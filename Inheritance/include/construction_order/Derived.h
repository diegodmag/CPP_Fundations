#ifndef DERIVED_H 
#define DERIVED_H 

#include "Base.h"

class Derived : public Base  
{
public:
    double m_cost {};


    Derived(double cost=0.0)
        : m_cost{cost} 
    {
        std::cout<<"Derived constructed\n"; 
    }

    double getCost() const { return m_cost;}
};

#endif 