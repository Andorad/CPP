#include "Player_Control.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Player_Control::Player_Control(sf::CircleShape* Player, sf::RenderWindow* Window)
{
	Game_Window = Window;
	Game_Player = *Player;
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
			ypos -= 0.1f;
			Game_Player.setPosition(xpos, ypos);
		}
		if (keypressedS)
		{
			ypos += 0.1f;
			Game_Player.setPosition(xpos, ypos);
		}
		if (keypressedQ)
		{
			xpos -= 0.1f;
			Game_Player.setPosition(xpos, ypos);
		}
		if (keypressedD)
		{
			xpos += 0.1f;
			Game_Player.setPosition(xpos, ypos);
		}
		};

void Player_Control::fire(sf::Event Game_event)
{
	if (Game_event.type == sf::Event::MouseButtonPressed)
	{
		firing = true;
	}
	else if (Game_event.type == sf::Event::MouseButtonReleased)
	{
		firing = false;
	}

	if (firing)
	{
		sf::CircleShape Bullet(10.f);
		fireRate += 1;
		if (fireRate >= 30)
		{
			std::cout << "fire!" << std::endl;
			fireRate = 0;
			Game_Window.draw(Bullet);
		}
		else
		{
			fireRate = 0;
		}
	}
}