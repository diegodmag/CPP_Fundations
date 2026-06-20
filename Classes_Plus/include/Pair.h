#ifndef PAIR_H
#define PAIR_H

namespace templates
{
    template <typename T>
    class Pair
    {
    public:
        Pair(const T &first, const T &second)
            : m_first{first}, m_second{second}
        {
        }

        bool isEqual(const Pair<T> &other);

    private:
        T m_first;
        T m_second;
    };

    template <typename T>
    bool Pair<T>::isEqual(const Pair<T> &other)
    {
        return m_first == other.m_first && m_second == other.m_second;
    }

};


#endif