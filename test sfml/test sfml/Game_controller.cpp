#include "Game_controller.h"
#include <iostream>
#include <cmath>
using namespace std;


Game_controller::Game_controller()
{
	
};
Game_controller::~Game_controller() = default;


void Game_controller::Game()
{
	double dirX = 0;
	double dirY = 0;
	float speed = 0.1f;
	double bulletDirection;
	vector<sf::CircleShape> bulletTab;
	vector<int> bulletTabErase;
	vector<double>bulletDirectionTab;
	bool isFiring;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Simple 2D Game");
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
			Bullet* bullet = new Bullet(10.f, Player.getPosition().x, Player.getPosition().y);
			bulletTab.push_back(bullet->getBulletObject());
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f playerPos = Player.getPosition();

			float distX = mousePos.x - Player.getPosition().x;
			float distY = mousePos.y - Player.getPosition().y;
			double bulletDirectionRad = atan2(distY, distX);
			double bulletDirectionDeg = bulletDirectionRad * 180.f / 3.14159265358979323846f;
			cout << "rad: " << bulletDirectionRad << ", deg: " << bulletDirectionDeg << endl;
			
			//cout << "rad: " << bulletDirectionRad << " playerPos: " << Player.getPosition().x << ", " << Player.getPosition().y << endl;
			bulletDirectionTab.push_back(bulletDirectionDeg);
			dirX = cos(bulletDirectionRad) + speed;
			dirY = sin(bulletDirectionRad) + speed;
		}
		for (int i = 0; i < bulletTab.size(); i++)
		{
			bulletTab[i].move(dirX, dirY);
			if(bulletTab[i].getPosition().x < 0 || bulletTab[i].getPosition().x > screenWidth)
			{
				bulletTabErase.push_back(i);
				continue;
			}
			else if (bulletTab[i].getPosition().y < 0 || bulletTab[i].getPosition().y > screenHeight)
			{
				bulletTabErase.push_back(i);
				continue;
			}
			window.draw(bulletTab[i]);
		}
		for(int i = 0; i < bulletTabErase.size(); i++)
		{
			if(bulletTab.empty() == false)
			{
				//std::cout << "bullet " << bulletTab[i].getPosition().x << ' ' << bulletTab[i].getPosition().y << " as been destroyed" << std::endl;
				bulletTab.erase(bulletTab.cbegin() + bulletTabErase[i]);
			}
		}
		bulletTabErase.clear();
		window.draw(Player);
		window.display();
	}
}