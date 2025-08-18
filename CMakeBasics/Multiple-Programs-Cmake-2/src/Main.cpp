// main.cpp  
//    ↓ (Preprocesador: g++ -E)  
// main.i  
//    ↓ (Compilador: g++ -S)  Verifica sintaxis, tipos y reglas del lenguaje - Si hay errores, aquí se detectan.
// main.s  
//    ↓ (Ensamblador: g++ -c)  convierte el código ensamblador en código máquina (binario) - archivos objeto (.o en Linux, .obj en Windows).
// main.o  
//    ↓ (Linker) - combina todos los archivos objeto y bibliotecas necesarias - Produce el ejecutable final
// programa (ejecutable)

#include "Hello.h"
#include "Godbye.h"

int main() {
    printHello("Diego");

    printGodbye("Diego");
    return 0;
}
