#ifndef INTROCLASSES_H
#define INTROCLASSES_H

#include <iostream>

namespace intro_classes{

    // Introduction with structs 

    /**
     * REMINDER: Because a class is a program-defined data type, it must be defined before it can be used.
     */

    struct Date
    {
        int year {};
        int month {};
        int day {};

        void print() // defines a member function named print
        {
            std::cout << year << '/' << month << '/' << day << '\n';
        }

        void const_print()   // defines a member function named print
        {
            std::cout << year << '/' << month << '/' << day << '\n';
        }

        void printYear(const Date& date ){
            std::cout << "The year is :" << date.year << '\n';
        }

        void incrementYear() {
            year+=1; 
        }

        // Compilation erro 
        // void const_incremment_Year() const 
        // {
        //     year+=1; 
        // }
    };


    void const_struct_example();

    class Employee 
    {
        std::string m_name{};
        std::string m_information {};
        int m_age {};

    public:
        Employee() //Empty default constructor
        {
                //Takes the default type value for each argument
        }

        
        Employee(std::string name, std::string info, int age):
        m_name{name}
        ,m_information{info} 
        ,m_age{age}
        {
   
        } 

        // Employee(std::string name="", std::string info="", int age=0):
        //     m_name{name}
        //    ,m_information{info}
        //    ,m_age{age}
        // {
                //Default constructor with specific default values 
        // }
            
        void setName(std::string_view name) { m_name = name; }
        void setAge(int age){m_age=age;}
        
        void fillInformation(){
            m_information += "Name: "+ m_name + " Age: " + std::to_string(m_age) + '\n' ;
        }
        const std::string& getName() const { return m_name; } //  getter returns by const reference
        
        const std::string& getInformation() const {return m_information;} 

    };


    Employee createEmployee(std::string_view name);

    
    void cases_for_data_members_for_rvalue();

    void constructor_cases();

    void printEmployeeByValue(Employee emp);

    void printEmployeeByReference(Employee& emp);

};

#endif