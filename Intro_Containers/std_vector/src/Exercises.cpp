#include "Exercises.h"

#include <vector>

//This is a template function 
template<typename T>
bool IsValueInArray(const std::vector<T>& arr, const T& value){
    for(const auto& current: arr){
        if(current == value){
            return true; 
        }
    }

    return false; 
}


void Exercises::ex_1(){

    std::vector<std::string> names {{"Alex", "Betty", "Caroline", "Dave",
        "Emily", "Fred", "Greg", "Holly"}};

    std::string name {"Juanito"};

    std::cout<< IsValueInArray(names, names[names.size()-1]) <<'\n';
    std::cout<< IsValueInArray(names, name ) <<'\n';

}

void Exercises::vector_printer(std::vector<int>& vector){
    std::cout<<"Printing vector >>>> \n";
    for(auto& element: vector){
        std::cout<<element<<'\n'; 
    }
    std::cout<<"                >>>> \n";
}


void Exercises::card_dealer(std::vector<int>& ids){

    //Printing value and addres of each value 
    std::cout<<"Before the change\n"; 
    for(auto& id : ids){
        std::cout<<"ID: "<<id<<" Memory Address: "<<&id<<'\n'; 
    }
    
    std::cout<<"After the change\n"; 
    for(auto& id : ids){
        id+=10; 
        std::cout<<"ID: "<<id<<" Memory Address: "<<&id<<'\n'; 
    }
    
}

void Exercises::discardHand(std::vector<int>& hand, std::vector<int> graveyard){
    for (size_t i = 0; i < std::ssize(hand); i++)
    {
        graveyard.push_back(std::move(hand[i])); 
        /* code */
    }
    
}

void Exercises::damage_validator(std::vector<int>& damages, int index){
    try
    {
        damages.at(index); 

        std::cout<<"The card at index "<<index<<" makes an attack, doing "<<damages.at(index)<<" of damage\n";    
    }
    catch(const std::out_of_range& e)
    {
        std::cerr<<"Not valid damage\n"; 
        std::cerr << e.what() << '\n';
    }
    
}