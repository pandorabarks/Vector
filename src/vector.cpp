#include "../includes/vector.h"
#include <stdexcept>
#include <algorithm> // Para std::copy
#include <iostream>

// Este es el archivo que implementa las funciones miembro de la clase Vector.

Vector::Vector() : datos(nullptr), capacidad(0), sizeVec(0) {}

// Constructor por defecto
Vector::Vector(int CapacidadInicial) : datos(nullptr), capacidad(CapacidadInicial), sizeVec(0) {
    if (capacidad > 0)
        datos = new double[capacidad];
}

Vector::Vector(const Vector& otro) : datos(nullptr), capacidad(otro.capacidad), sizeVec(otro.sizeVec) {
    if (capacidad > 0) {
        datos = new double[capacidad];
        std::copy(otro.datos, otro.datos + sizeVec, datos);
    }
}

// Constructor copia que crea un nuevo vector a partir de otro existente.
Vector::~Vector() {
    delete[] datos;
}

// Destructor
Vector& Vector::operator=(const Vector& otro) {
    if (this != &otro) {
        delete[] datos;
        capacidad = otro.capacidad;
        sizeVec = otro.sizeVec;
        datos = (capacidad > 0) ? new double[capacidad] : nullptr;
        std::copy(otro.datos, otro.datos + sizeVec, datos);
    }
    return *this;
}

// Operadores que permiten acceder a los elementos del vector mediante un índice, tanto para lectura como para escritura.
double& Vector::operator[](int indice) {
    if (indice < 0 || indice >= sizeVec) {
        // Throw es un método que lanza una excepción si el índice está fuera de rango.
        throw std::out_of_range("Índice fuera de rango");
    }
    return datos[indice];
}


const double& Vector::operator[](int indice) const {
    if (indice < 0 || indice >= sizeVec)
        throw std::out_of_range("Índice fuera de rango");
    return datos[indice];
}

void Vector::push(double valor) {
    if (sizeVec == capacidad)
        redimensionar(capacidad == 0 ? 1 : capacidad * 2);
    datos[sizeVec++] = valor;
}

// Agrega un valor al final del vector, redimensionando si es necesario.
void Vector::pop() {
    if (sizeVec > 0)
        --sizeVec;
}

// Elimina el último elemento del vector
int Vector::size() const {
    return sizeVec;
}

// Devuelve el número de elementos actualmente almacenados en el vector.
int Vector::capacity() const {
    return capacidad;
}

// Cambia el tamaño lógico del vector.
void Vector::resize(int n) {
    if (n > capacidad)
        redimensionar(n);
    sizeVec = n;
}

// Elimina todos los elementos del vector, pero no cambia la capacidad.
void Vector::clear() {
    sizeVec = 0;
}

// Redimensiona el vector a una nueva capacidad, si el tamaño que se ingresa es menor a la capacidad actual, no hace nada más que redimensionar el tamaño lógico.
// Hubiera estado genial poder redimensionar la capacidad también, pero por más que lo intentamos, no pudimos resolverlo a tiempo.
void Vector::redimensionar(int NuevaCapacidad) {
    if (NuevaCapacidad <= capacidad)
        return;
    double* nuevo = new double[NuevaCapacidad];
    for (int i = 0; i < sizeVec; ++i)
        nuevo[i] = datos[i];
    delete[] datos;
    datos = nuevo;
    capacidad = NuevaCapacidad;
}