/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Punto de entrada del programa
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include "Streaming.h"
#include "Serie.h"
#include "Pelicula.h"

#include <iostream>

// Limpia la consola en todos los os.
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); // Windows
    #elif __linux__
        system("clear"); // Linux
    #elif __APPLE__
        system("clear"); // macOS
    #endif
}

// Imprime un separador, para mantener un contexto claro.
void sPrint() {
    std::cout << "—————————————————————————————————————————————————————————————————" << std::endl;
}

// 1. Cargar Archivos
// Función para obtener la ruta del archivo
// Válida que el archivo se cargue correctamente
// Le pasamos sistema para que pueda guardar los datos en esa instancia
void cargarArchivo(Streaming &sistema) {
    std::string fileName;
    sPrint(); // Separador
    std::cout << "Introduce la ruta del archivo a cargar: ";
    // std::cin >> fileName;

    fileName = "./series.csv";

    // Reportamos si no pudimos cargar el archivo:
    if(!sistema.cargarCsv(fileName)) {
        std::cout << "Opps hubo un error" << endl;
    } else {
        std::cout << "Archivo: " << fileName << " cargado con éxito" << endl;
    }
}

// 2. Mostrar todos los videos con una cierta calificación:
void mostrarVideos(const Streaming &streaming) {
    int decision = -1;

    // Desplegamos menu para selecionar tipo de filtro:
    while(decision != 0) {
        
        sPrint();
        std::cout << "Filtrar por:" << std::endl;
        sPrint();
        std::cout << "1. Filtrar por calificacion" << std::endl;
        std::cout << "2. Filtrar por género" << std::endl;
        std::cout << "0. Regresar" << std::endl;
        sPrint();
        std::cout << "Filtro: ";
        // Registramos el filtro
        std::cin >> decision;

        // Creamos una variable para el genero y la calificacion
        float calif = 0;
        std::string genero;
        int decisionGenero = 0;

        
        switch (decision) {
            // Si elige filtrar por calificación:
            case 1:
                limpiarPantalla();
                sPrint();
                std::cout << "Califación minima: ";
                std::cin >> calif;
                sPrint();

                // Válidamos la calificación:
                if(calif <= 0) {
                    std::cout << "Calificación no válida" << endl;
                    break;
                } else if(calif > 5) {
                    std::cout << "La calificación tiene que ser de: de 0-5.0" << std::endl;
                    break;
                }

                // Mostrar los resultados:
                streaming.mostrarVideos(calif);
            break;
            // Si elige filtrar por genero
            case 2:
                limpiarPantalla();
                sPrint();
                std::cout << "Genero: " << std::endl;
                sPrint();
                std::cout << "1. Drama" << std::endl;
                std::cout << "2. Accion" << std::endl;
                std::cout << "3. Misterio" << std::endl;
                sPrint();
                std::cout << "Opción: ";
                std::cin >> decisionGenero;
                sPrint();

                // Válidamos la calificación:
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

                // Mostramos los resultados
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
    // Solicitamos calificación al usuario:
    float calif = 0;
    sPrint();
    std::cout << "Calificación mínima: ";
    std::cin >> calif;
    sPrint();

    // Vpalidamos la calificación:
    if(calif <= 0 || calif > 5) {
        std::cout << "La calificación tiene que ser de: de 0-5.0" << std::endl;
        return;
    }

    Serie* serie = (Serie*)streaming.buscarVideo(calif, true);

    // Verificamos si se encontro alguna serie:
    if(serie) {
        // Mostramos los resultados:
        serie->mostrar();
        sPrint();
        serie->mostrarEpisodios();
    } else {
        std::cout << "No se encontro niguna serie." << std::endl;
        return;
    }
}

// 4. Opción del menu
void mostrarPeliculas (const Streaming &streaming) {
    // Solicitamos calificación al usuario:
    float calif = 0;
    sPrint();
    std::cout << "Califación minima: ";
    std::cin >> calif;
    sPrint();

    // Válidamos calificación:
    if(calif <= 0 || calif > 5) {
        std::cout << "La calificación tiene que ser de: de 0-5.0" << std::endl;
        return;
    }

    // Mostramos el resultado:
    streaming.mostrarVideos(calif, false);
}

// 5. Opción del menu
void calificarVideo (const Streaming &streaming) {

    sPrint();
    // Mostramos los videos en el sistema:
    streaming.mostrarVideos();
    sPrint();

    // Solicitamos calificación y id o nobmre al usuario:
    float calif = 0;
    std::string nombreId;
    std::cout << "Ingrese el id, o nombre de la serie: ";
    std::cin >> nombreId;

    // Válidamos el nombre o id
    if(nombreId.empty()) {
        std::cout << "Titulo no válido" << std::endl;
        return;
    }

    sPrint();
    std::cout << "Calificación otorgada: ";
    std::cin >> calif;

    // Válidamos la calificación
    if(calif <= 0 || calif > 5) {
        std::cout << "La calificación tiene que ser de: de 0-5.0" << std::endl;
        return;
    }
    sPrint();

    // Buscamos el video por nombre o id
    Video* video = streaming.buscarVideo(nombreId);

    if(!video) {
        std::cout << "No se eonctro el video a calificar:" << std::endl;
        return;
    }

    // Método para calificar:
    video->calificar(calif);

    std::cout << "Video calificado con éxito" << std::endl;

}

// Código de entrada del programa:
int main() {
    limpiarPantalla();
    sPrint();
    std::cout << "Sistema Gestor de Videos" << std::endl;
    sPrint();

    // Sistema gestor de los dato:
    Streaming sistema;

    int decision = -1;

    // Se desplega menu con las respectivas decisiones
    while(decision != 0) {
        sPrint();
        std::cout << "Menu:" << std::endl;
        sPrint();
        std::cout << "1. Cargar archivo de datos" << std::endl;
        std::cout << "2. Mostrar videos por calificación o género "<< std::endl;
        std::cout << "3. Mostrar los episodios de una serie con una calificacion determinada" << std ::endl;
        std::cout << "4. Mostrar películas con cierta calificación" << std ::endl;
        std::cout << "5. Calificar un video" << std ::endl;
        std::cout << "0. Salir" << std ::endl;
        sPrint();
        std::cout << "Opción: ";
        std::cin >> decision;

        std::string fileName;

        // Limpiamos la pantalla antes de:
        // Ejecutar la función correspondiente a cada funcionalidad
        switch (decision) {
            case 1:
                limpiarPantalla();
                cargarArchivo(sistema);
            break;
                
            case 2:
                limpiarPantalla();
                mostrarVideos(sistema);
            break;

            case 3:
                limpiarPantalla();
                mostrarEpisodios(sistema);
            break;

            case 4:
                limpiarPantalla();
                mostrarPeliculas(sistema);
            break;

            case 5:
                limpiarPantalla();
                calificarVideo(sistema);
            break;
        
            default:
                std::cout << "Opción no válida" << std::endl;
            break;
        }
    }


    return 0;
}