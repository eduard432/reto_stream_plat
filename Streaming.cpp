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

void Streaming::reAlocar(unsigned int nuevaCapacidad) {
    Video** nuevosVideos = new Video*[nuevaCapacidad];

    if(nuevaCapacidad < tam_v) {
        tam_v = nuevaCapacidad;
    }

    for (unsigned int i = 0; i < tam_v; i++) {
        nuevosVideos[i] = videos[i];  // copiamos los punteros, no los objetos
    }

    if(videos) {
        delete[] videos;  // NO hacemos delete de los videos individuales aquí
        videos = nullptr;
    }

    videos = nuevosVideos;
    capacidad_v = nuevaCapacidad;
}


bool Streaming::cargarCsv(std::string fileName) {
    ifstream file(fileName);
    string line;

    if(!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return false;
    }

    if(!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return false;
    }

    cout << "Cargando archivo: " << fileName << endl;

    while(getline(file, line)) {
        stringstream ss(line);
        string cell;
        int errores = 0;
        Vector<string> datos;

        while(getline(ss, cell, ',')) {
            if(!cell.length()) 
                errores++;
            datos.push_Back(cell);
        }

        unsigned int longitud = datos.length();

        if(longitud == 4) {
            Pelicula* pelicula = new Pelicula(datos);

            if(tam_v >= capacidad_v) {
                // Debemos aumentar la capacidad de nuestro arreglo
                reAlocar(capacidad_v + capacidad_v / 2);
            }
            videos[tam_v] = pelicula;
            tam_v++;
        } else if(longitud == 6) {

            // Buscamos si ya existe una serie con ese id
            // datos[0] = id
            Serie* serie = (Serie*)buscarVideoPorId(datos[0]);
            Episodio episodio(datos);

            if(!serie) {
                serie = new Serie(datos);
                // Agregamos el puntero de esta neuva serie al arreglo
                // De punteros en la instancia de Streaming.
                if(tam_v >= capacidad_v) {
                    // Debemos aumentar la capacidad de nuestro arreglo
                    reAlocar(capacidad_v + capacidad_v / 2);
                }
                videos[tam_v] = serie;
                tam_v++;
            }
            serie->agregarEpisodio(episodio);
            
        } else {
            errores++;
        }

        if(errores) {
            cerr << "Error en la linea: " << line << endl;
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}

Video* Streaming::operator[](unsigned int index) const {
    return videos[index];
}

unsigned int Streaming::contarVideos() const {
    return tam_v;
}

void Streaming::mostrarVideos() const {
    std::cout << "-----------------" << std::endl;
    std::cout << "Motrando videos: " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Numero de Videos: " << tam_v << endl;

    for (unsigned int i = 0; i < tam_v; i++) {
        videos[i]->mostrar();
    }
}

void Streaming::mostrarVideos(std::string id) const {
    for (unsigned int i = 0; i < tam_v; i++) {
        std::string video_id = videos[i]->getId();
        if(video_id == id) {
            videos[i]->mostrar();
        }
    }
}

void Streaming::mostrarVideos(float calif) const {
    for (unsigned int i = 0; i < tam_v; i++) {
        float califProm = videos[i]->getCalifProm();
        if(califProm >= calif) {
            videos[i]->mostrar();
        }
    }
}

void Streaming::mostrarVideos(float calif, bool esSerie) const {
    for (unsigned int i = 0; i < tam_v; i++) {
        float califProm = videos[i]->getCalifProm();
        if(califProm >= calif && videos[i]->esSerie() == esSerie) {
            videos[i]->mostrar();
        }
    }
}

void Streaming::mostrarVideosPorGenero(std::string genero) const {
    for (unsigned int i = 0; i < tam_v; i++) {
        std::string v_genero = videos[i]->getGenero();
        if(v_genero == genero) {
            videos[i]->mostrar();
        }
    }
}

Video* Streaming::buscarVideoPorId(std::string id) const {
    for (unsigned int i = 0; i < tam_v; i++) {
        std::string video_id = videos[i]->getId();

        if(video_id == id) {
            return videos[i];
        }
    }

    return nullptr;
}

Video* Streaming::buscarVideo(std::string nombre, float calif) const {
    for (unsigned int i = 0; i < tam_v; i++) {
        std::string v_nombre = videos[i]->getNombre();
        float v_calif = videos[i]->getCalifProm();

        if(v_calif == calif || v_nombre == nombre) {
            return videos[i];
        }
    }

    return nullptr;
}

Video* Streaming::buscarVideo(std::string nombreId) const {
    for (unsigned int i = 0; i < tam_v; i++) {
        std::string v_nombre = videos[i]->getNombre();
        std::string v_id = videos[i]->getId();

        if(v_nombre == nombreId || v_id == nombreId) {
            return videos[i];
        }
    }

    return nullptr;
}