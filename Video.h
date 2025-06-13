/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Definición de la clase Video
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include <string>
#ifndef VIDEO_H
#define VIDEO_H

// Definimos una clase abastracta como base para las clases Pelicula y Serie:
class Video {
    public:
        // Constructor y destructor
        Video();
        virtual ~Video();

        // Podemos usar dynamic_cast o este atributo para saber si
        // es una serie o pelicula
        virtual bool esSerie() const = 0;

        // Getters:
        float getCalifProm() const;
        std::string getGenero() const;
        std::string getId() const;
        std::string getNombre() const;

        // Método virtual puro que se hereda:
        virtual void mostrar() const = 0;

        // Método para cambiar la calificaicón promedio:
        void calificar(float calif);
    protected:
        // Información del video:
        float calificacionPromedio;
        std::string genero;
        std::string id;
        std::string nombre;
        unsigned int duracion;
        // Variable útil para agregar calificaciones:
        unsigned int vecesCalif = 0;
};
#endif