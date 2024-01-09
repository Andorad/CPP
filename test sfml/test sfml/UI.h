#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class UI
{
	private:
		int score;
		int maxAmmoInLoader;
		int ammo;
		sf::Font font;
		sf::Text scoreText;
		sf::Text ammoText;
	public:
		UI(sf::RenderWindow& _window);
		~UI();
		int ModifyAmmoValue(int _ammo, int modif);
		int ModifyScoreValue(int _score, int modif);
};