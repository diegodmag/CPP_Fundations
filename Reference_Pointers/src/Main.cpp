#include "ReferencesPointers.h"


// main.cpp  
//    ↓ (Preprocesador: g++ -E)  
// main.i  
//    ↓ (Compilador: g++ -S)  
// main.s  
//    ↓ (Ensamblador: g++ -c)  
// main.o  
//    ↓ (Linker)  
// programa (ejecutable)

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <funcion> [parametros...]\n";
        return 1;
    }

    std::string comando = argv[1];

    // REFERENCES
    if (comando == "print_string_by_reference") {
        if (argc < 3) {
            std::cerr << "Falta el parametro string\n";
            return 1;
        }
        std::string str = argv[2];
        references_pointers::print_string_by_reference(str);
    }
    else if (comando == "print_val_and_ref_address_example") {
        references_pointers::print_val_and_ref_address_example();
    }
    else if (comando == "const_reference_bidings") {
        references_pointers::const_reference_bidings();
    }
    else if (comando == "return_by_ref_example"){
        references_pointers::return_by_ref_example();
    }

    
    // POINTERS
    else if (comando == "intro_to_pointers") {
        references_pointers::intro_to_pointers();
    }
    else if (comando == "different_argument_passing") {
        references_pointers::different_argument_passing();
    }
    else if (comando == "showing_passing_value_pointers") {
        references_pointers::showing_passing_value_pointers();
    }
    else if (comando == "pointer_verification_example") {
        references_pointers::pointer_verification_example();
    }
    else if (comando == "introduction_to_references") {
        references_pointers::introduction_to_references();
    }
    else if (comando == "reference_exercise") {
        references_pointers::reference_exercise();
    }
    else {
        std::cerr << "Funcion no reconocida: " << comando << "\n";
        return 1;
    }

    return 0;
}
