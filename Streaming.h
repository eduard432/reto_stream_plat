#include <iostream>
#include "Video.h"

using namespace std;

#ifndef STREAMING_H
#define STREAMING_H

class Streaming {
    private:
        Video** videos = nullptr;

        // Definimos las dos variables para llevar el control de cuantos videos tenemos:
        unsigned int capacidad_v = 0;
        unsigned int tam_v = 0;
        void reAlocar(unsigned int nuevaCapacidad);

    public:
        Streaming();
        ~Streaming();
        bool cargarCsv(std::string fileName);
        void mostrarVideos() const;
        void mostrarVideos(std::string id) const;
        void mostrarVideos(float calif) const;
        void mostrarVideos(float calif, bool esSerie) const;
        void mostrarVideosPorGenero(std::string genero) const;
        Video* buscarVideoPorId(std::string id) const;
        Video* buscarVideo(std::string nombre, float calif) const;
        Video* buscarVideo(std::string nombreId) const;
        Video* buscarVideo(float calif) const;
        // Video getVideo(unsigned int index);
        Video* operator[](unsigned int index) const;
        // Streaming[i] = Pelicula(...)
        unsigned int contarVideos() const;
};

#endif


