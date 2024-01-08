#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player_Control.h"

int main()
{
	float xpos = 50.f;
	float ypos = 150.f;
	bool keypressedD = false;
	bool keypressedZ = false;
	bool keypressedQ = false;
	bool keypressedS = false;
	bool firing = false;
	float fireRate = 0;



	sf::RenderWindow window(sf::VideoMode(1024, 800), "Simple 2D Game");
	sf::CircleShape Player(50.f);
	sf::CircleShape Bullet(10.f);
	

	Player.setOutlineColor(sf::Color::Red);
	Player.setFillColor(sf::Color(100,250,50));
	Player.setPosition(xpos, ypos);

	Bullet.setFillColor(sf::Color::Magenta);
	Player_Control playerControl(&Player, &window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			playerControl.deplacement(sf::Event);
			/*if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Z)
				{
					keypressedZ = true;
				}
				else if (event.key.code == sf::Keyboard::S)
				{
					keypressedS = true;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					keypressedD = true;
				}
				else if (event.key.code == sf::Keyboard::Q)
				{
					keypressedQ = true;
				}
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Z)
				{
					keypressedZ = false;
				}
				else if (event.key.code == sf::Keyboard::S)
				{
					keypressedS = false;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					keypressedD = false;
				}
				else if (event.key.code == sf::Keyboard::Q)
				{
					keypressedQ = false;
				}
			}*/

			if(event.type == sf::Event::MouseButtonPressed)
			{
				firing = true;
			}
			else if(event.type == sf::Event::MouseButtonReleased)
			{
				firing = false;
			}
		}

		//std::cout << fireRate << std::endl;
		if(firing)
		{
			fireRate += 1;
			if (fireRate >= 30)
			{
				std::cout << "fire!" << std::endl;
				fireRate = 0;
				window.draw(Bullet);
			}
		}
		else
		{
			fireRate = 0;
		}

		if (keypressedZ)
		{
			ypos -= 0.1f;
			Player.setPosition(xpos, ypos);
		}
		if (keypressedS)
		{
			ypos += 0.1f;
			Player.setPosition(xpos, ypos);
		}
		if (keypressedQ)
		{
			xpos -= 0.1f;
			Player.setPosition(xpos, ypos);
		}
		if (keypressedD)
		{
			xpos += 0.1f;
			Player.setPosition(xpos, ypos);
		}

		window.clear();
		window.draw(Player);

		window.display();
	}

	return 0;
}