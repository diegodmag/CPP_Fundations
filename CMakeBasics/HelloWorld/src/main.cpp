#include <iostream>

#include "Player.h"

int main() {
    // Maths::Vector2D vector{1.0f, 2.0f};
    // std::cout <<  "Vector2D: x "<<vector.x <<" y "<<vector.y<<'\n' << std::endl;
    Entity::Player p1{}; 
    p1.SetPosition(Maths::Vector2D {5.0f,5.0f});
    std::cout <<  "Player new pos: x "<<p1.GetPosition().x <<" y "<<p1.GetPosition().y<<'\n' << std::endl;
    
    return 0;
}