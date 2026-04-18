#include <iostream>
#include "OpOverload.h"

int op_overloading::add(int x, int y){
    return x+y; 
}

double op_overloading::add(double x, double y){
    return x+y; 
}

void op_overloading::FunctionOverloadingExample(){
    std::cout<<"Add with int: "<<add(5,6)<<'\n';
    std::cout<<"Add with doubles: "<<add(5.0, 6.9)<<'\n';
}


// This is a member function 
op_overloading::Cents op_overloading::Cents::operator+(Cents& c2) const{
    return Cents{m_cents+c2.getCents()};
}
// Another possible operator overloading for member functions 
void op_overloading::Cents::operator+(Cents& c2){
    m_cents+=c2.getCents();
}

void op_overloading::Cents::operator-(Cents& c2){
    m_cents-=c2.getCents();
}

// It returns a object of type Cents and receives two cents 
// This is not a member function
op_overloading::Cents op_overloading::operator+(const Cents& c1, const Cents& c2){
    return Cents{c1.getCents()+c2.getCents()};
}


void op_overloading::OperatorAsMemberFunction(){

    Cents c1 {50}; 
    Cents c2 {33};
    
    std::cout<<"C1: "<<c1.getCents()<<'\n'; 
    std::cout<<"C2: "<<c2.getCents()<<'\n';
    
    // First version
    // Cents c3 {c1+c2};
    // std::cout<<"C1 + C2: "<<c3.getCents()<<'\n';
    // Second version
    c1+c2; 
    std::cout<<"C1 + C2: "<<c1.getCents()<<'\n';
}
