#pragma once
#include <SFML/Graphics.hpp>

class Character
{
	private:
		CharacterType characterType;
		sf::CircleShape shape;
		float radius;
		sf::Color color;
		float speed;
		float angularSpeed;
		int health;
		int damages;
		float attackSpeed;
		float attackRange;
		bool canAttack;
	public:
		//Character(int initialSpeed, int initialHealth) : speed(initialSpeed), health(initialHealth) {}
		//~Character();
		virtual void Attack() = 0;
		virtual void Move() = 0;
		void TakeDamage(){ SetHealth(GetHealth() - 1);}
		virtual void Die();
		const sf::Vector2f& GetPosition() { return shape.getPosition(); }
		const float& GetSpeed() { return speed; }
		const int& GetHealth() { return health; }
		const bool& GetCanAttack() { return canAttack; }
		const float& GetAttackRange() { return attackRange; }
		const float& GetAttackSpeed() { return attackSpeed; }
		void SetPosition(sf::Vector2f _pos) { shape.setPosition(_pos); }
		void SetHealth(int _health) { health = _health; }
		void SetCanAttack(bool _canAttack) { canAttack = _canAttack; }

};

enum CharacterType
{
	player,
	basicEnemy,
	shootingEnemy,
	dashingEnemy
};