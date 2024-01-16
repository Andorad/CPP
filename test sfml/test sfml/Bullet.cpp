#include "Bullet.h"

Bullet::Bullet(float radius, float xpos, float ypos)
{
	BulletObject.setRadius(radius);
	BulletObject.setPosition(xpos, ypos);
	BulletObject.setFillColor(sf::Color::White);
};
Bullet::~Bullet() = default;

void Bullet::Bullet_fired()
{
	BulletObject.setPosition(BulletObject.getPosition() * bullet_speed);
};