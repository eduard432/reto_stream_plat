#include "Episodio.h"
#include "Vector.h"
#include <iostream>

Episodio::Episodio() {}

// Constructor de episodio, recibimos el vector con toda la información necesaria
Episodio::Episodio(const Vector<std::string>& datos) {
    // [0]: ID
    // [1]: Nombre
    // [2]: Duracion
    // [3]: Genero
    // [4]: Episodio
    // [5]: Temporada
    episodio = datos[4];
    temporada = datos[5];

    // Se válidan los datos de episodio
    if(datos[4].empty() || datos[5].empty()) {
        throw std::invalid_argument("Faltan datos - Episodio");
    }
}

// Método para mostrar episodio
void Episodio::mostrar() const {
    std::cout << "Episodio: " << episodio << " | Temporada: " << temporada << std::endl;
}