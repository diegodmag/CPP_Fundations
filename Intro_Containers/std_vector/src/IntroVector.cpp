#include "IntroVector.h"

#include <ranges> // C++20 for reverse iteration in foreach

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


    //Algunos ejercicios para recordar 

    //Inicaliz 5 arreglos de distintos tamaño 

    std::vector<char> characters (5);
    


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

std::vector<int> generate(){
    std::vector<int> vect {144,2,3,4,5};
    return vect; 
}

void pupulateVector(std::vector<int>& vect){
    std::vector<int> temp {generate()};

    vect = std::move(temp);
}


void printingReverse(const std::vector<int>& arr){
    for(int i{static_cast<int>(arr.size())-1}; i>=0; i--){
        std::cout<<arr[i]<<'\t';
    }
}



void range_based_loop(const std::vector<std::string>& arr){
    //Is a good practice pasing the vectors by address

    
    //Its a good practice using TYPE DEDUCTION in range-based loops (foreach)
    // std::vector<std::string>  words {"One", "Two", "Three"};
    
    std::cout<<"#########################\n";

    // for(auto word: arr){
    //     std::cout<<"Element: "<<word<<'\n';
    //     std::cout<<"Address: "<<&word<<'\n';
    // }
    
    // std::cout<<'\n';
    
    /**
     * The problem with the range based loop is that we are copying each value of the 
     * vector word (strings) in the variable word, and std::strings are not primitive 
     * types, so they are expensive to copy. We would like to use references. 
     */
    
    
    
    // In this case word is now a reference, so we are actually using each elment not a copy
    for(auto& word: arr){
        std::cout<<"Element: "<<word<<'\n';
        std::cout<<"Address: "<<&word<<'\n';
    }

}

void inverse_range_based_loo(const std::vector<std::string>& array){

    // auto rv = array | std::views::reverse;

    for(const auto& word: std::views::reverse(array)){
        std::cout<<"The word is :"<<word<<'\n';
    }
    //In order to do it in reverse, we can use std::views::reverse(words))
}   


void std_vector::practicing(){

    std::vector<std::string>  words {"One", "Two", "Three"};
    
    std::cout<<"Element: "<<words.at(0)<<'\n';
    std::cout<<"Address: "<<&words.at(0)<<'\n'; 

    std::cout<<"Element: "<<words.at(1)<<'\n';
    std::cout<<"Address: "<<&words.at(1)<<'\n'; 

    std::cout<<"Element: "<<words.at(2)<<'\n';
    std::cout<<"Address: "<<&words.at(2)<<'\n'; 

    range_based_loop(words);

    // inverse_range_based_loo(words);

    // std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    // for(int num: fibonacci){
    //     std::cout<<num<<' ';
    // }

    // std::cout<<'\n';

}

//Just to show something 
void std_vector::showingSizeNomProblem(){
    //Es importante notar que el size() es una desafortunada eleccion de nomenclatura
    //ya que se parece mucho al operador sizeof(), el cual se refiere al numero de BYTES 
    //en memoria usados por un objeto

    // int int_x; 
    // float float_x; 
    // char char_x; 

    // std::cout<<"This is for show the sizeof operator\n"; 
    // std::cout<<"Int bytes size "<<sizeof(int_x)<<'\n';
    // std::cout<<"Float bytes size "<<sizeof(float_x)<<'\n';
    // std::cout<<"Char bytes size "<<sizeof(char_x)<<'\n';

    std::vector<int> vec01{5}; //This is alsso a ne elment
    std::cout<<"Interpreted as a initializer list, matches list constructor with Size: "<<vec01.size()<<" First element: "<<vec01[0]<<'\n';
    std::vector<int> vec02({5});//--> This is a std vector wuth one element and is 5 
    std::cout<<"Interpreted as a initializer list, matches list constructor with Size: "<<vec02.size()<<" First element: "<<vec02[0]<<'\n';
    std::vector<int> vec03 = {5};
    std::cout<<"Interpreted as a initializer list, matches list constructor with Size: "<<vec03.size()<<" First element: "<<vec03[0]<<'\n';


    // std::vector<int> vec (5);
    // vec[0]=1; 

    // for(size_t i=0; i<std::size(vec); i++){
    //     std::cout<<vec[i]<<'\n';
    // }
}





//Exercises 


void std_vector::ex_1(){

    std::vector<int> numbers (3); 
    std::cout<<"Enter 3 integers"<<'\n';
    std::cin>>numbers[0]>>numbers[1]>>numbers[2];
    int sum{};
    int product{1};
    for(size_t i=0; i < numbers.size(); i++){
        sum+= numbers[i];
        product*= numbers[i];
    }   
    std::cout<<"The sum is: "<<sum<<'\n';
    std::cout<<"The prodcut is: "<<product<<'\n';

}

void std_vector::ex_2(){

}
