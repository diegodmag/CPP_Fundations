#include "IntroClasses.h"

// Cases with const structs 
void intro_classes::const_struct_example(){
    
    // Instancia de la struct Date 
    intro_classes::Date yesterday { 2020, 10, 13 };

    intro_classes::Date today { 2020, 10, 14 }; 

    today.day = 16; // Se accede a las member variables accessed usando el  member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)
    today.printYear(today);
    
    today.printYear(yesterday);

    // Const struct 
    // const Date tomorrow { 2020, 10, 15 };   
     
    // tomorrow.const_print(); // We only can use the function const_print because is const 
    // tomorrow.const_print();
        

    // Why this can happend ? 
    today.const_print();

}

intro_classes::Employee intro_classes::createEmployee(std::string_view name){
    Employee e{};   
	e.setName(name);
	return e;
}

void intro_classes::printEmployeeByValue(Employee emp){

    std::cout << "Printing employee information by value..."<<'\n';
    emp.fillInformation();
    std::cout << emp.getInformation();
}

void intro_classes::printEmployeeByReference(Employee& emp){

    std::cout << "Printing employee information by value..."<<'\n';
    emp.fillInformation();
    std::cout << emp.getInformation();
}

//Returning instances 
void intro_classes::cases_for_data_members_for_rvalue(){
    // Case 1: okay: use returned reference to member of rvalue class object in same expression
	// It will not persist after the statement 
    std::string val_employee {createEmployee("Frank").getName()};
    std::cout << val_employee << '\n';

    // Case 2: bad: save returned reference to member of rvalue class object for use later
	const std::string& ref { createEmployee("Garbo").getName() }; // reference becomes dangling when return value of createEmployee() is destroyed
	std::cout << ref << '\n'; // It will work for now 


    // Case 3: okay: copy referenced value to local variable for use later
	std::string val { createEmployee("Hans").getName() }; // makes copy of referenced member
	std::cout << val << '\n'; // okay: val is independent of referenced member

    // std::cout << ref << '\n'; // undefined behavior
    // std::cout << val << '\n'; // undefined behavior

}

// Basic of constructors 
void intro_classes::constructor_cases(){

    Employee pepe {}; //direct list initialization
    pepe.fillInformation();
    std::cout<< pepe.getInformation();

    // Employee juan ("Juan","",35);
    Employee juan {"Juan","", 30}; //direct list initialization
    juan.fillInformation();
    std::cout<< juan.getInformation();

    // pepe.fillInformation();
    // std::cout << pepe.getInformation() << '\n';

    //Temporary object 
    //Employee {"Pepe", "", 45};
    // printEmployeeByValue(Employee {"Don Gato", "", 45});

    // Que pasa aqui ? >> 
    // printEmployeeByReference(Employee {"Don Gato", "", 45});

    // Employee nobody {"Noboyd","", 20};
    // Employee unknown("Unknown","", 20);

    // nobody.fillInformation();
    // unknown.fillInformation();

    // std::cout << nobody.getInformation(); 
    // std::cout << unknown.getInformation();

}