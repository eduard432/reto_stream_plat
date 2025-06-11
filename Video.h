/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include <string>
#ifndef VIDEO_H
#define VIDEO_H

// TODO: No lo estamos usando:
enum Genero {
    drama,
    accion,
    misterio
};

class Video {
protected:
    std::string id;
    std::string nombre;
    unsigned int duracion;
    std::string genero;
    float calificacionPromedio;

public:
    Video();
    virtual ~Video();
    virtual void mostrar() const;
    // void setId(std::string newId);
    // void setNombre(std::string newNombre);
    // void setDuracion(unsigned int newDuracion);
    // void setGenero(Genero newGenero);
    // void setCalificacionPromedio(float newCalificacionPromedio);

};
#endif