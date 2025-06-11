#include <iostream>
#include "Video.h"

using namespace std;

#ifndef STREAMING_H
#define STREAMING_H

class Streaming {
    private:
        Video* videos = nullptr;

        // Definimos las dos variables para llevar el control de cuantos videos tenemos:
        unsigned int capacidad_v = 0;
        unsigned int tam_v = 0;
        int contarLineasCsv(std::string filenName);
        bool cargarCsv(std::string fileName);
    public:
        Streaming();
        void reAlojar(unsigned int nuevaCapacidad);
        void agregarVideo(Video video);
        Video getVideo(unsigned int index);
        // TODO: sobrecargar operador para setear video
        void setVideo(unsigned int index);
        const Video& operator[](unsigned int index) const;
        // Streaming[i] = Pelicula(Los incr)
        unsigned int contarVideos() const;
        void cargarDatos();
};

#endif


