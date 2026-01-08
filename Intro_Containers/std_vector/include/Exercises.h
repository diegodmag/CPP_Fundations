#ifndef EXCERCISES_H
#define EXCERCISES_H

#include <iostream>
#include <vector>

namespace Exercises{
    
    void ex_1();
    
    // Vector Printer 
    void vector_printer(std::vector<int>& vector); 

    // 1 Card dealer 
    void card_dealer(std::vector<int>& ids);  

    // 2
    void discardHand(std::vector<int>& hand, std::vector<int> graveyard);

    // 3 Validación de Daño (Bound Checking con .at())
    void damage_validator(std::vector<int>& damages, int index); 
};

#endif