#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player_control.h"
#include "Bullet.h"
#include "UI.h"
#include "BasicEnemy.h"
#include "WaveManager.h"
#include <iostream>
#include <cstdlib>

class Game_controller
{
private:
	float xpos = 512.f;
	float ypos = 400.f;
	int screenWidth = 1024;
	int screenHeight = 800;
	bool firing = false;
	float fireRate = 0;
	int score;
	int maxAmmoInLoader;
	int ammo;

public:
	Game_controller();
	~Game_controller() = default;
	void Game();
	void AddScore(UI& ui);
	void Reload(UI& ui);
	void Shoot(UI& ui);

};