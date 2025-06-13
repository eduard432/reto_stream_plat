/*
Autores: Carlos Marlon García Arráez - Juan Eduardo Barrón Cisneros
Descripcion: Implemenetacíón de la clase Pelicula
Fecha de Creación/Modificación: 12/Junio/2025
*/


#include <iostream>

#include "Vector.h"
#include "Pelicula.h"

using namespace std;

// Constructor de pelicula, recibimos un vector con toda la información necesaria
Pelicula::Pelicula(const Vector<std::string>& datos) {
    // Se encuentra en este orden:
    // [0]: ID
    // [1]: Nombre
    // [2]: Duracion
    // [3]: Genero

    // Se válidan los datos de pelicula
    if(datos[0].empty() || datos[1].empty() || std::stoi(datos[2]) <= 0 || datos[3].empty()) {
        throw std::invalid_argument("Faltan datos - Pelicula");
    }
    
    // Asignamos los datos a la instancia
    id = datos[0];
    nombre = datos[1];
    duracion = std::stoi(datos[2]); // Convertir de string a texto
    genero = datos[3];
}

// Método para mostrar pelicula (sobrecarga)
void Pelicula::mostrar() const {
    std::cout << id << " | " << nombre << " | Duacion:";
    std::cout << duracion << " | Genero: " << genero ;
    std::cout << " | Calificacion: " << calificacionPromedio << std::endl;
}