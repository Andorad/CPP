#include "Game_controller.h"

int main()
{
	Game_controller game;
	game.Game();

	/*
	float xpos = 50.f;
	float ypos = 150.f;
	bool firing = false;
	float fireRate = 0;
	sf::CircleShape *ptrPlayer;

	sf::RenderWindow window(sf::VideoMode(1024, 800), "Simple 2D Game");

	sf::CircleShape Player(50.f);
	Player.setOutlineColor(sf::Color::Red);
	Player.setFillColor(sf::Color(100,250,50));
	Player.setPosition(xpos, ypos);
	Player_Control playerControl(&Player);

	sf::CircleShape Bullet(10.f);
	Bullet.setFillColor(sf::Color::Magenta);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			playerControl.deplacement(event);
			playerControl.fire(event);
		}
		playerControl.deplacement(event);
		playerControl.fire(event);
		window.clear();

		window.draw(Player);

		window.display();
	}*/

	return 0;
}