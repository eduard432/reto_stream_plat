/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include "Streaming.h"
#include "Serie.h"
#include "Pelicula.h"

#include <iostream>

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); // Windows
    #elif __linux__
        system("clear"); // Linux
    #elif __APPLE__
        system("clear"); // macOS
    #endif
}

// 2. Opción del menú
void mostrarVideos (const Streaming &streaming) {
    limpiarPantalla();
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

        limpiarPantalla();

        float calif = 0;
        
        std::string genero;
        int decisionGenero = 0;

        
        switch (decision) {
            case 1:
                std::cout << "-----------------" << std::endl;
                std::cout << "Califación minima: ";
                std::cin >> calif;
                std::cout << "-----------------" << std::endl;

                if(calif <= 0) {
                    std::cout << "Calificación no válida" << endl;
                    break;
                } else if(calif > 5) {
                    std::cout << "La calificación tiene que ser de: de 0-5.0" << std::endl;
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
                std::cin >> decisionGenero;


                switch (decisionGenero) {
                    case 1:
                        genero = "Drama";
                        break;

                    case 2:
                        genero = "Accion";
                        break;
                    
                    case 3:
                        genero = "Misterio";
                        break;
                    
                    default:
                        std::cout << "Esta opción no existe" << std::endl;
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

// 3. Opción del menú
void mostrarEpisodios (const Streaming &streaming) {
    float calif = 0;
    std::cout << "Calificación mínima: ";
    std::cin >> calif;

    if(calif <= 0) {
        std::cout << "Calificación no válida" << std::endl;
        return;
    } else if(calif > 5) {
        std::cout << "La calificación tiene que ser de: de 0-5.0" << std::endl;
        return;
    }

    Serie* serie = (Serie*)streaming.buscarVideo(calif);
    if(serie) {
        serie->mostrar();
        serie->mostrarEpisodios();
    } else {
        std::cout << "No se encontro niguna serie." << std::endl;
        return;
    }
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
    std::cout << "Calificación otorgada: ";
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
    limpiarPantalla();
        std::cout << "Bienvenido a Netflix" << std::endl;
    Streaming sistema;

    int decision = -1;

    while(decision != 0) {
        std::cout << "-----------------" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "1. Cargar archivo de datos" << std::endl;
        std::cout << "2. Mostrar videos por calificación o género "<< std::endl;
        std::cout << "3. Mostrar los episodios de una serie con una calificacion determinada" << std ::endl;
        std::cout << "4. Mostrar películas con cierta calificación" << std ::endl;
        std::cout << "5. Calificar un video" << std ::endl;
        std::cout << "0. Salir" << std ::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "Opción: ";
        std::cin >> decision;

        std::string fileName;

        switch (decision) {
            case 1:
                limpiarPantalla();
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