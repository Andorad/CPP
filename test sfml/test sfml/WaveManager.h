#pragma once
#include <SFML/Graphics.hpp>
#include "BasicEnemy.h"

class WaveManager
{
public:
	WaveManager();
	~WaveManager() = default;
	void InstantiateWaves(std::vector<Character*>& enemyList, int x, int y, int enemiesToSpawn);
};