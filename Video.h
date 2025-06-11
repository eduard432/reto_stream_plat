/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include <string>
#ifndef VIDEO_H
#define VIDEO_H

enum Genero {
    drama,
    accion,
    misterio
};

class Video {
private:
    std::string id;
    std::string nombre;
    unsigned int duracion;
    Genero genero;
    float calificacionPromedio;

public:
    Video();
    void setId(std::string newId);
    void setNombre(std::string newNombre);
    void setDuracion(unsigned int newDuracion);
    void setGenero(Genero newGenero);
    void setCalificacionPromedio(float newCalificacionPromedio);


    

};
#endif