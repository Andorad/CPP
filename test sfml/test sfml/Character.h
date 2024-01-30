#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Character
{
	private:
		sf::CircleShape shape;
		float radius = 50;
		sf::Color color = sf::Color::Blue;
		float speed = 50.f;
		int maxHealth = 2;
		int health = maxHealth;
		int damages = 1;
		float attackSpeed = 1;
		float attackRange = 50;
		bool canAttack;
	public:
		//Constructeur/Destructeur
		Character();
		~Character() = default;
		//Méthodes
		virtual void Attack() = 0;
		virtual void Move(int targetPosX, int targetPosY) = 0;
		virtual void Spawn(int sizeX, int sizeY) = 0;
		//bool Collision(const sf::CircleShape& circle2);
		void Draw(sf::RenderWindow& window);
		void TakeDamage();
		//Getters
		const sf::Vector2f& GetPosition() { return shape.getPosition(); }
		const float& GetSpeed() { return speed; }
		const int& GetMaxHealth() { return maxHealth; }
		const int& GetHealth() { return health; }
		const bool& GetCanAttack() { return canAttack; }
		const float& GetAttackRange() { return attackRange; }
		const float& GetAttackSpeed() { return attackSpeed; }
		const float& GetRadius() { return radius; }
		const sf::CircleShape& GetShape() { return shape; }
		//Setters
		void SetPosition(sf::Vector2f _pos) { shape.setPosition(_pos); }
		void SetHealth(int _health) { health = _health; }
		void SetCanAttack(bool _canAttack) { canAttack = _canAttack; }
		void SetSpeed(float _speed) { speed = _speed; }
};