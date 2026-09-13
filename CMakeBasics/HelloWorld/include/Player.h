#include <iostream>

#include "Vector2D.h"

namespace Entity
{
    class Player
    {
        public:
        Player();

        ~Player();

        void SetPosition(Maths::Vector2D pos);

        const Maths::Vector2D GetPosition() const; 

        private: 
        Maths::Vector2D m_position{};
    };
}