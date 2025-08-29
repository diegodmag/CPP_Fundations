#ifndef BASE_H
#define BASE_H 

#include <iostream>

class Base
{
    public: 

    int m_id{};

    Base(int id=0)
        : m_id{id}
    {
        std::cout<<"Base constructed\n"; 
    }   

    int getID() const { return m_id;}

};

#endif