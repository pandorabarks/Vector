#include "../includes/vector.h"
#include <stdexcept>
#include <algorithm> // Para std::copy
#include <iostream>

Vector::Vector() : datos(nullptr), capacidad(0), sizeVec(0) {}

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

Vector::~Vector() {
    delete[] datos;
}

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

double& Vector::operator[](int indice) {
    if (indice < 0 || indice >= sizeVec)
        throw std::out_of_range("Índice fuera de rango");
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

void Vector::pop() {
    if (sizeVec > 0)
        --sizeVec;
}

int Vector::size() const {
    return sizeVec;
}

int Vector::capacity() const {
    return capacidad;
}

// Cambia el tamaño lógico del vector. Si el nuevo tamaño es mayor que la capacidad actual, redimensiona el vector.
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