#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person 
{

public: 

    double m_hourlySalary{};
    long m_employeeID{};


    Employee(double hourlySalary = 0.0, long employeeID = 0.0f)
        : m_hourlySalary{hourlySalary}, m_employeeID{employeeID}
    {
    }

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }

};


#endif