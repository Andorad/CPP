#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class BasicEnemy : public Character
{
	public:
		BasicEnemy();
		~BasicEnemy() = default;
		//void Attack() override;
		void Move() override;
};