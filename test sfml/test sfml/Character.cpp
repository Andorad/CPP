#include "Character.h"

Character::Character()
{
    shape.setPosition(0, 0);
};

void Character::Draw(sf::RenderWindow& window) 
{
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOutlineColor(sf::Color::Red);
    window.draw(shape);
}

void Character::TakeDamage() 
{ 
    SetHealth(GetHealth() - 1);
    shape.setOutlineThickness((GetMaxHealth() - GetHealth()) * -50 / GetMaxHealth());
}