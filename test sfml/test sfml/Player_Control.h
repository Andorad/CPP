#pragma once
#include <SFML/Graphics.hpp>
#include "Pistol.h"

class Player_Control
{
private:
	float xpos = 50.f;
	float ypos = 150.f;
	float fireRate = 0.f;
	float rate = 1000000000;
	bool keypressedD = false;
	bool keypressedZ = false;
	bool keypressedQ = false;
	bool keypressedS = false;
	bool isFiring = false;
	sf::CircleShape * ptrGame_Player;
	sf::RenderWindow* ptrWindow;
	Pistol weaponType();
public:
	Player_Control(sf::CircleShape *Player, sf::RenderWindow* Window);
	~Player_Control();
	void isDeplacement(sf::Event Game_event);
	void deplacement();
	void isFire(sf::Event Game_event);
	bool Fire();
	void selectWeapon();
};