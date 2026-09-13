#include "Player.h"

Entity::Player::Player()
{
    std::cout<<"Player created at "<<m_position.x<<", "<<m_position.y<<'\n';
} 

Entity::Player::~Player()
{
    std::cout<<"Player destroyed"<<'\n';
}

void Entity::Player::SetPosition(Maths::Vector2D pos)
{
    m_position=pos; 
}

const Maths::Vector2D Entity::Player::GetPosition() const
{
    return m_position; 
} 