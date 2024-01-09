#include "basicEnemy.h"

void BasicEnemy::Attack()
{
    SetCanAttack(false);
    //target.TakeDamage();

    //A mettre dans le main
    //sf::Clock cooldown;
    //
    //if(cooldown.getElapsedTime().asMilliseconds() < GetAttackSpeed())
    //{
    //    SetCanAttack(true);
    //}
    //else
    //{
    //    SetCanAttack(false);
    //}
}

void BasicEnemy::Move()
{
	int targetPosX = 0;
	int targetPosY = 0;

    float dx = targetPosX - GetPosition().x;
    float dy = targetPosX - GetPosition().y;

    float distance = sqrt(dx * dx + dy * dy);

    if (distance > GetAttackRange())
    {
        float moveX = dx / distance * GetSpeed();
        float moveY = dy / distance * GetSpeed();

        SetPosition(sf::Vector2f(moveX, moveY));
    }
    else
    {
         SetCanAttack(true);
    }
}