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
	double bulletDirection;
	vector<Bullet*> bulletTab;
	bulletTab.clear();
	//vector<double>bulletDirectionTab;
	bool isFiring;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "top-down Game");


	sf::CircleShape Player(50.f);

	Player.setOutlineColor(sf::Color::Red);
	Player.setFillColor(sf::Color(100, 250, 50));
	Player.setPosition(xpos, ypos);
	Player.setOrigin(sf::Vector2f(50, 50));

	sf::RectangleShape weaponShape(sf::Vector2f(70, 10));
	weaponShape.setOrigin(0, 5);

	Player_Control playerControl(&Player, &window);
	playerControl.selectWeapon();

	window.setFramerateLimit(60);
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
			playerControl.isDeplacement(event);
			playerControl.isFire(event);
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		float distX = mousePos.x - Player.getPosition().x;
		float distY = mousePos.y - Player.getPosition().y;
		double bulletDirectionRad = atan2(distY, distX);
		double bulletDirectionDeg = bulletDirectionRad * 180.f / 3.14159265358979323846f;
		
		weaponShape.setRotation(bulletDirectionDeg);
		weaponShape.setPosition(Player.getPosition());

		playerControl.deplacement();
		isFiring = playerControl.Fire();

		if(isFiring)
		{
			Bullet* bullet = new Bullet(Player.getPosition().x , Player.getPosition().y);
			bulletTab.push_back(bullet);
			bullet->SetBulletDirection(bulletDirectionRad);
			bullet->BulletMove();
			bullet->BulletMove();
			bullet->BulletMove();
			bullet->BulletMove();
			bullet->BulletMove();
			bullet->BulletMove();
		}
		for (auto it = bulletTab.begin(); it != bulletTab.end(); )
		{
			(*it)->BulletMove();

			if((*it)->getBulletObject().getPosition().x < 0 || (*it)->getBulletObject().getPosition().x > screenWidth
			   || (*it)->getBulletObject().getPosition().y < 0 || (*it)->getBulletObject().getPosition().y > screenHeight)
			{
				delete* it;
				it = bulletTab.erase(it);
			}
			else
			{
				window.draw((*it)->getBulletObject());
				++it;
			}
		}

		window.draw(weaponShape);
		window.draw(Player);
		window.display();
	}
}