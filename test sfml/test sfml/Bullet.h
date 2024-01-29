#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	double bullet_direction;
	bool isHit;
	sf::Vector2f bullet_position;
	sf::CircleShape BulletObject;
public:
	Bullet(float radius,float xpos, float ypos);
	~Bullet();
	sf::CircleShape getBulletObject() { return BulletObject; }
	double GetBulletDirection() { return bullet_direction; }
	sf::Vector2f  GetBulletPosition() { return bullet_position; }

	void SetBulletDirection(double bullet_direction);
	void SetBulletPosition(float posx, float posy);
	void Bullet_fired();

};