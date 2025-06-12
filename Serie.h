/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/
#include <iostream>
#include "Video.h"
#include "Vector.h"
#include "Episodio.h"

#ifndef SERIE_H
#define SERIE_H

class Serie: public Video {
    private:
        Vector<Episodio> episodios;
    public:
        bool esSerie() const override {
            return true;
        }
        void mostrar() const override;
        void agregarEpisodio(Episodio episodio);
        void mostrarEpisodios() const;
        Serie(const Vector<std::string>& datos);
        unsigned int getNumEpisodios() const;
};
#endif