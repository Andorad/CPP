#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Character
{
	public:
		//Constructeur/Destructeur
		Character();
		~Character() = default;
		//Méthodes
		virtual void Attack() = 0;
		virtual void Move(int posX, int posY) = 0;
		void Spawn(int sizeX, int sizeY);
		void Draw(sf::RenderWindow& window);
		void TakeDamage();
		int GetHealth() { return m_health; }
		sf::CircleShape GetShape() { return m_shape; }

	protected:
		float m_radius = 50;
		float m_attackRange = 50;
		float m_speed = 1.f;
		bool m_canAttack = false;
		int m_maxHealth = 2;
		int m_health = m_maxHealth;
		sf::CircleShape m_shape;
		sf::Color m_color = sf::Color::Blue;
		int m_damages = 1;
		float m_attackSpeed = 1;

};