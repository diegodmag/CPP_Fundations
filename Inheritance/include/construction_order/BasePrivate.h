#ifndef BASEPRIVATE_H
#define BASEPRIVATE_H

#include <iostream>

class BasePrivate
{

private:
    int m_id{};
public: 
    BasePrivate(int id=0)
        : m_id{id}
    {
        std::cout<<"Base constructed\n"; 
    }   

    int getID() const { return m_id;}

};

#endif