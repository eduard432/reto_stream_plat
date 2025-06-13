/*
Autores: Carlos Marlon García Arráez - Juan Eduardo Barrón Cisneros
Descripcion: Definición de la clase Pelicula
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include "Video.h"

#ifndef PELICULA_H
#define PELICULA_H

// Clase para definir elemento Pelicula, herencia de Pelicula
class Pelicula: public Video { 
public:
    // Constructor de la pelicula a partir de un vector de datos
    Pelicula(const Vector<std::string>& datos);

    // Podemos usar dynamic_cast o este atributo para saber si
    // es una serie o pelicula
    bool esSerie() const override {
        return false;
    }
    // Método para mostrar atributos de la pelicula
    void mostrar() const override;
    
};
#endif