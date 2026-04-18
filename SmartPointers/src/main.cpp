#include "SmartPointer.h"
#include <iostream>


// WRONG EXAMPLE ABOUT STACK 
int* CreateArray(){
    int arr[5] {1,2,3,4,5}; // Este array fue declarado en el stack  
    return arr;
    // Cuando termina el ambito de la funcion, se libera l stack,
    // Que pasa con el array que iba a ser regresado ?  
}

// Considera la clase 
class Entity{
public:

    Entity(){
        std::cout<<"Created Entity!"<<std::endl; 
    }
    
    ~Entity(){
        std::cout<<"Destroy Entity!"<<std::endl;         
    }
};

// Cómo podemos hacer un puntero con ambito ? 
class ScopePtr{

private:
    Entity * m_Ptr; 
public: 
    ScopePtr(Entity * ptr)
        : m_Ptr{ptr}
        {}

    ~ScopePtr()
    {
        delete m_Ptr;
    }
};


int main(int arg, char* argv[]){

    // Ejemplo 1 
    {
        Entity e; // <--- Esto se creo en el stack, cuando deja el ambito
        // se libera  
    }

    // Ejemplo 2
    std::cout<<"---------\n"; 
    {
        Entity* e = new Entity(); // Se creo la entidad pero ..
        // Nunca se destruyo, entonces nunca libero los recursos que usó
        // Dato importante, es maso menos equivalente a 
        
        // Entity* e = (Entity*)malloc(sizeof(Entity)); 
        // La diferencia de new y malloc es que new, llama al constructor 
        // Y malloc solo reserva memoria para un objeto de tipo entity
    }

    // Ejemplo 3
    std::cout<<"---------\n"; 
    {
        // El objeto sptr se asigna en el stack 
        // Mientras que su objeto new Entiy en el heap 
        // Sin embargo en el destructor de sptr se libera el objeto entity
        ScopePtr sptr {new Entity()};
    }

    // SmartPointer p {}; 

    // SmartPointer::DoSomeLogic(); 
    
    // return 0; 
}