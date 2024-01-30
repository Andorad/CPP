#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	double bullet_direction;
	bool isHit;
	float speed = 10.f;
	sf::CircleShape bulletShape;
public:
	Bullet(float xpos, float ypos);
	~Bullet();
	sf::CircleShape getBulletObject() { return bulletShape; }
	void BulletMove();


	//double GetBulletDirectionX() { return bullet_direction_x; }
	//double GetBulletDirectionY() { return bullet_direction_y; }
	sf::Vector2f  GetBulletPosition() { return bulletShape.getPosition(); }

	void SetBulletDirection(double bullet_dir);
	void SetBulletPosition(sf::Vector2f pos);

};