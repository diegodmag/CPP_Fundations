#include "Extra.h"
#include <limits>

double additional_functions::getDouble(){
    while(true){
        std::cout<<"Enter a decimal number: ";
        double x{};
        std::cin>>x; 

        // You shoulld check for a failed extraction here 

        //If there are still remaining characters 
        if(hasUnextractedInput()){  
            //Ignore the buffer 
            igoreLine();
            continue; 
        }

        return x;
    }
}

char additional_functions::getOperator(){
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op{};
        std::cin>>op;
        
        igoreLine();
        switch (op)
        {
            case '+':
            case '-':
            case '*': 
            case '/':
                return op;
            default:
                std::cout<<"Oops, that input is invalid, please try again.\n";
                break;
        }
        
        return op; 
        /* code */
    }
    
}

void additional_functions::printResult(double x, char operation, double y ){
    std::cout<< x << ' ' << operation << ' ' << y << " is "; 

    switch (operation)
    {
    case '+':
        std::cout<<x+y<<'\n';
        break;
    case '-':
        std::cout<<x-y<<'\n';
        break;
    case '*': 
        std::cout<<x*y<<'\n';
        break; 
    case '/':
        std::cout<<x/y<<'\n';
    default:
        break;
    }
}   

void additional_functions::igoreLine(){
    // returns the largest value that can be stored in a variable of type std::streamsize
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


/**
 * std::cin.eof()
 * std::cin.peek()
 */
bool additional_functions::hasUnextractedInput(){

    return !std::cin.eof() && std::cin.peek()!='\n';

}

void additional_functions::handlingInvalidInput(){

    double x {getDouble()};
    char op{getOperator()};
    double y {getDouble()};
    printResult(x,op,y);

}