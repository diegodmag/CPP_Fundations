#include "IntroVector.h"
#include "Extra.h"
#include "Exercises.h"
#include "PassReturnVector.h"

int main(){

    std::vector<int> ids {std::vector<int>(5)}; 
    int counter=0; 
    for(auto& id: ids){
        id=counter; 
        counter++;     
    }
    
    
    std::vector<int> graveyard {};

    Exercises::vector_printer(ids); 
    
    // Exercises::card_dealer(ids);
    Exercises::discardHand(ids, graveyard); 
    Exercises::vector_printer(graveyard); 
    
    std::vector<int> damages = {55, 78, 22, 33}; 
    Exercises::damage_validator(damages, 5); 


}