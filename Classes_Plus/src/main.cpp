#include <iostream>

// To work with pairs
#include <utility>

#include "Static/Son.h"

int main(int arg, char *argv[])
{

    Son s_1 {}; 
    Son s_2 {}; 
    Son s_3 {}; 
    Son s_4 {};
    
    
    std::cout<<"The current ID_Generator's value is :"<<s_1.getIDGenerator()<<'\n';

}