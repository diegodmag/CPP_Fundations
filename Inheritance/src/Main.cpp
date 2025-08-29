
#include <string>
#include <unordered_map>
#include <functional>


// Introduction to Inheritance

#include "basics/Person.h"
#include "basics/BaseballPlayer.h"
#include "basics/Employee.h"

// Order of constructio 

#include "construction_order/Base.h"
#include "construction_order/Derived.h"

// Derived Class Constructors 

#include "construction_order/BasePrivate.h"
#include "construction_order/DerivedPrivate.h"

// From derived folder, in order to show inheritance 
#include "derived/Persona.h"
#include "derived/Jugador.h"

void Inheritance_Example(); //Intro inheritance

void Construction_Order_Example(); //Order of constructors 

void Derived_Classes_Constructor_Example();  // Constructors of derived classes 

void Inheritance_Example_2();

void Changing_Behavior_Example();

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Debes especificar un comando\n";
        return 1;
    }

    std::string comando = argv[1];

    std::unordered_map<std::string, std::function<void()>> comandos = {
        {"Inheritance_Example", []{ Inheritance_Example();   }},
        {"Construction_Order_Example", []{ Construction_Order_Example();   }},
        {"Derived_Classes_Constructor_Example", []{ Derived_Classes_Constructor_Example();   }},
        {"Inheritance_Example_2", []{ Inheritance_Example_2();   }},
        {"Changing_Behavior_Example", []{ Changing_Behavior_Example();   }}
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

void Construction_Order_Example()
{

    std::cout << "Instantiating Base\n";
    Base base;

    std::cout << "Instantiating Derived\n";
    Derived derived;


}

void Derived_Classes_Constructor_Example(){

    DerivedPrivate derived {50.0, 5}; 
    
    std::cout << "Derived id: " << derived.getID() <<'\n';

    std::cout << "Derived cost" << derived.getCost() <<'\n';

}

void Inheritance_Example_2(){

    Jugador piter{20, "Peter", "Parker", 12345, "el_piter"}; 

}

void Changing_Behavior_Example(){
    Jugador piter{20, "Peter", "Parker", 12345, "el_piter"}; 
    piter.Saludar();
}