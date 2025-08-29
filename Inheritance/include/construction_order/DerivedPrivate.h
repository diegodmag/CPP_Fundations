#ifndef DERIVEDPRIVATE_H 
#define DERIVEDPRIVATE_H 

#include "Base.h"

class DerivedPrivate : public Base  
{
private:
    double m_cost {};

public:
    DerivedPrivate(double cost=0.0, int id=0)
        : Base{id}
        , m_cost{cost}
    {
        std::cout<<"Derived constructed\n"; 
    }

    double getCost() const { return m_cost;}
};

#endif 