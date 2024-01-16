#include "Game_controller.h"
#include <iostream>
using namespace std;


Game_controller::Game_controller()
{
	
};
Game_controller::~Game_controller() = default;


void Game_controller::Game()
{
	float speedX = 0.1f;
	float speedY = 0.1f;
	int screenWidth = 1024;
	int screenHeight = 800;
	int distX;
	int distY;
	double bulletDirectionRad;
	double bulletDirection;
	sf::Vector2i mousePos;
	vector<sf::CircleShape> bulletTab;
	//vector<sf::Vector2f>
	vector<double>bulletDirectionTab;
	bool isFiring;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Simple 2D Game");
	//window.getSize();
	sf::CircleShape Player(50.f);
	Player.setOutlineColor(sf::Color::Red);
	Player.setFillColor(sf::Color(100, 250, 50));
	Player.setPosition(xpos, ypos);
	Player_Control playerControl(&Player, &window);


	//window.setFramerateLimit(60);
	while (window.isOpen())
	{
		window.clear();
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
		isFiring = playerControl.fire(event);

		if(isFiring)
		{
			Bullet bullet(10.f, Player.getPosition().x, Player.getPosition().y);
			bulletTab.push_back(bullet.getBulletObject());
			mousePos = sf::Mouse::getPosition();
			distX = mousePos.x - Player.getPosition().x;
			distY = mousePos.y - Player.getPosition().y;

			bulletDirectionRad = atan2(distY, distX);
			bulletDirection = bulletDirectionRad * 180 / 3.14159265358979323846;
			std::cout << "rad: " << bulletDirectionRad << "deg: " << bulletDirection << endl;
			bulletDirectionTab.push_back(bulletDirection);
		}
		for (int i = 0; i < bulletTab.size(); i++)
		{
			bulletTab[i].move(speedX,speedY);
			if(bulletTab[i].getPosition().x < 0 || bulletTab[i].getPosition().x > screenWidth)
			{
				bulletTab.erase(bulletTab.cbegin() + i);
				if (not bulletTab.empty())
				//std::cout << bulletTab[i].getPosition().x << ' ' << bulletTab[i].getPosition().y << std::endl;
				continue;
			}
			else if (bulletTab[i].getPosition().y < 0 || bulletTab[i].getPosition().y > screenHeight)
			{
				bulletTab.erase(bulletTab.cbegin() + i);
				if (not bulletTab.empty())
				//std::cout << bulletTab[i].getPosition().x << ' ' << bulletTab[i].getPosition().y << std::endl;
				continue;
			}
			window.draw(bulletTab[i]);
		}

		window.draw(Player);
		window.display();
	}
}