#include <string>
#include <unordered_map>
#include <functional>

#include "basics/Inheritance.h"

#include "basics/Person.h"
#include "basics/BaseballPlayer.h"
#include "basics/Employee.h"

void Inheritance_Example();

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Debes especificar un comando\n";
        return 1;
    }

    std::string comando = argv[1];

    std::unordered_map<std::string, std::function<void()>> comandos = {
        {"HelloInheritance", []{ inheritance::HelloInheritance(); }},
        {"Inheritance_Example", []{ Inheritance_Example();   }}
        //Inheritance_Example
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

void Inheritance_Example(){
    // Create a new BaseballPlayer object
    BaseballPlayer joe{};
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class

    Employee pepe {30.0, 12345};

    pepe.m_name="Pepe";

    pepe.printNameAndSalary();


}