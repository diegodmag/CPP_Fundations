#include "IntroVector.h"

void std_vector::intro_vector(){
    std::cout<< "This is an introduction to std_vector\n";
 
    
    std::vector<int>  primes {2,3,5,7};

    std::vector vowels {'a','e','i','o','u'}; // Not explicity specified type 
                                              // Using class template argument deduction
    std::cout<<&(primes[0])<<'\n';
    std::cout<<&(primes[1])<<'\n';
    std::cout<<&(primes[2])<<'\n';

    //Un entero esta compuesto por 4 bytes 
    //Entonces

    // El output sera como: 
    // 0x579aaf6ad6c0
    // 0x579aaf6ad6c4
    // 0x579aaf6ad6c8

    // Declaring a specific length vector 
    std::vector<int> data (10); // This is direct initialization (with parenthesis )

    // This creates a std::vector with a capacity of 8, and then uses that as the initializer for v
    std::vector<int> v{ std::vector<int>(8) }; // ok
    
    //Para obtener el length de un container se usa .size() o std::size()
    std::cout<<".size(): "<<v.size()<<'\n';
    std::cout<<"std::size(): "<<std::size(v)<<'\n';

    //Para almacenar el tamanio 
    int length {static_cast<int>(v.size())};
    std::cout<<length<<'\n';


    //En C++ 20 se introdujo std::ssize(), el cual regresa el length como un large signed integral type 

    //Usar la member function at(), accede a un elmento haciendo bound checking 

    std::vector prime{ 2, 3, 5, 7, 11 };

    std::cout << "Usando at: "<< prime.at(3)<<'\n'; // print the value of element with index 3
    // --> en vez de regresar una referencia, la funcion at genera un error que termina el programa 
    //std::cout << prime.at(9); // invalid index (throws exception)


    // Se puede idexar al .data() de un vector para poder usar sign int en vez de el mismo vecor, el .data() regresa un C-Style array 
    int index { 3 };                          // non-constexpr signed value
    std::cout << "Usando .data(): "<<prime.data()[index] << '\n'; // okay: no sign conversion warnings

}