#include "Video.h"

#include <iostream>
#include <fstream>

// definimos los constructores:
Video::Video() {}
Video::~Video() {}

void Video::mostrar() const {}


// Definimos los getters de la clase video:
std::string Video::getId() const {
    return id;
}

float Video::getCalifProm() const {
    return calificacionPromedio;
}

std::string Video::getGenero() const {
    return genero;
}

std::string Video::getNombre() const {
    return nombre;
}

// Función para definir calificación promedio
// Se toma la calificación aanterior y el numero de veces que se ha calificado el video
// para usar la siguiente formula y promediar con la nueva calif
void Video::calificar(float calif) {
    calificacionPromedio = (calificacionPromedio * numCalifs + calif) / (numCalifs + 1);
    numCalifs++;
}