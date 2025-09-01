#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>


#include "io_files/Input.h"
#include "io_files/Output.h"

#include "io_files/Example.h"

void example();

void input_example();

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Debes especificar un comando\n";
        return 1;
    }

    std::string comando = argv[1];

    std::unordered_map<std::string, std::function<void()>> comandos = {
        {"output_example", []{ output::example();   }}
        , {"example_get", []{ input::example_get();   }}
        , {"example_get_2", []{ input::example_get_2();   }}
        , {"example_getline", []{ input::example_getline();   }}
        , {"input_example_extraction", []{ input::example_extraction();   }}
        , {"basic_example", []{ input::basic_example();   }}
        , {"input_example", []{ input_example();   }}


        , {"final_example_output", []{ example_of_use::output();  }}
        , {"final_example_input", []{ example_of_use::input();  }}
        , {"reading_obj", []{ example_of_use::readObjExample("obj/mini_square.obj");  }}
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

void example(){
    std::cout<<"Hello\n";
}

void input_example(){
    char ch{};

    while(std::cin >> ch){
        std::cout << ch; 
    }



}