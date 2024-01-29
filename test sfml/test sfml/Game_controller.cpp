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
	float speed = 1000.f;
	double bulletDirection;
	vector<Bullet> bulletTab;
	bulletTab.clear();
	vector<int> bulletTabErase;
	//vector<double>bulletDirectionTab;
	bool isFiring;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "top-down Game");
	sf::CircleShape Player(50.f);
	Player.setOutlineColor(sf::Color::Red);
	Player.setFillColor(sf::Color(100, 250, 50));
	Player.setPosition(xpos, ypos);
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
		sf::Vector2f playerPos = Player.getPosition();
		float distX = mousePos.x - Player.getPosition().x;
		float distY = mousePos.y - Player.getPosition().y;
		double bulletDirectionRad = atan2(distY, distX);
		double bulletDirectionDeg = bulletDirectionRad * 180.f / 3.14159265358979323846f;

		playerControl.deplacement();
		isFiring = playerControl.Fire();



		if(isFiring)
		{
			Bullet* bullet = new Bullet(10.f, Player.getPosition().x, Player.getPosition().y);
			bulletTab.push_back(*bullet); //->getBulletObject()
			bullet->SetBulletDirection(bulletDirectionRad);
			//bulletDirectionTab.push_back(bulletDirectionDeg);
		}
		for (int i = 0; i < bulletTab.size(); i++)
		{
			dirX = cos(bulletTab[i].GetBulletDirection()) + speed;
			dirY = sin(bulletTab[i].GetBulletDirection()) + speed;
			bulletTab[i].getBulletObject().setPosition(bulletTab[i].GetBulletPosition());
			bulletTab[i].getBulletObject().move(dirX, dirY);
			if(bulletTab[i].getBulletObject().getPosition().x < 0 || bulletTab[i].getBulletObject().getPosition().x > screenWidth)
			{
				bulletTabErase.push_back(i);
				continue;
			}
			else if (bulletTab[i].getBulletObject().getPosition().y < 0 || bulletTab[i].getBulletObject().getPosition().y > screenHeight)
			{
				bulletTabErase.push_back(i);
				continue;
			}

			bulletTab[i].SetBulletPosition(bulletTab[i].getBulletObject().getPosition().x, bulletTab[i].getBulletObject().getPosition().y);
			window.draw(bulletTab[i].getBulletObject());
		}
		for(int i = 0; i < bulletTabErase.size(); i++)
		{
			if(bulletTab.empty() == false)
			{
				bulletTab.erase(bulletTab.cbegin() + bulletTabErase[i]);
			}
		}

		//cout << bulletTab.size() << endl;
		/// draw part
		bulletTabErase.clear();
		window.draw(Player);
		window.display();
	}
}