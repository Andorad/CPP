#include "Player_Control.h"

#include <iostream>

Player_Control::Player_Control(sf::CircleShape *Player, sf::RenderWindow *Window)
{
	ptrGame_Player = Player;
	ptrWindow = Window;
};

Player_Control::~Player_Control() = default;

void Player_Control::deplacement(sf::Event Game_event)
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

		if (keypressedZ)
		{
			ypos -= 0.2f;
			ptrGame_Player->setPosition(xpos, ypos);
			std::cout << "up!" << std::endl;
		}
		if (keypressedS)
		{
			ypos += 0.2f;
			ptrGame_Player->setPosition(xpos, ypos);
			std::cout << "down!" << std::endl;
		}
		if (keypressedQ)
		{
			xpos -= 0.2f;
			ptrGame_Player->setPosition(xpos, ypos);
			std::cout << "left!" << std::endl;
		}
		if (keypressedD)
		{
			xpos += 0.2f;
			ptrGame_Player->setPosition(xpos, ypos);
			std::cout << "right!" << std::endl;
		}
		};

bool Player_Control::fire(sf::Event Game_event)
{
	bool isFiring = false;
	if (Game_event.type == sf::Event::MouseButtonPressed)
	{
		firing = true;
	}
	else if (Game_event.type == sf::Event::MouseButtonReleased)
	{
		firing = false;
		isFiring = false;
	}
	if (firing)
	{
		sf::CircleShape Bullet(10.f);
		fireRate += 1;
		if (fireRate >= 100)
		{
			//std::cout << "fire!" << std::endl;
			fireRate = 0;
			isFiring = true;
		}
	}
	else
	{
		fireRate = 0;
	}
	return isFiring;
}