/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/
#include "Video.h"
#include <iostream>
#include "Vector.h"

#ifndef SERIE_H
#define SERIE_H

class Serie: public Video {
public:
    Serie(const Vector<std::string>& datos);
};
#endif