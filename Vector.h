#ifndef VECTOR_H
#define VECTOR_H

// Implementación de arreglo dinámico de números enteros:

template <typename T>
class Vector {
    private:
        T* data = nullptr;

        unsigned int capacity = 0;
        unsigned int size = 0;
    public:
        Vector() {
            re_alloc(2);
        };
        void re_alloc(unsigned int new_capacity){
            T* new_data = new T[new_capacity];

            if(new_capacity < size) {
                size = new_capacity;
            }

            for(unsigned int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        };

        void push_Back(T value) {

            if(size >= capacity) {
                re_alloc(capacity + capacity / 2);
            }

            data[size] = value;
            size++;
        }

        const T& operator[](unsigned int index) const {
            if(index >= size) {
                // throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        T& operator[](unsigned int index) {
            return data[index];
        }

        unsigned int length() const { return size; }

};

#endif