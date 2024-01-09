#include "Character.h"

Character::Character()
{
    health = 10;
};
Character::~Character() = default;

void Character::Die()
{
    if (health <= 0)
    {
        //delete CetObject;
    }
}