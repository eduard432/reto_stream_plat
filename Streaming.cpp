#include <iostream>
#include <fstream>
#include <sstream>
#include "Vector.h"

#include "Streaming.h"
#include "Pelicula.h"
#include "Serie.h"

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
            std::cout << "NUeva pelicula" << std::endl;
            Pelicula* pelicula = new Pelicula(datos);

            std::cout << "Punter pelicula: " << pelicula << std::endl;
            if(tam_v >= capacidad_v) {
                // Debemos aumentar la capacidad de nuestro arreglo
                reAlocar(capacidad_v + capacidad_v / 2);
            }
            videos[tam_v] = pelicula;
            tam_v++;
        } else if(longitud == 7) {
            Serie* serie = new Serie(datos);
            if(tam_v >= capacidad_v) {
                // Debemos aumentar la capacidad de nuestro arreglo
                reAlocar(capacidad_v + capacidad_v / 2);
            }
            videos[tam_v] = serie;
            tam_v++;
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
    std::cout << "Motrando peliculas: " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Numero de Videos: " << tam_v << endl;

    for (unsigned int i = 0; i < tam_v; i++) {
        videos[i]->mostrar();
    }
}