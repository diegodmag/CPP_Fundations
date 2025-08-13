#include <iostream>

/**
 * There are many instances in programming where we 
 * need more than one variable in order to represent something of interest
 */


/**
 * Hay dos tipos compuestos en C++: structs y clases. Un struct es un tipo de dato definido por el programa.
 * Es decir un program-defined data type que permite agrupar multiples variables en un solo tipo.
 */

/**
 * REMINDER:
 * A struct is a class type (as are classes and unions). As such, anything that applies to class types applies to structs.
 */

// example 

namespace Employee{
    struct Employee
    {
    // The variables that are part of the struct are called data members (or member variables)
        int id {};
        int age {};
        double wage {};
    };
};

/**
 * REMINDER:
 * En C++ un miembro es una variable, funcion o tipo que pertenece a una strcut o una clase. 
 * All members must be declared within the struct (or class) definition.
 */

/**
 * En programacion general, un tipo de dato agregado o agregado (aggregate data type) es cualquier
 * tipo que puede contenet multiples data members. Algunos tipos de agregados permiten a los miembros
 * tener diferentes tipos (como las estructuras), mientras otros requieren que todos los miembros sean 
 * de un solo tipo (como los arreglos).
 * */

void aggregate_initialization(){
    //Para inicializar un aggregate se usa el aggregate initialization
    // Employee::Employee juan {1, 32, 45000.0};

    Employee::Employee juan {.id = 2, .age=40, .wage=40000.0f};

    std::cout << juan.id << '\n';
    std::cout << juan.age << '\n';
    std::cout << juan.wage << '\n';

    juan = {.id = 7, .age=44, .wage=40000.0f};

    std::cout << juan.id << '\n';
    std::cout << juan.age << '\n';
    std::cout << juan.wage << '\n';

    Employee::Employee pepe {juan};

    pepe = {.id=3, .age=pepe.age, .wage = pepe.wage};
    
    std::cout << pepe.id << '\n';
    std::cout << pepe.age << '\n';
    std::cout << pepe.wage << '\n';

    //g++ -std=c++20 main.cpp -o main
}


/**
 * Overloading operator<< to print a struct
 */
// std::ostream& operator<<(std::ostream& out, const Employee::Employee& e)
// {
//     out << e.id << ' ' << e.age << ' ' << e.wage;
//     return out;
// }

int main(){

    aggregate_initialization();
 
    return 0;
}