#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	float bullet_speed;
	bool isHit;
	sf::CircleShape BulletObject;
public:
	Bullet(float radius,float xpos, float ypos);
	~Bullet();
	sf::CircleShape getBulletObject() { return BulletObject; }

	void Bullet_fired();
};