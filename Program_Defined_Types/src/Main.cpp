#include "IntroClasses.h"
#include <string>
#include <unordered_map>
#include <functional>


int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Debes especificar un comando\n";
        return 1;
    }

    std::string comando = argv[1];

    std::unordered_map<std::string, std::function<void()>> comandos = {
        {"const_struct_example", []{ intro_classes::const_struct_example(); }},
        {"cases_for_data_members_for_rvalue", []{intro_classes::cases_for_data_members_for_rvalue();}},
        {"constructor_cases", []{intro_classes::constructor_cases();}}
    };

  
    // Ejecutar comando normal
    auto it = comandos.find(comando);
    if (it != comandos.end()) {
        it->second(); // ejecutar la función
    } else {
        std::cerr << "Funcion no reconocida: " << comando << "\n";
        return 1;
    }

    return 0;
    


}
