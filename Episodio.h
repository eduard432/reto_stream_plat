/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include <iostream>
#include "Vector.h"

#ifndef EPISODIO_H
#define EPISODIO_H

class Episodio {
    private:
        std::string episodio;
        std::string temporada;
    public:
        Episodio();
        Episodio(const Vector<std::string>& datos);
};



#endif