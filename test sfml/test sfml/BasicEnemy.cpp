#include "basicEnemy.h"

BasicEnemy::BasicEnemy()
{
    float m_radius = 50;
    float m_attackRange = 50;
    float m_speed = 1.f;
    bool m_canAttack = false;
    int m_maxHealth = 2;
    int m_health = m_maxHealth;
    sf::CircleShape m_shape;
    sf::Color m_color = sf::Color::Blue;
    int m_damages = 1;
    float m_attackSpeed = 1;
};

void BasicEnemy::Attack()
{
    m_canAttack = false;
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
    //On calcule la direction du mouvement
    float dx = targetPosX - m_shape.getPosition().x;
    float dy = targetPosY - m_shape.getPosition().y;

    float distance = sqrt(dx * dx + dy * dy);

    //Si on est trop loin
    if (distance >= m_attackRange + m_radius)
    {
        dx /= (float)distance;
        dy /= (float)distance;

        //On avance d'un pas dans la bonne direction
        m_shape.setPosition(sf::Vector2f(m_shape.getPosition().x + (dx * m_speed), m_shape.getPosition().y + dy * m_speed));
    }
    //Si on est assez proche
    else
    {
            //On attaque le joueur
        m_canAttack = true;
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
        m_shape.setPosition(sf::Vector2f(rand() % sizeX, 0 - m_radius));
        break;
    case 1:
        //On spawn en bas de l'écran
        m_shape.setPosition(sf::Vector2f(rand() % sizeX, sizeY + m_radius));
        break;
    case 2:
        //On spawn à droite de l'écran
        m_shape.setPosition(sf::Vector2f(sizeX + m_radius, rand() % sizeY));
        break;
    case 3:
        //On spawn à gauche de l'écran
        m_shape.setPosition(sf::Vector2f(0 - m_radius, rand() % sizeY));
        break;
    default:
        m_shape.setPosition(sf::Vector2f(0, 0));
    }

    m_shape.setOrigin(m_radius, m_radius);
}