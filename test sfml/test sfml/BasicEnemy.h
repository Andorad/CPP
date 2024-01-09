#pragma once
#include "Character.h"
#include "Player_Control.h"

class BasicEnemy : public Character
{
	public:
		void Attack() override;
		void Move() override;
};