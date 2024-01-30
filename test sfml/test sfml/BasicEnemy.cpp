#include "basicEnemy.h"

BasicEnemy::BasicEnemy() 
{

};

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

void BasicEnemy::Move(int targetPosX, int targetPosY)
{
    SetSpeed(1.f);

    //On calcule la direction du mouvement
    float dx = targetPosX - GetPosition().x;
    float dy = targetPosY - GetPosition().y;

    float distance = sqrt(dx * dx + dy * dy);

    //Si on est trop loin
    if (distance >= GetAttackRange() + GetRadius())
    {
        dx /= (float)distance;
        dy /= (float)distance;

        //On avance d'un pas dans la bonne direction
        SetPosition(sf::Vector2f(GetPosition().x + (dx * GetSpeed()), GetPosition().y + dy * GetSpeed()));
    }
    //Si on est assez proche
    else
    {
            //On attaque le joueur
            SetCanAttack(true);
            Attack();
    }
}

void BasicEnemy::Spawn(int sizeX, int sizeY)
{
    //On choisi aléatoirement le côté de l'écran sur lequel on spawn
    int rdmNb = rand() % 4;

    switch (rdmNb) {
    case 0:
        //On spawn en haut de l'écran
        SetPosition(sf::Vector2f(rand() % sizeX, 0 - GetRadius()));
        break;
    case 1:
        //On spawn en bas de l'écran
        SetPosition(sf::Vector2f(rand() % sizeX, sizeY + GetRadius()));
        break;
    case 2:
        //On spawn à droite de l'écran
        SetPosition(sf::Vector2f(sizeX + GetRadius(), rand() % sizeY));
        break;
    case 3:
        //On spawn à gauche de l'écran
        SetPosition(sf::Vector2f(0 - GetRadius(), rand() % sizeY));
        break;
    default:
        SetPosition(sf::Vector2f(0, 0));
    }
}