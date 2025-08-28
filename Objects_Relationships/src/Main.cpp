#include <string>
#include <unordered_map>
#include <functional>

#include "Aggregation.h"
#include "Association.h"

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Debes especificar un comando\n";
        return 1;
    }

    std::string comando = argv[1];

    std::unordered_map<std::string, std::function<void()>> comandos = {
        {"aggregation_example", []{ aggregation_example::aggregation_example(); }},
        {"association_example_1", []{ association_example::association_ejectuion_example(); }}
        
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