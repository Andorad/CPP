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
		virtual void Move(int targetPosX, int targetPosY) = 0;
		virtual void Spawn(int sizeX, int sizeY) = 0;
		void Draw(sf::RenderWindow& window);
		void TakeDamage();
		int GetHealth() { return m_health; }

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