#include <iostream>
#include <fstream>
#include <sstream>
#include "Vector.h"

#include "Streaming.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

using namespace std;

Streaming::~Streaming() {
    for (unsigned int i = 0; i < tam_v; i++) {
        delete videos[i];
        videos[i] = nullptr;
    }
    if(videos) {
        delete[] videos;
        videos = nullptr;
    }
}

Streaming::Streaming() {
    reAlocar(2);
}

// Función para reasignar espacio de memoria cuando se acaba el actual
void Streaming::reAlocar(unsigned int nuevaCapacidad) {
    // Definimos el nuevo apuntador con la nueva capacidad
    Video** nuevosVideos = new Video*[nuevaCapacidad];

    // Validamos por si olvidamos incrementar el tam_v
    if(nuevaCapacidad < tam_v) {
        tam_v = nuevaCapacidad;
    }

    // Copiamos cada video en la nueva direccion de memoria
    for (unsigned int i = 0; i < tam_v; i++) {
        nuevosVideos[i] = videos[i];  // copiamos los punteros, no los objetos
    }

    if(videos) {
        // Solo liberamos el puntero previo, porque los punteros de cada instancia
        // Los copiamos al nuevo apuntador
        delete[] videos;
        videos = nullptr;
    }

    // Asignamos a la instancia actual
    videos = nuevosVideos;
    // Asignamos la nueva capacidad
    capacidad_v = nuevaCapacidad;
}

// Función para cargar videos desde un csv:
bool Streaming::cargarCsv(std::string fileName) {
    ifstream file(fileName);
    string line;

    // Válidaciones del archivo
    if(!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return false;
    }

    // Validamos y avanzamos una fila
    if(!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return false;
    }

    // Avisamos al usuario:
    cout << "Cargando archivo: " << fileName << endl;

    // Vamos recorriendo cada linea del archivo:
    while(getline(file, line)) {
        stringstream ss(line);
        string cell;

        // Control de erroes:
        int errores = 0;

        // Inicializamos nuestra propia implementaicón de Vector
        // Donde guardamos los datos de cada fila
        Vector<string> datos;

        // Vamos recorriendo cada celda de la fila:
        while(getline(ss, cell, ',')) {
            // Reportamos si existe algun error
            if(!cell.length()) 
                errores++;
            // Agregamos el valor de la celda al final
            datos.pushBack(cell);
        }

        // Verificamos cuantos datos tenemos
        // Para saber si es una Pelicula o un Episodio de una serie
        unsigned int longitud = datos.length();

        // Si tiene 4 datos es una pelicula
        // Si tiene 6 datos es un titulo de una serie
        if(longitud == 4) {
            // Creamos un puntero apuntando a una nueva instancia de pelicula
            Pelicula* pelicula = new Pelicula(datos);

            if(tam_v >= capacidad_v) {
                // Debemos aumentar la capacidad de nuestro arreglo dinámico interno
                reAlocar(capacidad_v + capacidad_v / 2);
            }
            // Agregamos a la instancia la nueva pelicula
            videos[tam_v] = pelicula;
            tam_v++;
        } else if(longitud == 6) {

            // Buscamos si ya existe una serie con ese id
            // datos[0] = id
            Serie* serie = (Serie*)buscarVideo(datos[0]);

            // Creamos una nueva instancia del titulo a guardar
            Episodio titulo(datos);

            // Si no encontramos una serie, creamos una y la agregamos al arreglo
            if(!serie) {
                serie = new Serie(datos);
                // Agregamos el puntero de esta nueva serie al arreglo
                // De punteros en la instancia de Streaming.
                if(tam_v >= capacidad_v) {
                    // Debemos aumentar la capacidad de nuestro arreglo
                    reAlocar(capacidad_v + capacidad_v / 2);
                }
                videos[tam_v] = serie;
                tam_v++;
            }

            // A la previa serie o a la nueva, le agregamos este nuevo titulo:
            serie->agregarEpisodio(titulo);
            
        } else {
            // Aumentamos el indice si hay algun error
            errores++;
        }

        // Reportamos errores
        if(errores) {
            cerr << "Error en la linea: " << line << endl;

            // Cerramos el archivo
            file.close();
            return false;
        }
    }

    // Cerramos el archivo
    file.close();
    return true;
}

// Getter de tamaño:
unsigned int Streaming::getTam() const {
    return tam_v;
}

// Función para mostrar todos los videos sin filtro:
void Streaming::mostrarVideos() const {
    // Recorremos el arreglo de videos:
    for (unsigned int i = 0; i < tam_v; i++) {
        videos[i]->mostrar();
    }
}

// Función para mostrar todos los videos con calificación mayor a calif
void Streaming::mostrarVideos(float calif) const {
    unsigned int found = 0;
    // Recorremos todos los videos almacenados:
    for (unsigned int i = 0; i < tam_v; i++) {
        float califProm = videos[i]->getCalifProm();
        if(califProm >= calif) {
            videos[i]->mostrar();
            found++;
        }
    }

    // Validamos si se encontro algun video
    if(found == 0)
        std::cout << "Ningún video encontrado" << std::endl;
}

// Función para mostrar todos los videos con calificación mayor a calif y si es serie o no
void Streaming::mostrarVideos(float calif, bool esSerie) const {
    unsigned int found = 0;
    // Recorremos todos los videos almacenados:
    for (unsigned int i = 0; i < tam_v; i++) {
        float califProm = videos[i]->getCalifProm();
        if(califProm >= calif && videos[i]->esSerie() == esSerie) {
            videos[i]->mostrar();
            found++;
        }
    }
    // Validamos si se encontro algun video
    if(found == 0) {
        std::cout << "Ninguna " << (esSerie ? "Serie" : "Pelicula") << " encontrada" << std::endl;
    }
}

// Función para buscar video a partir del género:
void Streaming::mostrarVideosPorGenero(std::string genero) const {
    unsigned int found = 0;
    // Recorremos todos los videos almacenados:
    for (unsigned int i = 0; i < tam_v; i++) {
        // Obtenemos su genero:
        std::string v_genero = videos[i]->getGenero();
        if(v_genero == genero) {
            videos[i]->mostrar();
            found++;
        }
    }

    // Validamos si se encontro algun video
    if(found == 0)
        std::cout << "Ningún video encontrado" << std::endl;
}


// Función para buscar video a partir del nombre o el id del video:
Video* Streaming::buscarVideo(std::string nombreId) const {
    // Recorremos todos los videos almacenados:
    for (unsigned int i = 0; i < tam_v; i++) {
        // Obtenemos sus id y nombre
        std::string v_nombre = videos[i]->getNombre();
        std::string v_id = videos[i]->getId();

        // Verificamos is coinciden
        if(v_nombre == nombreId || v_id == nombreId) {
            // Regresamos lo encontrado:
            return videos[i];
        }
    }
    return nullptr;
}

// Función para buscar video a partir de la calificación y si es serie o no
Video* Streaming::buscarVideo(float calif, bool esSerie) const {
    for (unsigned int i = 0; i < tam_v; i++) {
        float v_calif = videos[i]->getCalifProm();
        bool v_esSerie = videos[i]->esSerie();

        // Verificamos is coinciden
        if(v_calif >= calif && esSerie == v_esSerie) {
             // Regresamos lo encontrado:
            return videos[i];
        }
    }

    return nullptr;
}