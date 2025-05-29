#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    double* datos;
    int capacidad;
    int sizeVec;

    void redimensionar(int NuevaCapacidad);

public:
    Vector(); // Constructor por defecto
    Vector(int CapacidadInicial); // Constructor paramétrico
    Vector(const Vector& otro); // Constructor copia
    ~Vector(); // Destructor

    Vector& operator=(const Vector& otro); // Operador de asignación

    double& operator[](int indice); // Acceso por subíndice (modificable)
    const double& operator[](int indice) const; // Acceso por subíndice (const)

    void push(double valor); // Agrega un valor al final
    void pop(); // Elimina el último elemento

    int size() const; // Número de elementos
    int capacity() const; // Capacidad actual

    void resize(int n); // Cambia el tamaño lógico
    void clear(); // Elimina todos los elementos
};

#endif // VECTOR_H