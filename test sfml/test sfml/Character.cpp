#include "Character.h"

Character::Character()
{

};

void Character::Draw(sf::RenderWindow& window) 
{
    //On draw notre Character
    m_shape.setRadius(m_radius);
    m_shape.setFillColor(m_color);
    m_shape.setOutlineColor(sf::Color::Red);
    window.draw(m_shape);
}

void Character::TakeDamage() 
{ 
    //On prend des dégâts et on sesert de l'outline pour indiquer les pvs
    m_health -= 2;
    m_shape.setOutlineThickness((m_maxHealth - m_health) * -50 / m_maxHealth);
}