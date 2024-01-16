#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class UI
{
public:
	UI(sf::RenderWindow& _window);
	~UI() = default;
	int ModifyAmmoValue(int _ammo, int modif);
	int ModifyScoreValue(int _score, int modif);
private:
	int score;
	int maxAmmoInLoader;
	int ammo;
	sf::Font font;
	sf::Text scoreText;
	sf::Text ammoText;
};