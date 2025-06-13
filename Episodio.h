/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Definición de la clase Episodio
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include <iostream>
#include "Vector.h"

#ifndef EPISODIO_H
#define EPISODIO_H

// Clase para definir los elementos episodios de una serie
class Episodio {
    public:
        // Constructores:
        Episodio();
        Episodio(const Vector<std::string>& datos);

        // Método para mostrar atributos
        void mostrar() const;
    private:
        // 
        std::string titulo;
        std::string temporada;
};



#endif