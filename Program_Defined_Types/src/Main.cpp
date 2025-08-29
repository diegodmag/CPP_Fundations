#include <string>
#include <unordered_map>
#include <functional>

#include "IntroClasses.h"
#include "IntroClasses2.h"

void copy_constructors_example();

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Debes especificar un comando\n";
        return 1;
    }

    std::string comando = argv[1];

    std::unordered_map<std::string, std::function<void()>> comandos = {
        {"const_struct_example", []{ intro_classes::const_struct_example(); }},
        {"cases_for_data_members_for_rvalue", []{intro_classes::cases_for_data_members_for_rvalue();}},
        {"constructor_cases", []{intro_classes::constructor_cases();}},
        {"copy_constructors_example", []{copy_constructors_example();}}
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


void copy_constructors_example(){

    intro_classes_2::Monster zombie {"Zombie",intro_classes_2::Monster::Type::UNDEAD,1};
    zombie.ShowMonsterInformation();

    std::cout<<"Monster address: "<< &zombie <<'\n'; 

    std::cout<<"<<<<<<<<<<<<<<\n";
    intro_classes_2::Monster zombie_2 {zombie};
    zombie_2.ShowMonsterInformation();

    std::cout<<"Monster address: "<< &zombie_2 <<'\n'; 

}