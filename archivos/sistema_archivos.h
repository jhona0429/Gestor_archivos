#ifndef SISTEMA_ARCHIVOS_H
#define SISTEMA_ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

// creacion de las clases 
class Archivo {
public:
    std::string nombre;
    std::string contenido;

    Archivo() = default;  // Constructor por defecto vacio para archivo
    Archivo(std::string nombre, std::string contenido = ""); // creacion de un nuevo archivo y contenido
    void leer();
    void escribir(std::string nuevo_contenido);
};

class Directorio {
public:
    std::string nombre;
    std::map<std::string, Archivo> archivos;
    std::map<std::string, Directorio> subdirectorios;
    bool tiene_permisos;

    Directorio() = default;  // Constructor por defecto vacio para directorio
    Directorio(std::string nombre, bool tiene_permisos = false);
    void agregar_archivo(std::string nombre, std::string contenido = "");
    void leer_archivo(std::string nombre);
    void escribir_archivo(std::string nombre, std::string nuevo_contenido);
    void eliminar_archivo(std::string nombre);
    void listar_archivos();
    void agregar_directorio(std::string nombre);
    void listar_directorios();
};

#endif
