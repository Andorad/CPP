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

void BasicEnemy::Move(int targetPosX, int targetPosY)
{
    SetSpeed(1.f);


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

void BasicEnemy::Spawn(int sizeX, int sizeY)
{
    int spawnPosXMax = sizeX;
    int spawnPosYMax = sizeY;

    int rdmNb = rand() % 4;

    switch (rdmNb) {
    case 0:
        //On spawn en haut de l'écran
        SetPosition(sf::Vector2f(rand() % spawnPosXMax, 0 - GetRadius()));
        break;
    case 1:
        //On spawn en bas de l'écran
        SetPosition(sf::Vector2f(rand() % spawnPosXMax, spawnPosYMax + GetRadius()));
        break;
    case 2:
        //On spawn à droite de l'écran
        SetPosition(sf::Vector2f(spawnPosXMax + GetRadius(), rand() % spawnPosYMax));
        break;
    case 3:
        //On spawn à gauche de l'écran
        SetPosition(sf::Vector2f(0 - GetRadius(), rand() % spawnPosYMax));
        break;
    default:
        SetPosition(sf::Vector2f(0, 0));
    }
}