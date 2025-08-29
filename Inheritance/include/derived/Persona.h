#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

class Persona
{
private:
    /* data */
    int m_edad {}; 
    std::string m_nombre{}; 
    std::string m_apellido{};

public:
    Persona(int edad=0, std::string nombre="", std::string apellido="")
        : m_edad{edad}
        , m_nombre{nombre}
        , m_apellido{apellido}
    {
        std::cout<<"La persona con nombre :"<<m_nombre<<" "<<m_apellido<<" Y edad: "<<m_edad<<" ha sido creada\n";
    }
    ~Persona()
    {
        std::cout<<"La persona con nombre :"<<m_nombre<<" "<<m_apellido<<" Y edad: "<<m_edad<<" ha sido destruida\n";
    }

    void Saludar(){
        std::cout<<"Hola soy una persona!\n";
    }

};


#endif