#include "basicEnemy.h"

BasicEnemy::BasicEnemy()
{

};

//void BasicEnemy::Attack()
//{
//    SetCanAttack(false);
//    ////target.TakeDamage();
//
//    //A mettre dans le main
//    sf::Clock cooldown;
//    
//    if(cooldown.getElapsedTime().asMilliseconds() < GetAttackSpeed())
//    {
//        SetCanAttack(true);
//    }
//    else
//    {
//        SetCanAttack(false);
//    }
//}
//
void BasicEnemy::Move()
{
    SetSpeed(1.f);

	int targetPosX = 100;
	int targetPosY = 100;

    float dx = targetPosX - GetPosition().x;
    float dy = targetPosY - GetPosition().y;

    float distance = sqrt(dx * dx + dy * dy);

    if (distance >= GetAttackRange())
    {
        dx /= (float)distance;
        dy /= (float)distance;

        SetPosition(sf::Vector2f(GetPosition().x + (dx * GetSpeed()), GetPosition().y + dy * GetSpeed()));
    }
    else
    {
            SetCanAttack(true);
    }
}