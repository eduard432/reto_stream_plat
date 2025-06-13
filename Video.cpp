/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implemenetacíón de la clase Video
Fecha de Creación/Modificación: 12/Junio/2025
*/


#include <iostream>
#include <fstream>

#include "Video.h"

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
    calificacionPromedio = (calificacionPromedio * vecesCalif + calif) / (vecesCalif + 1);
    vecesCalif++;
}