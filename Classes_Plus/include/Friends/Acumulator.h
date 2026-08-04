#ifndef ACUMULATOR_H
#define ACUMULATOR_H

#include "iostream"

class Acumulator
{

public:
    void Add(int value) { m_value += value; }

    /**
     * Now, the class Acumulator recognizes print as a friend and therefore
     * the non-member function can access to all members of Acumulator
     */
    friend void print(const Acumulator& acumulator);

private:
    int m_value{0};
};


// Outsider function 
void print(const Acumulator& acumulator)
{
    std::cout<<"Acumulator value "<<acumulator.m_value<<'\n';
}

#endif
