#include "Vector.h"
#include "Pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula(const Vector<std::string>& datos) {
    // [0]: ID
    // [1]: Nombre
    // [2]: Duracion
    // [3]: Genero
    id = datos[0];
    nombre = datos[1];
    duracion = std::stoi(datos[2]); // Convertir de string a texto
    genero = datos[3];
}

void Pelicula::mostrar() const {
    std::cout << id << " - " << nombre << " - Duación:";
    std::cout << duracion << " - Genero: " << genero ;
    std::cout << " Calificación: " << calificacionPromedio << std::endl;
}