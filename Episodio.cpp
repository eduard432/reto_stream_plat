/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implemenetacíón de la clase Episodio
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include "Episodio.h"
#include "Vector.h"
#include <iostream>

Episodio::Episodio() {}

// Constructor de titulo, recibimos el vector con toda la información necesaria
Episodio::Episodio(const Vector<std::string>& datos) {
    // [0]: ID
    // [1]: Nombre
    // [2]: Duracion
    // [3]: Genero
    // [4]: Episodio
    // [5]: Temporada
    titulo = datos[4];
    temporada = datos[5];

    // Se válidan los datos de titulo
    if(datos[4].empty() || datos[5].empty()) {
        throw std::invalid_argument("Faltan datos - Episodio");
    }
}

// Método para mostrar titulo
void Episodio::mostrar() const {
    std::cout << "Episodio: " << titulo << " | Temporada: " << temporada << std::endl;
}