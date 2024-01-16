#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player_control.h"
#include "Bullet.h"

class Game_controller
{
private:
	float xpos = 512.f;
	float ypos = 400.f;
	int screenWidth = 1024;
	int screenHeight = 800;
	bool firing = false;
	float fireRate = 0;

public:
	Game_controller();
	~Game_controller();
	void Game();

};