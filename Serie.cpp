#include "Serie.h"
#include <iostream>
#include "Vector.h"
#include "Episodio.h"

// Constructor de Serie, recibimos un vector con toda la información necesaria
Serie::Serie(const Vector<std::string>& datos) {
    // [0]: ID
    // [1]: Nombre
    // [2]: Duracion
    // [3]: Genero
    // [4]: Episodio
    // [5]: Temporada
    if(datos[0].empty() || datos[1].empty() || std::stoi(datos[2]) <= 0 || datos[3].empty()) {
        throw std::invalid_argument("Faltan datos - Serie");
    }

    // Asignamos los datos a la instancia
    id = datos[0];
    nombre = datos[1];
    duracion = std::stoi(datos[2]); // Convertir de string a texto
    genero = datos[3];
}

// Método para agregar episodios a la serie
void Serie::agregarEpisodio(const Episodio& titulo) {
    episodios.pushBack(titulo);
}

// Getter para obtener numero de episodios
unsigned int Serie::getNumEpisodios() const {
    return episodios.length();
}

// Método para mostrar la serie (sobrecarga)
void Serie::mostrar() const {
    std::cout << id << " | " << nombre << " | Duación:";
    std::cout << duracion << " | Genero: " << genero;
    std::cout << " | Calificación: " << calificacionPromedio;
    std::cout << " | Episodios: " << episodios.length() << std::endl;
}

// Método para mostrar episodios
void Serie::mostrarEpisodios() const {
    unsigned int found = 0;
    for (unsigned int i = 0; i < episodios.length(); i++) {
        Episodio titulo = episodios[i];
        titulo.mostrar();
        found++;
    }
    if(found == 0) {
        std::cout << "Ningún episodio encontrado" << std::endl;
    }
}