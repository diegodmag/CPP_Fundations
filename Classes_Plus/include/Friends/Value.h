#pragma once

#include <iostream>

class Value
{
private:
    int m_value{};

public:
    // The word explicit is to stop the compiler doing implicit type castings and prevent bugs  
    explicit Value(int v) : m_value{v} {} // We tell thec compiler : "We don't want to cast an int to a Value implicit"
    
    /**
     * Si no tuviera la explicit, basicamente le decimos al compilar que un int puede transformarse 
     * automaticamente en un objeto de tipo Value de ser necesario 
     */
    // Value(int v) : m_value{v} {}

    /**
     * GOLDEN RULE 
     * Todo constructor que reciba un solo parámetro (o donde todos los parámetros 
     * extra tengan valores por defecto) debe ser marcado como explicit, 
     * a menos que realmente desees y planees una conversión de tipos automática
     */

    bool isEqualToMember(const Value &v) const;

    friend bool isEqualToNonmember(const Value& v1, const Value& v2);
};

bool Value::isEqualToMember(const Value& v) const
{
    return m_value == v.m_value;
}

/**
 * This is a non-member function 
 */
bool isEqualToNonmember(const Value& v1, const Value& v2)
{
    return v1.m_value == v2.m_value;
}