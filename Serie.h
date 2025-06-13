/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Definición de la clase Serie
Fecha de Creación/Modificación: 12/Junio/2025
*/
#include <iostream>
#include "Video.h"
#include "Vector.h" 
#include "Episodio.h"

#ifndef SERIE_H
#define SERIE_H

// Clase para definir elemento Serie, herencia de Video
class Serie: public Video {
    public:
        // Constructor de la serie a partir de un vector de datos
        Serie(const Vector<std::string>& datos);
        unsigned int getNumEpisodios() const;

        // Podemos usar dynamic_cast o este atributo para saber si
        // es una serie o pelicula
        bool esSerie() const override {
            return true;
        }

        // Método para mostrar atributos
        void mostrar() const override;
        // Método para mostrar todos los episodios de la serie
        void mostrarEpisodios() const;

        // Método para agregar episodio a la serie
        void agregarEpisodio(const Episodio& titulo);
    private:
        // Vector de todos los episodios de la serie:
        Vector<Episodio> episodios;
    
};
#endif