#include <iostream>
#include <ranges> // C++20
#include <string_view>
#include <vector>
#include <algorithm>

#ifndef INTROVECTOR_H
#define INTROVECTOR_H

namespace std_vector{

    struct Foo{
        //This is the needed way to define a vector of a specific size
        std::vector<int> attribute {std::vector<int>(5)};
        // This is a struct wich has a single member attribute called attribute which is a five length vector 
    };


    void intro_vector();

    void practicing();

    void showingSizeNomProblem();

    //Exercises

    void ex_1();

    void ex_2();

}



#endif