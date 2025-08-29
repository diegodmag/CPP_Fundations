#ifndef INTROCLASSES2_H
#define INTROCLASSES2_H

#include <iostream>

namespace intro_classes_2{

    class Monster{
         
    public:

        enum Type{ // Enumeration or Enumerated type 
            UNDEAD, 
            BEAST, 
            ABERRATION,
            UNKNOWN
        };

        Monster(std::string name="", Type type=UNKNOWN, int danger_level=0)
            : m_name{name}
            , m_type{type}
            , m_danger_level{danger_level}
            {
                std::cout<<"NEW MONSTER\n";
                std::cout<<"NAME: "<<m_name<<'\n';
                std::cout<<"DANGER LEVEL: "<<m_danger_level<<'\n';

            }

    
        ~Monster(){
            std::cout<<"MONSTER DESTROYED\n";
        }    

        Monster(const Monster& monster)//Copy Constructor
            : m_name{monster.m_name}
            , m_type{monster.m_type}
            , m_danger_level{monster.m_danger_level}
        {
            std::cout<<"MONSTER CLONED\n";
        }

        void ShowMonsterInformation(){
            std::cout<<"Showing monster ...\n";
            std::cout<<"NAME: "<<m_name<<'\n';
            std::cout<<"DANGER LEVEL: "<<m_danger_level<<'\n';
        }

    private:

        std::string m_name{}; 
        Type m_type{};
        int m_danger_level{};

    };


}


#endif