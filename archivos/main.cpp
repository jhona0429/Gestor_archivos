#include "sistema_archivos.h"
#include <iostream>
#include <stack> 

// funcion para las opciones en la terminal
void mostrar_menu() {
    std::cout << "1. Crear archivo" << std::endl;
    std::cout << "2. Leer archivo" << std::endl;
    std::cout << "3. Escribir archivo" << std::endl;
    std::cout << "4. Eliminar archivo" << std::endl;
    std::cout << "5. Listar archivos" << std::endl;
    std::cout << "6. Crear directorio" << std::endl;
    std::cout << "7. Listar directorios" << std::endl;
    std::cout << "8. Cambiar directorio" << std::endl;
    std::cout << "9. Volver al directorio principal" << std::endl;
    std::cout << "10. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main() {
    // Crea el directorio raíz "Raiz" con un segundo parematros que es permisos 
    Directorio directorio_raiz("Raiz", true);

    // Puntero al directorio raíz
    Directorio* directorio_actual = &directorio_raiz;

    // Pila que se usa para guardar los directorios visitados (para poder regresar)
    std::stack<Directorio*> pila_directorios;

    // Variables para almacenar la opción seleccionada
    int opcion;
    std::string nombre, contenido;

    // Bucle infinito hasta que se le de salir
    while (true) {
        mostrar_menu();
        std::cin >> opcion;  // Lee la opción elegida por el usuario

        // Procesa la opción seleccionada
        switch (opcion) {
        case 1:
            std::cout << "Ingrese el nombre del archivo: ";
            std::cin >> nombre;
            std::cout << "Ingrese el contenido del archivo: ";
            std::cin.ignore();
            std::getline(std::cin, contenido);
            directorio_actual->agregar_archivo(nombre, contenido);
            break;
        case 2:
            std::cout << "Ingrese el nombre del archivo: ";
            std::cin >> nombre;
            directorio_actual->leer_archivo(nombre);
            break;
        case 3:
            std::cout << "Ingrese el nombre del archivo: ";
            std::cin >> nombre;
            std::cout << "Ingrese el nuevo contenido del archivo: ";
            std::cin.ignore();
            std::getline(std::cin, contenido);
            directorio_actual->escribir_archivo(nombre, contenido);
            break;
        case 4:
            std::cout << "Ingrese el nombre del archivo: ";
            std::cin >> nombre;
            directorio_actual->eliminar_archivo(nombre);
            break;
        case 5:
            directorio_actual->listar_archivos();
            break;
        case 6:
            std::cout << "Ingrese el nombre del directorio: ";
            std::cin >> nombre;
            directorio_actual->agregar_directorio(nombre);
            break;
        case 7:
            directorio_actual->listar_directorios();
            break;
        case 8:
            std::cout << "Ingrese el nombre del directorio al que desea cambiar: ";
            std::cin >> nombre;
            if (directorio_actual->subdirectorios.find(nombre) != directorio_actual->subdirectorios.end()) {
                pila_directorios.push(directorio_actual);
                directorio_actual = &directorio_actual->subdirectorios[nombre];
                std::cout << "Cambiado al directorio " << nombre << std::endl;
            }
            else {
                std::cout << "Error: El directorio " << nombre << " no existe." << std::endl;
            }
            break;
        case 9:
            if (!pila_directorios.empty()) {   // Si hay directorios anteriores en la pila
                directorio_actual = pila_directorios.top();  // Restaura el directorio anterior
                pila_directorios.pop();   // Elimina el directorio de la pila
                std::cout << "Directorio de raiz" << std::endl;
            }
            else {
                std::cout << "Ya estás en el directorio raíz" << std::endl;
            }
            break;
        case 10:
            return 0;
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
        }
    }
}
