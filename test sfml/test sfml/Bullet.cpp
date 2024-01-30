#include "Bullet.h"
#include <iostream>

Bullet::Bullet(float xpos, float ypos)
{
	bulletShape.setRadius(10.f);
	bulletShape.setOrigin(10.f, 10.f);
	// bulletShape.setPosition()
	SetBulletPosition(sf::Vector2f(xpos, ypos));
	std::cout << "Bullet" << " x: " << GetBulletPosition().x << " | y: " << GetBulletPosition().y << std::endl;
	bulletShape.setFillColor(sf::Color::Magenta);
};
Bullet::~Bullet() = default;

void Bullet::BulletMove()
{
	 double dirX = cos(bullet_direction) * speed;
	 double dirY = sin(bullet_direction) * speed;
	 SetBulletPosition(sf::Vector2f(GetBulletPosition().x + dirX, GetBulletPosition().y + dirY));
}


void Bullet::SetBulletDirection(double bullet_dir)
{
	bullet_direction = bullet_dir;
}

void Bullet::SetBulletPosition(sf::Vector2f pos)
{
	bulletShape.setPosition(pos);
	
}