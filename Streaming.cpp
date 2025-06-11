#include "Streaming.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Streaming::Streaming() {
    reAlocar();
}

void Streaming::cargarDatos() {
    std::cout << "-----------------" << std::endl;
    std::cout << "Introduce la ruta del archivo a cargar: ";
    std::string fileName;
    std::cin >> fileName;
    bool resultado = cargarCsv(fileName);
}

// Este método igual lo puedes utilizar para validar cuantos datos hay
// en el CSV que estarás utilizando.
// Piensa en cual clase debería ir.
// Regresa "-1" si hay un error al leer el archivo o regresa
// de 0 a la cantidad de datos en el csv.
int countDataLinesInCSV(string fileName) {
    ifstream    file(fileName);
    int         lineCount = 0;
    string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        cerr << "El archivo no tiene header" << endl;
        file.close();
        return -1;
    }

    // Contar lineas 
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}