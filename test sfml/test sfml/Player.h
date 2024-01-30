#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>

class Player : public Character
{
public :
	Player();
	~Player() = default;
	void isAttacking(sf::Event Game_event, int ammo);
	void Attack() override;
	bool GetIsFiring();
	void isMoving(sf::Event Game_event);
	void Move(int posX, int posY) override;
	void Spawn(int sizeX, int sizeY);
private :
	bool keypressedZ;
	bool keypressedS;
	bool keypressedQ;
	bool keypressedD;

	bool isFiring;
	float rate;
};