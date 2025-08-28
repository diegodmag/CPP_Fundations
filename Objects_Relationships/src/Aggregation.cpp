#include "Aggregation.h"

void aggregation_example::aggregation_example(){
    
    Teacher bob{"Bob"}; // Teacher is the part(member) whose lifecycle doesn't depend on department 
    //Also, bob could be part of another department 

    Teacher piter{"Piter"};
    Teacher otto{"Otto"};
    {
        Department department {bob}; //<- Departmente would be the object(class)

        department.addTeacher(piter);
        department.addTeacher(otto);

        department.printTeachers();
    }   // department goes out of scope here and is desroyed 

    // bob still exists here, but the department doesn't 

    std::cout<< bob.getName() << '\n';
}