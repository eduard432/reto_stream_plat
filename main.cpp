/*
Autores: Carlos Marlon García Arráez Juan Eduardo Barrón Cisneros
Descripcion: Implementación de la clase ArregloComplejos
Fecha de Creación/Modificación: 12/Junio/2025
*/

#include "Streaming.h"

#include <iostream>

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
                std::cin >> fileName;
                sistema.cargarCsv(fileName);
            break;
        
            default:
                std::cout << "Opción no válida" << std::endl;
            break;
        }
    }


    return 0;
}