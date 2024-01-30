#include "Game_controller.h"
#include "Player.h"
#include <iostream>
#include <cmath>
using namespace std;


Game_controller::Game_controller()
{
	score = 0;
	maxAmmoInLoader = 10;
	ammo = maxAmmoInLoader;
};

void Game_controller::AddScore(UI& ui)
{
	score += 5;
	ui.ModifyScoreValue(score);
}

void Game_controller::Reload(UI& ui)
{
	ammo += maxAmmoInLoader - ammo;
	ui.ModifyAmmoValue(ammo);
}

void Game_controller::Shoot(UI& ui)
{
	if (ammo > 0)
	{
		ammo--;
		ui.ModifyAmmoValue(ammo);
	}
	else
	{
		Reload(ui);
	}
}

void Game_controller::Game()
{
	double dirX = 0;
	double dirY = 0;
	double bulletDirection;
	vector<Bullet*> bulletTab;
	bulletTab.clear();
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "top-down Game");

	UI ui(window);

	ui.ModifyAmmoValue(ammo);

	ui.ModifyScoreValue(score);

	std::vector<Character*> enemyList;
	WaveManager waveManager;
	int enemiesToSpawn = 1;

	srand(time(nullptr));


	sf::RectangleShape weaponShape(sf::Vector2f(70, 10));
	weaponShape.setOrigin(0, 5);

	Player* player = new Player();
	player->Spawn(screenWidth / 2, screenHeight / 2);

	//Player_Control playerControl(player);
	//playerControl.selectWeapon();

	window.setFramerateLimit(60);
	while (window.isOpen())
	{


		if (enemyList.size() == 0)
		{
			waveManager.InstantiateWaves(enemyList, window.getSize().x, window.getSize().y, enemiesToSpawn);
			enemiesToSpawn *= 2;
		}

		sf::Event event;

		while (window.pollEvent(event))
		{
			player->isMoving(event);
			player->isAttacking(event, ammo);

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if(event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::R)
				{
					Reload(ui);
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					Shoot(ui);
				}
			}
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		float distX = mousePos.x - player->GetShape().getPosition().x;
		float distY = mousePos.y - player->GetShape().getPosition().y;
		double bulletDirectionRad = atan2(distY, distX);
		double bulletDirectionDeg = bulletDirectionRad * 180.f / 3.14159265358979323846f;
		
		weaponShape.setRotation(bulletDirectionDeg);
		weaponShape.setPosition(player->GetShape().getPosition());

		player->Move(0, 0);
		player->Attack();

		if (player->GetIsFiring())
		{
			Bullet* bullet = new Bullet(player->GetShape().getPosition().x , player->GetShape().getPosition().y);
			bulletTab.push_back(bullet);
			bullet->SetBulletDirection(bulletDirectionRad);
			bullet->BulletMove();
			bullet->BulletMove();
			bullet->BulletMove();
			bullet->BulletMove();
			bullet->BulletMove();
			bullet->BulletMove();
		}

		window.clear();

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

		if (!enemyList.empty())
		{
			for (size_t i = 0; i < enemyList.size(); i++)
			{
				enemyList[i]->Move(player->GetShape().getPosition().x, player->GetShape().getPosition().y);
				enemyList[i]->Draw(window);
			}
		}

		window.draw(weaponShape);
		window.draw(player->GetShape());
		ui.UpdateUI(window);
		window.display();
	}
}