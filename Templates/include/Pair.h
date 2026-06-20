#ifndef PAIR_H
#define PAIR_H

namespace templates
{
    template <typename T>
    /**
     * Note that the class is named Pair and not Pair<T>
     * So, within the scope of a class, the unqualified name of the class 
     * is called an injected class name. In a class template, the injected 
     * class name serves as shorthand for the fully templated name
     * 
     * Because Pair IS THE INJECTED CLASS NAME of Pair<T>, within the scope of our
     * Pair<T> class template, any use of Pair will be treated as if we had written 
     * Pair<T>.
     */
    class Pair
    {
    public:
        /**
         * When we define a MEMBER FUNCTION inside the class definition,
         * the template parameter declaration belonging to the class applies
         */
        Pair(const T &first, const T &second)
            : m_first{first}, m_second{second}
        {
        }

        /**
         * When we define a memeber function inside the class definition
         * we don't need to provide a TEMPLATE PARAMETER DECLARATION
         */
        bool isEqual(const Pair<T> &other);

    private:
        T m_first;
        T m_second;
    };

    // Out side the class
    /**
     * When we define a member function outside the class definition,
     * we need to ressuply a template parameter declaration
     */
    template <typename T>
    bool Pair<T>::isEqual(const Pair<T> &other)
    {
        return m_first == other.m_first && m_second == other.m_second;
    }

};

/**
 * GOLDEN RULE:
 * All member function or class using templates must have its definition and
 * implementation completely visible in the header
 */

#endif