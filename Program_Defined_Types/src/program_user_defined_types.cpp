#include <iostream>
#include "Fraction.h"

//For experiments 
#include <random> 
#include <cstdlib>
#include <ctime>

// A user defined function to get a rvalue random number from a uniform distribution
int get_random_int(int x, int y) {
    // Motor de números aleatorios con semilla no determinista
    static std::random_device rd;              
    static std::mt19937 gen(rd());             // Motor MT19937 basado en rd()

    // Distribución uniforme en el rango [x, y]
    std::uniform_int_distribution<> distrib(x, y);

    return distrib(gen); // Genera y devuelve el número aleatorio
}



// INTRODUCTION TO USER/PROGRAM DEFINED TYPES

using Length = int; // define a type alias with identifier 'Length'

// int main()
// {
//     Length x { 5 }; // we can use 'length' here since we defined it above
//     std::cout << x << '\n';

//     return 0;
// }


///What are user-defined / program-defined types?

/**
 * C++ has two different categories of compound types that can be used to create program-defined types:
 *      Enumerated types (including unscoped and scoped enumerations)
 *      Class types (including structs, classes, and unions).
 */

 //A program-defined type must have a name and a definition before it can be used. 


 // Define a program-defined type named Fraction so the compiler understands what a Fraction is
// (we'll explain what a struct is and how to use them later in this chapter)
// This only defines what a Fraction type looks like, it doesn't create one
// struct Fraction
// {
// 	int numerator {};
// 	int denominator {};
// };

void showing_fraction_struct(){
    Fraction f { 3, 4 }; // this actually instantiates a Fraction object named f

    std::cout << f.numerator << "/" << f.denominator << '\n';

    Fraction frac {};

    frac.numerator = 40; 
    frac.denominator = 60;

    std::cout << frac.numerator << "/" << frac.denominator << '\n';

}


// ENUMERATIONS 

/**
 * An enumeration (also called an enumerated type or an enum) is a compound data type 
 * whose values are restricted to a set of named symbolic constants (called enumerators).
 * 
 * C++ supports two kinds of enumerations: unscoped enumerations 
 * (which we’ll cover now) and scoped enumerations (which we’ll cover later in this chapter).
 */

//Unscoped enumerations

// Define a new unscoped enumeration named Color
enum Color 
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red,
    green,
    blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

/**
 * To quickly recap on nomenclature:
 * An enumeration or enumerated type is the program-defined type itself (e.g. Color). 
 * An enumerator is a specific named value belonging to the enumeration (e.g. red)
 */

// int main()
// {
//     Color apple  {red};
//     Color shirt {green};
//     Color cup {blue};

//     std::cout << "Random number " << get_random_int(1,12) << '\n';
    
// 	return 0;
// }

/**
 * Unscoped enumerations are named such because they put their enumerator names 
 * into the same scope as the enumeration definition itself (as opposed to creating 
 * a new scope region like a namespace does).
 * 
 * WARNING: 
 * One consequence of this is that an enumerator name can’t be used in multiple enumerations within the same scope:
 */


 /**
  * A way to prevent enumeration's enumerators collide because their names is 
  * put the enumerated type inside something that provides a separate scope region, such as a namespace:
  */
 
  // For example: 

namespace Day
{
    // The names Color, red, blue, and green are defined inside namespace Color
    enum Day
    {
        sunday,
        monday,
        tuesday,
        wednesday, 
        thursday, 
        friday, 
        saturday,
    };
}

namespace Feeling
{
    enum Feeling
    {
        happy,
        tired,
        blue, // Feeling::blue doesn't collide with Color::blue
    };
}


// This means we now have to prefix our enumeration and enumerator names with the name of the scoped region

/**
 * BEST PRACTICE
 * Prefer putting your enumerations inside a named scope region (such as a namespace or class) so the 
 * enumerators don’t pollute the global namespace.
 */

//Practice 
namespace MonsterType{
    enum MonsterType{
         orc,  // 0
         goblin, // 1
         troll, // 2
         ogre, // 3
         skeleton, //4
    };
}

// Just as reminder, enumerators are symbolic constants  that have integral type 

/**
 * When we define an enumeration, each enumerator is automatically associated with an 
 * integer value based on its position in the enumerator list. By default, the first enumerator 
 * is given the integral value 0, and each subsequent enumerator has a value one greater than 
 * the previous enumerator
 */


// PAUSED 

int main()
{
    MonsterType::MonsterType skeleton {MonsterType::skeleton};

    std::cout << "The monster is a " <<  skeleton  << '\n';



    return 0;
}