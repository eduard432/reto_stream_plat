/*
Autores: Carlos Marlon García Arráez - Juan Eduardo Barrón Cisneros
Descripcion: Definición de la clase Streaming
Fecha de Creación/Modificación: 12/Junio/2025
*/
#include <iostream>
#include "Video.h"

using namespace std;

#ifndef STREAMING_H
#define STREAMING_H


// Clase que administra el sistema de series y peliculas
// encargado de filtrar, calificar y mostrar los elementos pelicula, series y episodios
class Streaming {
    public:
        // Constructor y destructor:
        Streaming();
        ~Streaming();
        
        // Getter para obtener la cantidad de videos
        unsigned int getTam() const;

        // Método para cargar archivo de datos:
        bool cargarCsv(std::string fileName);

        // Métodos para mostrar videos con distintos filtros (con sobrecarga)
        void mostrarVideos() const;
        void mostrarVideos(float calif) const;
        void mostrarVideos(float calif, bool esSerie) const;
        void mostrarVideosPorGenero(std::string genero) const;

        // Métodos para buscar videos:
        Video* buscarVideo(std::string nombreId) const;
        Video* buscarVideo(float calif, bool esSerie) const;

        
    private:
        // Puntero a lista de arreglo de punteros
        Video** videos = nullptr;

        // Definimos las dos variables para llevar el control de cuantos videos tenemos:
        unsigned int capacidad_v = 0;
        unsigned int tam_v = 0;

        // Método para realocar en memoria cuando ya no tengamos espacio en el arreglo
        void reAlocar(unsigned int nuevaCapacidad);

    
};

#endif


