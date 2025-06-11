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

    cout << "Cargand archivo: " << fileName << endl;

    while(getline(file, line)) {
        stringstream ss(line);
        string cell;
        int errores = 0;
        Vector<string> datos;

        while(getline(ss, cell, ',')) {
            datos.push_Back(cell);
        }

        if(datos.length() < 4) {
            Pelicula* pelicula = new Pelicula(datos);
            if(tam_v >= capacidad_v) {
                // Podemos aumentar la capacidad 
                reAlocar(capacidad_v + capacidad_v / 2);
            }
            videos[tam_v] = pelicula;
        } else {
            Serie* serie = new Serie(datos);
            if(tam_v >= capacidad_v) {
                // Podemos aumentar la capacidad 
                reAlocar(capacidad_v + capacidad_v / 2);
            }
            videos[tam_v] = serie;
        }
    }
}

// Este método igual lo puedes utilizar para validar cuantos datos hay
// en el CSV que estarás utilizando.
// Piensa en cual clase debería ir.
// Regresa "-1" si hay un error al leer el archivo o regresa
// de 0 a la cantidad de datos en el csv.
int countDataLinesInCSV(string fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return -1;
    }

    // Contar lineas 
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}