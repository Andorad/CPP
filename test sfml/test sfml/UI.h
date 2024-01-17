#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class UI
{
public:
	UI(sf::RenderWindow& _window);
	~UI() = default;
	void ModifyAmmoValue(int ammo);
	void ModifyScoreValue(int score);
	void UpdateUI(sf::RenderWindow& window);
private:
	sf::Texture targetTexture;
	sf::Sprite onMouseSprite;
	sf::Vector2f spriteOffset;
	sf::Text scoreText;
	sf::Font font;
	sf::Text ammoText;
};