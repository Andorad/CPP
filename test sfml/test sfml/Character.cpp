#include "Character.h"

Character::Character()
{

};

//bool Character::Collision(const sf::CircleShape& other)
//{
//    // Calculer la distance entre les centres des cercles
//    sf::Vector2f center1 = GetShape().getPosition() + sf::Vector2f(GetShape().getRadius(), GetShape().getRadius());
//    sf::Vector2f center2 = other.getPosition() + sf::Vector2f(other.getRadius(), other.getRadius());
//
//    float distance = std::sqrt(std::pow(center2.x - center1.x, 2) + std::pow(center2.y - center1.y, 2));
//
//    // Vérifier si la distance est inférieure à la somme des rayons
//    return distance < GetShape().getRadius() + other.getRadius();
//}

void Character::Draw(sf::RenderWindow& window) 
{
    //On draw notre Character
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOutlineColor(sf::Color::Red);
    window.draw(shape);
}

void Character::TakeDamage() 
{ 
    //On prend des dégâts et on sesert de l'outline pour indiquer les pvs
    SetHealth(GetHealth() - 1);
    shape.setOutlineThickness((GetMaxHealth() - GetHealth()) * -50 / GetMaxHealth());
}