#include <iostream>

// To work with pairs 
#include <utility>

#include <Pair.h>

// Don't Repeat Yourself (DRY)
/**
 * Apparently this is one of the principes that the templates follow
 */

/**
 * Unlike a normal definition (where all types must be specified)
 * in a template we can use one or more placeholders types. A placeholder
 * type represents SOME TYPE THAT IS NOT KNOWN at the time the template is definied
 * but that will be provided later (when the template is used)
 *
 * Once the template is defined, the compiler use the template to generate
 * as many overloaded functions (or classes) as needed, each
 * using different actual types.
 */

/**
 * Because the actual types aren't determined until the template is
 * used in a program, the author of the template doesn't have to try
 * to anticipate all of the actual types that might be used.
 *
 * Templates can work with types that didn't even exist when the template
 * was written.s
 */

// For Functions
/**
 * The initial function template that is used to generate
 * other functions is called the primary template.
 *
 * And the functions generated from the primary template are
 * called instantiated functions.
 *
 * we used a TYPE TEMPLATE PARAMETER - TEMPLATE TYPES
 */

// We need the keyword template to tell the compiler we are creating a template
template <typename T> // T is the TYPE TEMPLATE PARAMETER 
T max(T x, T y)
{
    return (x < y) ? y : x;
}
// Actually, template functions are not functions, their code isn't compiled or executed
// Instead, they generated functions (that are compiled and executed)

// CLASS TEMPLATES 

// struct Pair
// {
//     int first {}; 
//     int secon {};
// };

/***
 * Much like a FUNCTION TEMPLATE is a template DEFINITION fonr 
 * instantiating functions, a CLASS TEMPLATE is a template DEFINITION 
 * for instantiating class types. 
 * 
 */

// Rewriting the pair would be 
template <typename T>
struct Pair
{
    T first; 
    T second; 
};

// Now we can pass the pair as an argument 
template <typename T> // out type template parameter
T max(Pair<T> pair){
    return (pair.first < pair.second) ? pair.second : pair.first; 
}

// Recordatorio de constexpr CONSTANT EXPRESSSION
/**
 * Su objetivo principal es garantizar o permitir que ciertos calculos, 
 * funciones oo variables se ejecuten en TIEMPO DE COMPILACION en lugar 
 * de hacerlo EN TIEMPO DE EJECUCION 
 */

// 1 Variables conxtexpr 
/**
 * Se le obliga al compilador a que su valor sea conocido e inicializado 
 * de inmediato en TIEMPO DE COMPILACION 
 * 
 */
constexpr float PI = 3.0146; // < - se conocer en tiempo de compilacion  
constexpr float DOS_PI = PI * 2.0f;
// En otras palabras es CONSTANTE EN TIEMPO DE COMPILACION 

//2 Funciones constexpr 
/**
 * Una funcion constexpr es una funcion que tiene la capacidad 
 * de EJECUTARSER EN TIEMPO DE COMPILACION , SI todos los argumentos 
 * que se le pasan también son conocidos en tiempo de compilacion 
 */
// Ejemplo 
constexpr int CalculaFactorial(int n)
{
    int result = 1;
    for(int i = 1; i <= n ; i++){
        result *= n; 
    }

    return result; 
} 


// 3 Constructores y Clases 
/**
 * Estructuras planas como las clases de Vector2D o Color se benefician 
 * Se pueden CREAR INSTANCIAS COMPLETAS DE OBJETOS EN TIEMPOS 
 * DE COMPILACION 
 */

// Ejemplo 
struct  Vector2D
{
    float x; 
    float y; 

    constexpr Vector2D(float _x, float _y) : x{_x}, y{_y}{}
};


// REGRESANDO A LOS TEMPLATES 
// Class templates with multiple template types and non-template type members 
template <typename T, typename U>
struct Foo
{
    T first {}; 
    U second{}; 
    float some_number{}; 
};

template <typename T>
struct Vector
{
    T x;
    T y;
};

int main(int arg, char *argv[])
{

    templates::Pair<int> pair_int_1 {1,2};
    templates::Pair<int> pair_int_2 {2,3};
    templates::Pair<int> pair_int_3 {1,2};

    std::cout<<"P1 V P2 "<< pair_int_1.isEqual(pair_int_2) <<"\n";
    std::cout<<"P1 V P3 "<< pair_int_1.isEqual(pair_int_3) <<"\n";

    // Deduction 


}