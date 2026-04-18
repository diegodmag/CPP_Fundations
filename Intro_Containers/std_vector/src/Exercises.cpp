#include "Exercises.h"

#include <vector>
#include <ranges> // to use filter 

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
        damages.at(index); // Try to get the element 

        std::cout<<"The card at index "<<index<<" makes an attack, doing "<<damages.at(index)<<" of damage\n";    
    }
    catch(const std::out_of_range& e)
    {
        std::cerr<<"Not valid damage\n"; 
        std::cerr << e.what() << '\n';
    }
    
}

/// 4 

void Exercises::card_filter(std::vector<int>& hand){

    auto positives = [](int n){return n>0;}; 
    
    // Here, it is importanta to highlight (or note) that THERE IS NOT MEMORY ALLOCATIO when 
    // the view is created, the onlyPositiveAttacks object, only stores a reference to the 
    // initial vector and the filter 

    auto onlyPositiveAttacks = std::views::filter(hand, positives); 
    // Views -views- only execute the filter when someone tries to read the data 
    
    std::cout<<"Positives attacks detected\n"; 
    for(const auto& attack: onlyPositiveAttacks){
        std::cout<<"Attack: "<<attack<<'\n'; 
    }
    
}

/// 4.5 
void Exercises::selective_buffer(std::vector<int>& damages){

    //First, we stablish the lambdas 
    //
    // In lambdas the capture block ([])
    auto positives = [](int n){return n>0;};
    // 
    auto doubled = [](int n){return n*2;}; 

    auto onlyPositives = std::views::filter(damages, positives); 

    auto doublePositives = std::views::transform(onlyPositives, doubled); 

    std::cout<<"The followings are the positive numbers: \n"; 
    for(const auto& view : onlyPositives){
        std::cout<<view<<' '; 
    }
    std::cout<<"\n"; 
    std::cout<<"The followings are the double of those positives numbers: \n"; 
    for(const auto& view : doublePositives){
        std::cout<<view<<' '; 
    }
    std::cout<<"\n"; 
}

void Exercises::powerful_atcks_filter(std::vector<int>& atcks, int defense){
    
    // lambda
    auto filter = [defense](int n){return n>=defense;}; 
    // view 1 
    auto powerful_atcks = atcks | std::views::filter(filter) | std::views::reverse; 
     
    
    std::cout<<"The attacks that surpass the defense "<<defense<<" are...\n"; 
    for(const auto& atck: powerful_atcks){
        std::cout<<atck<<'\t'; 
    }   
    std::cout<<'\n'; 
}

void Exercises::filtering_cards(std::vector<int>& costs){

    // Only filter odd numbers 
    // 1 Create the lambda 
    auto odd = [](int n){return n%2 ==0;};
    
    // Sort them from greater to shorter 

    // Take only two elements 
    
    auto filtered_cards = costs | std::views::filter(odd) | std::views::reverse | std::views::take(2); 
    
    std::cout<<"The elements that achieve the requierements are ...\n";
    for(const auto& card: filtered_cards){
        std::cout<<"Card "<<card<<'\t'; 
    }
    std::cout<<'\n'; 
}