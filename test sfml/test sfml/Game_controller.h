#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player_control.h"
#include "Bullet.h"

class Game_controller
{
private:
	float xpos = 50.f;
	float ypos = 150.f;
	bool firing = false;
	float fireRate = 0;

public:
	Game_controller();
	~Game_controller();
	void Game();

};