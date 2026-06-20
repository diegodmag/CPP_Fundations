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
    
    int getIDGenerator() const { return s_ID_generator; }

private:
    // int m_age{};
    /**
     * static members are shared among class instances
     * constexpr variables and functions are in compile time
     */
    // static constexpr int s_mother{5}; // Sons instances can share mother memebers so, it could be an static member

    // We can also use inline in order to initialize static members
    int m_id{};
    static inline int s_ID_generator{0};
};

#endif