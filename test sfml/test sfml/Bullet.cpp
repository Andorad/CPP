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
	//BulletObject.setPosition(BulletObject.getPosition() * bullet_speed);
};

void Bullet::SetBulletDirection(double bullet_dir)
{
	bullet_direction = bullet_dir;
}

void Bullet::SetBulletPosition(float posx, float posy)
{
	bullet_position.x = posx;
	bullet_position.y = posy;
}