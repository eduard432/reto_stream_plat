#include "Serie.h"
#include <iostream>
#include "Vector.h"
#include "Episodio.h"

Serie::Serie(const Vector<std::string>& datos) {
    // [0]: ID
    // [1]: Nombre
    // [2]: Duracion
    // [3]: Genero
    // [4]: Episodio
    // [5]: Temporada
    id = datos[0];
    nombre = datos[1];
    duracion = std::stoi(datos[2]); // Convertir de string a texto
    genero = datos[3];
}

void Serie::agregarEpisodio(Episodio episodio) {
    episodios.push_Back(episodio);
}

unsigned int Serie::getNumEpisodios() const {
    return episodios.length();
}

void Serie::mostrar() const {
    std::cout << id << " - " << nombre << " - Duación:";
    std::cout << duracion << " - Genero: " << genero;
    std::cout << " Calificación: " << calificacionPromedio << std::endl;
    std::cout << " Episodios: " << episodios.length() << std::endl;
}

void Serie::mostrarEpisodios() const {
    for (unsigned int i = 0; i < episodios.length(); i++) {
        Episodio episodio = episodios[i];
        episodio.mostrar();
    }
}