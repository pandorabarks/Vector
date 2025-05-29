#include "includes/vector.h"

int main(){
    Vector v;
    int opcion;
    double valor;
    int indice;

    do {
        std::cout << "\nMenú de opciones:\n";
        std::cout << "1. Agregar elemento\n";
        std::cout << "2. Eliminar último elemento\n";
        std::cout << "3. Acceder a un elemento\n";
        std::cout << "4. Mostrar tamaño y capacidad\n";
        std::cout << "5. Redimensionar vector\n";
        std::cout << "6. Limpiar vector\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese un valor: ";
                std::cin >> valor;
                v.push(valor);
                break;
            case 2:
                v.pop();
                break;
            case 3:
                std::cout << "Ingrese el índice: ";
                std::cin >> indice;
                if (indice >= 0 && indice < v.size()) {
                    std::cout << "Valor en índice " << indice << ": " << v[indice] << "\n";
                } else {
                    std::cout << "Índice fuera de rango.\n";
                }
                break;
            case 4:
                std::cout << "Tamaño: " << v.size() << ", Capacidad: " << v.capacity() << "\n";
                break;
            case 5:
                int nuevaCapacidad;
                std::cout << "Ingrese nueva capacidad: ";
                std::cin >> nuevaCapacidad;
                v.resize(nuevaCapacidad);
                break;
            case 6:
                v.clear();
                break;
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 0);
    
}