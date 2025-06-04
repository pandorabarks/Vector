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
    // Constructores (por defecto, paramétrico, copia) y destructor
    Vector();
    Vector(int CapacidadInicial); 
    Vector(const Vector& otro); 
    ~Vector();

    Vector& operator=(const Vector& otro); // Operador de asignación

    // Acceso por subíndice (constante y modificable)
    double& operator[](int indice); 
    const double& operator[](int indice) const;

    // Agrega y elimina elementos
    void push(double valor);
    void pop();

    int size() const;
    int capacity() const;

    void resize(int n);
    void clear();
};

#endif // VECTOR_H

// Nota para el equipo: Este archivo es de cabecera, no debería contener implementaciones de funciones miembro.