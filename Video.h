/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include <string>
#ifndef VIDEO_H
#define VIDEO_H

class Video {
protected:
    std::string id;
    std::string nombre;
    unsigned int duracion;
    std::string genero;
    float calificacionPromedio;
    unsigned int numCalifs = 0;

public:
    Video();
    virtual ~Video();
    virtual void mostrar() const = 0;
    virtual bool esSerie() const = 0;
    std::string getId() const;
    float getCalifProm() const;
    std::string getGenero() const;
    std::string getNombre() const;
    void calificar(float calif);
    // void setId(std::string newId);
    // void setNombre(std::string newNombre);
    // void setDuracion(unsigned int newDuracion);
    // void setGenero(Genero newGenero);
    // void setCalificacionPromedio(float newCalificacionPromedio);

};
#endif