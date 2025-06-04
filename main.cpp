#include "../includes/vector.h"
#include "../src/vector.cpp"

int main() {
    Vector v;
    int opcion;
    double valor;
    int indice;

    do {
        // Este es el menú de opciones que se mostrará al usuario
        std::cout << "\n--- Menú de opciones ---:\n";
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
                // Agregar un elemento al vector
                std::cout << "Ingrese un valor: ";
                std::cin >> valor;
                v.push(valor);
                break;
            case 2:
                // Eliminar el último elemento del vector
                v.pop();
                break;
            case 3:
                // Acceso a un elemento por índice, recordando que en arreglos y vectores, el índice comienza en 0.
                std::cout << "Ingrese el índice que desea buscar: ";
                std::cin >> indice;
                if (indice >= 0 && indice < v.size()) {
                    std::cout << "Valor en índice (" << indice << "): " << v[indice] << "\n";
                } else {
                    std::cout << "Índice fuera de rango. No se encuentra. Intente nuevamente.\n";
                }
                break;
            case 4:
                // Muestra el tamaño y la capacidad del vector
                std::cout << "El tamaño del vector es: " << v.size() << ", la capacidad es: " << v.capacity() << "\n";
                break;
            case 5: {
                // Redimensiona el vector a una nueva capacidad, solo que solo cambia el tamaño lógico, pero no la capacidad física del vector.
                int nuevaCapacidad;
                std::cout << "Ingrese una nueva capacidad: ";
                std::cin >> nuevaCapacidad;
                v.resize(nuevaCapacidad);
                break;
            }
            case 6:
            // Limpia el vector
                v.clear();
                break;
            case 0:
                // Salir del programa
                std::cout << "Saliendo...\n";
                break;
            default:
                // En caso de que el usuario ingrese una opción no válida
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 0); // Bucle para continuar hasta que el usuario decida salir

    return 0;
}