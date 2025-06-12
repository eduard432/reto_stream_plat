#ifndef VECTOR_H
#define VECTOR_H

// Implementación de arreglo dinámico
// Usamos template para que el vector pueda ser de cualquier tipo de dato
// Por lo mismo implementamos todo el código en el .h
template <typename T>
class Vector {
    private:
        // Definimos data como el puntero donde se va ubicar el vector
        T* data = nullptr;

        // Definimos capacity para saber cuantos elementos podemos guardar antes
        // De tener que realocar el vector en otra parte de la memoria
        unsigned int capacity = 0;
        // Usamos size para saber cuantos elementos tenemos en el vector
        unsigned int size = 0;

        // Usamos reAlloc para asignar al vector una nueva direcicón de memoria cuando 
        // se llena
        void reAlloc(unsigned int new_capacity){
            // Asignamos un nuevo espacio en memoria con el nuevo tamaño
            T* new_data = new T[new_capacity];

            // Verificacion de erroes potenciales al no haber agrandado el tamaño
            if(new_capacity < size) {
                size = new_capacity;
            }

            // Copiamos cada elemento del vector en el nuevo espacio
            for(unsigned int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }

            // Liberamos el espacio de memoria previo
            if(data) {
                delete[] data;
            }
            // Lo guardamos en la instancia
            data = new_data;
            // Asignamos la nueva capacidad
            capacity = new_capacity;
        };
    public:
        // Constructor:
        // Para hacer más fácil la reasignación, definimos dos elementos iniciales:
        Vector() {
            reAlloc(2);
        };
        // En el destructor nos aseguramos de liberar la memoria usada
        // y asignar nullptr al puntero que dejamos de usar
        ~Vector() {
            if(data) {
                delete[] data;
                data = nullptr;
            }
        }
        
        // Función para agregar elementos al vector
        void pushBack(T value) {
            // Verificamos si necesitamos más espacio
            if(size >= capacity) {
                // En ese caso, agregamos un 50% más de espacio
                reAlloc(capacity + capacity / 2);
            }

            // Asignamos el nuevo valor al tamaño
            // (Considerando que el indices empiezan en cero)
            data[size] = value;
            // Aumentamos la cantida de elementos que tenemos
            size++;
        }

        // Sobrecargamos un operador para que el vector funcione
        // como los arreglos nativos del tipo: vector[indice]
        const T& operator[](unsigned int index) const {
            return data[index];
        }

        // Sobrecargamos un operador para que el vector funcione
        // como los arreglos nativos del tipo: vector[indice] = valorNuevo
        T& operator[](unsigned int index) {
            return data[index];
        }

        // Obtener cantidad de elementos:
        unsigned int length() const { return size; }

};

#endif