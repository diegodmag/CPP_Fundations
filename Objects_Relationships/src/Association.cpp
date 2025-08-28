#include "Association.h"


    void association_example::Doctor::addPatient(Patient& patient){
    
        // Our doctor will add this patient
        m_patient.push_back(patient);
    
        // and the patient will also add this doctor
        patient.addDoctor(*this);
    }
    
    

    
    void association_example::association_ejectuion_example(){
        	// Create a Patient outside the scope of the Doctor
        Patient dave{ "Dave" };
        Patient frank{ "Frank" };
        Patient betsy{ "Betsy" };

        Doctor james{ "James" };
        Doctor scott{ "Scott" };

        james.addPatient(dave);

        scott.addPatient(dave);
        scott.addPatient(betsy);

        std::cout << james << '\n';
        std::cout << scott << '\n';
        std::cout << dave << '\n';
        std::cout << frank << '\n';
        std::cout << betsy << '\n';
    }

