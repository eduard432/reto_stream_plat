#include "Video.h"

#include <iostream>
#include <fstream>


Video::Video() {}
Video::~Video() {}

void Video::mostrar() const {}

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

void Video::calificar(float calif) {
    calificacionPromedio = (calificacionPromedio * numCalifs + calif) / (numCalifs + 1);
    numCalifs++;
}