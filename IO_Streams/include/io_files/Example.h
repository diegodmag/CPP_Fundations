#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace example_of_use {

    // ----------------------------------------------------------
    // Escritura de archivo de ejemplo
    // ----------------------------------------------------------
    int output() {
        std::ofstream outFile("files/example.txt", std::ios::out | std::ios::trunc);
        if (!outFile) {
            std::cerr << "No se pudo abrir el archivo para escritura.\n";
            return 1;
        }

        // Escribir caracteres y enteros
        outFile.put('A');        // un solo char
        outFile.put('\n');       // salto de línea
        int number = 42;
        outFile << number << "\n"; // entero como texto
        outFile << "Hola Mundo\n";

        // Escribir un arreglo de caracteres con índices
        char str[] = "CADENA";
        for (size_t i = 0; i < 6; ++i) {
            outFile.put(str[i]);
            outFile.put('\t');
            outFile << i;
            outFile.put('\n');
        }

        // Ejemplo de flush manual
        outFile << "Linea con flush" << std::flush << "\n";
        outFile << "Otra línea" << std::endl; // también hace flush

        outFile.close(); // cerrar explícitamente
        std::cout << "Archivo escrito correctamente.\n";
        return 0;
    }

    // ----------------------------------------------------------
    // Lectura de archivo de ejemplo
    // ----------------------------------------------------------
    int input() {
        std::ifstream inFile("files/example.txt", std::ios::in);
        if (!inFile) {
            std::cerr << "No se pudo abrir el archivo para lectura.\n";
            return 1;
        }

        // Leer primer caracter
        char ch;
        inFile.get(ch);
        std::cout << "Primer caracter leído: " << ch << "\n";
        if (ch == 'A') {
            std::cout << "Se detectó la letra A\n";
        }

        // Leer un entero
        int num;
        inFile >> num;
        std::cout << "Número leído: " << num << " (lo multiplicamos por 2 -> " << num * 2 << ")\n";

        // Leer el resto del archivo línea por línea
        inFile.ignore(); // ignorar el salto de línea pendiente
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << "Linea: " << line << "\n";
        }

        // Reiniciar el stream para leer nuevamente de forma estructurada
        inFile.clear();
        inFile.seekg(0);

        // Leer líneas con formato "char int int"
        char c;
        int x, y;
        std::cout << "\nLeyendo líneas de formato 'char int int'\n";
        while (inFile >> c >> x >> y) {
            std::cout << "Caracter: " << c << ", X: " << x << ", Y: " << y << "\n";
            if (c == 'D') {
                std::cout << "¡Encontramos la D!\n";
            }
        }

        inFile.close();
        std::cout << "Lectura finalizada.\n";
        return 0;
    }

    // ----------------------------------------------------------
    // Ejemplo de lectura tipo .obj (vértices y caras)
    // ----------------------------------------------------------
    struct Vertex { float x, y, z; };
    struct Face { int v1, v2, v3; };

    int readObjExample(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "No se pudo abrir " << filename << "\n";
            return 1;
        }

        std::vector<Vertex> vertices;
        std::vector<Face> faces;

        std::string type;
        while (inFile >> type) {
            if (type == "v") {
                Vertex v;
                inFile >> v.x >> v.y >> v.z;
                std::cout<< "v.x: " << v.x << " v.y: " << v.y << " v.z: " << v.z<<'\n'; 
                vertices.push_back(v);
            } else if (type == "f") {
                Face f;
                inFile >> f.v1 >> f.v2 >> f.v3;
                std::cout<< "f.v1: " << f.v1 << " f.v2: " << f.v2 << " f.v3: " << f.v3<<'\n';
                faces.push_back(f);
            } else {
                std::string line;
                std::getline(inFile, line); // ignorar línea desconocida
            }
        }

        std::cout << "Vertices leídos: " << vertices.size() << "\n";
        std::cout << "Caras leídas: " << faces.size() << "\n";

        inFile.close();
        return 0;
    }

} // namespace example_of_use

#endif
