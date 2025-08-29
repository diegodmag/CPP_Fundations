#ifndef JUGADOR_H
#define JUGADOR_H

#include "derived/Persona.h"

class Jugador : public Persona
{
private:

    long m_idJugador {};
    std::string m_nickname {};

public:

    Jugador(int edad, std::string nombre, std::string apellido, int  id, std::string nickname)
        : Persona{edad, nombre, apellido}
        , m_idJugador{id}
        , m_nickname{nickname}
    {
        std::cout<<"El jugador con id: "<<m_idJugador<<" Y Nickname: "<<m_nickname<<" ha sido creado\n";
    }

    ~Jugador()
    {
        std::cout<<"El jugador con id: "<<m_idJugador<<" Y Nickname: "<<m_nickname<<" ha sido destruido\n";
    }

    //Ejemplo de cambio de comportamiento 1 
    void Saludar(){
        Persona::Saludar(); //Extending behavior 
        std::cout<<"Hola soy un jugador!\n";
    }

};


#endif 