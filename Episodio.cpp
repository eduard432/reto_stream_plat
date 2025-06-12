#include "Episodio.h"
#include "Vector.h"
#include <iostream>

Episodio::Episodio() {}

Episodio::Episodio(const Vector<std::string>& datos) {
    // [0]: ID
    // [1]: Nombre
    // [2]: Duracion
    // [3]: Genero
    // [4]: Episodio
    // [5]: Temporada
    episodio = datos[4];
    temporada = datos[5];
}

void Episodio::mostrar() const {
    std::cout << "Episodio: " << episodio << " | Temporada: " << temporada << std::endl;
}