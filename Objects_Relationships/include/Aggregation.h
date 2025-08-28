#ifndef AGGREGATION_H
#define AGGREGATION_H

#include <iostream>
#include <functional> // In order to use reference_wrapper
#include <vector>

namespace aggregation_example{

  class Teacher
  {
    private:
        std::string m_name{};
    public:
        Teacher(std::string name)
            :m_name{name}
        {
            // std::cout<<"Teacher initialized"<<'\n';
        }

        ~Teacher(){
            // std::cout<<"Teacher destroyed"<<'\n';
        }

        const std::string& getName() const {return m_name;}
  };  

  class Department
  {
    private: 
        const Teacher& m_teacher; //Is a reference so the object must exist before the creation of Deparment

        //If we would like to have more than one teacher registred in the Department:
        std::vector<std::reference_wrapper<Teacher>> m_teachers {};

    public:
        Department(const Teacher& teacher)
            :m_teacher{teacher}
        {
            std::cout<<"Department initialized"<<'\n';
        }
        ~Department()
        {
            std::cout<<"Department destroyed"<<'\n';
        }

        void addTeacher(Teacher& teacher){
            m_teachers.emplace_back(teacher);
        }


        //  
        void printTeachers() {
            for(auto teacher: m_teachers){
                std::cout<< "Teacher in teachers "<< teacher.get().getName() << '\n';
            }
        }
  };


  void aggregation_example();

}


#endif