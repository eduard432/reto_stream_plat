/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include "Streaming.h"
#include "Serie.h"
#include "Pelicula.h"

#include <iostream>

void mostrarVideos (const Streaming &streaming) {
    int decision = -1;

    while(decision != 0) {
        std::cout << "-----------------" << std::endl;
        std::cout << "Filtrar por:" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "1. Filtrar por calificacion" << std::endl;
        std::cout << "2. Filtrar por género" << std::endl;
        std::cout << "0. Regresar" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "Opción: ";
        std::cin >> decision;

        float calif = 0;
        std::string genero;
        
        switch (decision) {
            case 1:
                std::cout << "-----------------" << std::endl;
                std::cout << "Califación minima: " << std::endl;
                std::cin >> calif;
                std::cout << "-----------------" << std::endl;

                if(calif <= 0) {
                    std::cout << "Calificación no válida" << endl;
                    break;
                }

                streaming.mostrarVideos(calif);
            break;

            case 2:
                std::cout << "-----------------" << std::endl;
                std::cout << "Genero: " << std::endl;
                std::cout << "1. Drama" << std::endl;
                std::cout << "2. Accion" << std::endl;
                std::cout << "3. Misterio" << std::endl;
                std::cout << "-----------------" << std::endl;
                std::cout << "Opción: ";
                std::cin >> genero;

                if(genero == "accion" || genero == "drama" || genero == "misterio" ) {
                    std::cout << "Genero no válido" << std::endl;
                    break;
                }

                streaming.mostrarVideosPorGenero(genero);
            break;
        
            default:
                std::cout << "Opción no válida" << std::endl;
            break;
        }
    }
}

void mostrarEpisodios (const Streaming &streaming) {
    std::string nombreId;
    float calif = 0;
    std::cout << "Ingrese el id, o nombre de la serie: " << std::endl;
    std::cin >> nombreId;
    std::cout << "Calificación mínima: " << std::endl;
    std::cin >> calif;

    if(calif <= 0) {
        std::cout << "Calificación no válida" << std::endl;
        return;
    }

    Serie* serie = (Serie*)streaming.buscarVideo(nombreId, calif);
    serie->mostrarEpisodios();
}

void mostrarPeliculas (const Streaming &streaming) {

    float calif = 0;

    std::cout << "-----------------" << std::endl;
    std::cout << "Califación minima: " << std::endl;
    std::cin >> calif;
    std::cout << "-----------------" << std::endl;

    if(calif <= 0) {
        std::cout << "Calificación no válida" << endl;
        return;
    }

    streaming.mostrarVideos(calif, false);
}

void calificarVideo (const Streaming &streaming) {

    float calif = 0;
    std::string nombreId;

    std::cout << "Ingrese el id, o nombre de la serie: " << std::endl;
    std::cin >> nombreId;
    std::cout << "Calificación dada: " << std::endl;
    std::cin >> calif;

    if(calif <= 0) {
        std::cout << "Calificación no válida" << endl;
        return;
    }

    Video* video = streaming.buscarVideo(nombreId);
    video->calificar(calif);

    std::cout << "Video calificado con éxito" << std::endl;

}

int main() {
    Streaming sistema;

    int decision = -1;

    while(decision != 0) {
        std::cout << "Bienvenido a Netflix" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "1. Cargar archivo de datos" << std::endl;
        std::cout << "2. Mostrar videos por calificación o género "<< std::endl;
        std::cout << "3. Mostrar series con cierta calificación" << std ::endl;
        std::cout << "4. Mostrar películas con cierta calificación" << std ::endl;
        std::cout << "5. Calificar un video" << std ::endl;
        std::cout << "0. Salir" << std ::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "Opción: ";
        std::cin >> decision;

        std::string fileName;

        switch (decision) {
            case 1:
                std::cout << "-----------------" << std::endl;
                std::cout << "Introduce la ruta del archivo a cargar: ";
                // std::cin >> fileName;

                fileName = "./series.csv";

                if(!sistema.cargarCsv(fileName)) {
                    std::cout << "Opps hubo un error" << endl;
                } else {
                    std::cout << "Archivo: " << fileName << " cargado con éxito" << endl;
                }
                
            break;
                
            case 2:
                mostrarVideos(sistema);
            break;

            case 3:
                mostrarEpisodios(sistema);
            break;

            case 4:
                mostrarPeliculas(sistema);
            break;

            case 5:
                calificarVideo(sistema);
            break;
        
            default:
                std::cout << "Opción no válida" << std::endl;
            break;
        }
    }


    return 0;
}