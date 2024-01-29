#include "Player_Control.h"

#include <iostream>

#include "Pistol.h"

Player_Control::Player_Control(sf::CircleShape *Player, sf::RenderWindow *Window)
{
	ptrGame_Player = Player;
	ptrWindow = Window;
};

Player_Control::~Player_Control() = default;

void Player_Control::isDeplacement(sf::Event Game_event)
{
		if (Game_event.type == sf::Event::KeyPressed)
		{
			if (Game_event.key.code == sf::Keyboard::Z)
			{
				keypressedZ = true;
			}
			else if (Game_event.key.code == sf::Keyboard::S)
			{
				keypressedS = true;
			}
			if (Game_event.key.code == sf::Keyboard::D)
			{
				keypressedD = true;
			}
			else if (Game_event.key.code == sf::Keyboard::Q)
			{
				keypressedQ = true;
			}
		}
		else if (Game_event.type == sf::Event::KeyReleased)
		{
			if (Game_event.key.code == sf::Keyboard::Z)
			{
				keypressedZ = false;
			}
			else if (Game_event.key.code == sf::Keyboard::S)
			{
				keypressedS = false;
			}
			if (Game_event.key.code == sf::Keyboard::D)
			{
				keypressedD = false;
			}
			else if (Game_event.key.code == sf::Keyboard::Q)
			{
				keypressedQ = false;
			}
		
		}

};

void Player_Control::deplacement()
{
	if (keypressedZ)
	{
		ypos -= 1.5f;
		ptrGame_Player->setPosition(xpos, ypos);
		//std::cout << "up!" << std::endl;
	}
	if (keypressedS)
	{
		ypos += 1.5f;
		ptrGame_Player->setPosition(xpos, ypos);
		//std::cout << "down!" << std::endl;
	}
	if (keypressedQ)
	{
		xpos -= 1.5f;
		ptrGame_Player->setPosition(xpos, ypos);
		//std::cout << "left!" << std::endl;
	}
	if (keypressedD)
	{
		xpos += 1.5f;
		ptrGame_Player->setPosition(xpos, ypos);
		//std::cout << "right!" << std::endl;
	}
	//ptrGame_Player->setRotation();

}

void Player_Control::isFire(sf::Event Game_event)
{
	if (Game_event.type == sf::Event::MouseButtonPressed)
	{
		isFiring = true;
	}
	else if (Game_event.type == sf::Event::MouseButtonReleased)
	{
		isFiring = false;
	}
}

bool Player_Control::Fire()
{
	//Pistol pistol* = new Pistol;
	//weaponType().Getfirerate()
	if(isFiring)
	{
		if (rate >= 6)
		{
			rate = 0;
			return true;
		}
		else
		{
			rate += 0.1;
			return false;
		}
	}
	else
	{
		rate = 1000000000;
		return false;
	}
}


void Player_Control::selectWeapon()
{
}
