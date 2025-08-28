#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <string_view>
#include <vector>


namespace association_example{
    /**
     * Since Doctor and Patient have a circular dependency, 
     * we're going to forward declare Patient
     */
    class Patient; // <-- foreward declaration cause circular use 
    
    class Doctor
    {
    private:
        std::string m_name{};
        std::vector<std::reference_wrapper<const Patient>> m_patient{};

    public:
        Doctor(std::string_view name) :
            m_name{ name }
        {
        }

        void addPatient(Patient& patient);

        // We'll implement this function below Patient since we need Patient to be defined at that point
        friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

        const std::string& getName() const { return m_name; }
    };

    class Patient
    {
    private:
        std::string m_name{};
        std::vector<std::reference_wrapper<const Doctor>> m_doctor{}; // so that we can use it here

        // We're going to make addDoctor private because we don't want the public to use it.
        // They should use Doctor::addPatient() instead, which is publicly exposed
        void addDoctor(const Doctor& doctor)
        {
            m_doctor.push_back(doctor);
        }

    public:
        Patient(std::string_view name)
            : m_name{ name }
        {
        }

        // We'll implement this function below to parallel operator<<(std::ostream&, const Doctor&)
        friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

        const std::string& getName() const { return m_name; }

        // We'll friend Doctor::addPatient() so it can access the private function Patient::addDoctor()
        friend void Doctor::addPatient(Patient& patient);
    };

    std::ostream& operator<<(std::ostream& out, const association_example::Doctor& doctor){
        if (doctor.m_patient.empty())
        {
            out << doctor.m_name << " has no patients right now";
            return out;
        }
    
        out << doctor.m_name << " is seeing patients: ";
        for (const auto& patient : doctor.m_patient)
            out << patient.get().getName() << ' ';
    
        return out;
    }

    std::ostream& operator<<(std::ostream& out, const Patient& patient)
    {
        if (patient.m_doctor.empty())
        {
            out << patient.getName() << " has no doctors right now";
            return out;
        }

        out << patient.m_name << " is seeing doctors: ";
        for (const auto& doctor : patient.m_doctor)
            out << doctor.get().getName() << ' ';

        return out;
    }



    void association_ejectuion_example();
}

#endif