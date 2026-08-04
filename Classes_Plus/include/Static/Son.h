#ifndef SON_H
#define SON_H

#include <iostream>

class Son
{
public:
    Son() : m_id{s_ID_generator++}
    {
        std::cout << "Son's ID: " << m_id << " was created\n ";
    }

    ~Son()
    {
    }

    int getID() const { return m_id; }
    
    // But this is a non-static member function, consequently, it needs an instance of the class in order to be called
    // int getIDGenerator() const { return s_ID_generator; }
    // Nonetheless, we can transform it into a static member function and we will no need an class' instance 
    
    static int getIDGenerator() {return s_ID_generator;}
    /**
     * Another interesting thing is that static member function do not have acces to the poniter this 
     * because they are not attached to any instance. 
     */

    
private:
    int m_id{};

    /**
     * static members are shared among class instances
     * constexpr variables and functions are in compile time
     */
    // static constexpr int s_mother{5}; // Sons instances can share mother memebers so, it could be an static member

    // We can also use inline in order to initialize static members
    static inline int s_ID_generator{0};


};

#endif