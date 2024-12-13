#include "sistema_archivos.h"

// Implementación de la clase Archivo

// Inicializa el nombre y el contenido del archivo
Archivo::Archivo(std::string nombre, std::string contenido)
    : nombre(nombre), contenido(contenido) {}

// imprime el nombre del archivo y su contenido
void Archivo::leer() {
    std::cout << "Contenido de " << nombre << ": " << contenido << std::endl;
}

// actualiza el contenido del archivo y se guarda
void Archivo::escribir(std::string nuevo_contenido) {
    contenido = nuevo_contenido;
    std::ofstream archivo(nombre);
    if (archivo.is_open()) {
        archivo << contenido;
        archivo.close();
    }
}

// Implementación de la clase Directorio

// inicializa el nombre del directorio y el permiso
Directorio::Directorio(std::string nombre, bool tiene_permisos)
    : nombre(nombre), tiene_permisos(tiene_permisos) {}

// funcion para agregar archivo al directorio
void Directorio::agregar_archivo(std::string nombre, std::string contenido) {
    if (archivos.find(nombre) == archivos.end()) {
        archivos[nombre] = Archivo(nombre, contenido);
        std::ofstream archivo(nombre);
        if (archivo.is_open()) {
            archivo << contenido;
            archivo.close();
        }
    }
    else {
        std::cout << "Error: El archivo " << nombre << " ya existe." << std::endl;
    }
}
 // funcion para buscar un archivo en el directorio 
void Directorio::leer_archivo(std::string nombre) {
    if (archivos.find(nombre) != archivos.end()) {
        archivos[nombre].leer();
    }
    else {
        std::cout << "Error: El archivo " << nombre << " no existe." << std::endl;
    }
}
// funcion para actualizar un archivo 
void Directorio::escribir_archivo(std::string nombre, std::string nuevo_contenido) {
    if (archivos.find(nombre) != archivos.end()) {
        archivos[nombre].escribir(nuevo_contenido);
    }
    else {
        std::cout << "Error: El archivo " << nombre << " no existe." << std::endl;
    }
}
// funcion para eliminar un archivo 
void Directorio::eliminar_archivo(std::string nombre) {
    if (archivos.find(nombre) != archivos.end()) {
        archivos.erase(nombre);
        std::remove(nombre.c_str());
        std::cout << "Archivo " << nombre << " eliminado exitosamente." << std::endl;
    }
    else {
        std::cout << "Error: El archivo " << nombre << " no existe." << std::endl;
    }
}
// funcion para mostrar los archivos de un directorio
void Directorio::listar_archivos() {
    std::cout << "Archivos en el directorio " << nombre << ": ";
    for (auto& archivo : archivos) {
        std::cout << archivo.first << " ";
    }
    std::cout << std::endl;
}
// funcion para crear sub directorios
void Directorio::agregar_directorio(std::string nombre) {
    if (subdirectorios.find(nombre) == subdirectorios.end()) {
        subdirectorios[nombre] = Directorio(nombre);
        std::cout << "Directorio " << nombre << " creado exitosamente." << std::endl;
    }
    else {
        std::cout << "Error: El directorio " << nombre << " ya existe." << std::endl;
    }
}
// funcion para listar los sub directorios
void Directorio::listar_directorios() {
    std::cout << "Subdirectorios en " << nombre << ": ";
    for (auto& subdirectorio : subdirectorios) {
        std::cout << subdirectorio.first << " ";
    }
    std::cout << std::endl;
}
