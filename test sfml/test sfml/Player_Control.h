#pragma once
#include <SFML/Graphics.hpp>

class Player_Control
{
private:
	float xpos = 50.f;
	float ypos = 150.f;
	float fireRate = 0.f;
	bool keypressedD = false;
	bool keypressedZ = false;
	bool keypressedQ = false;
	bool keypressedS = false;
	bool firing = false;
	sf::CircleShape * ptrGame_Player;
	sf::RenderWindow* ptrWindow;

public:
	Player_Control(sf::CircleShape *Player, sf::RenderWindow* Window);
	~Player_Control();
	void deplacement(sf::Event Game_event);
	bool fire(sf::Event Game_event);
};