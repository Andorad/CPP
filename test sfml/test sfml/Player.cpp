#include "Player.h"

Player::Player()
{
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

	keypressedZ = false;
	keypressedS = false;
	keypressedQ = false;
	keypressedD = false;

	isFiring = false;
	rate = 1;
	
};

void Player::isAttacking(sf::Event Game_event, int ammo)
{
	if (Game_event.type == sf::Event::MouseButtonPressed && ammo > 0)
	{
		isFiring = true;
	}
	else if (Game_event.type == sf::Event::MouseButtonReleased)
	{
		isFiring = false;
	}
}

void Player::Attack()
{
	if (isFiring)
	{
		if (rate >= 1)
		{
			rate = 0;
			isFiring = true;
		}
		else
		{
			rate += 0.1;
			isFiring = false;
		}
	}
	else
	{
		rate = 1000000000;
		isFiring = false;
	}
}

bool Player::GetIsFiring()
{
	return isFiring;
}

void Player::isMoving(sf::Event Game_event)
{
	if (Game_event.type == sf::Event::KeyPressed)
	{
		if (Game_event.key.code == sf::Keyboard::Z)
		{
			keypressedZ = true;
		}
		else if (Game_event.key.code == sf::Keyboard::S)
		{
			keypressedS = true;
		}
		if (Game_event.key.code == sf::Keyboard::D)
		{
			keypressedD = true;
		}
		else if (Game_event.key.code == sf::Keyboard::Q)
		{
			keypressedQ = true;
		}
	}
	else if (Game_event.type == sf::Event::KeyReleased)
	{
		if (Game_event.key.code == sf::Keyboard::Z)
		{
			keypressedZ = false;
		}
		else if (Game_event.key.code == sf::Keyboard::S)
		{
			keypressedS = false;
		}
		if (Game_event.key.code == sf::Keyboard::D)
		{
			keypressedD = false;
		}
		else if (Game_event.key.code == sf::Keyboard::Q)
		{
			keypressedQ = false;
		}
	}
}

void Player::Move(int posX, int posY)
{
	if (keypressedZ)
	{
		m_shape.setPosition(m_shape.getPosition().x, m_shape.getPosition().y - 5.f);
	}
	if (keypressedS)
	{
		m_shape.setPosition(m_shape.getPosition().x, m_shape.getPosition().y + 5.f);
	}
	if (keypressedQ)
	{
		m_shape.setPosition(m_shape.getPosition().x - 5.f, m_shape.getPosition().y);
	}
	if (keypressedD)
	{
		m_shape.setPosition(m_shape.getPosition().x + 5.f, m_shape.getPosition().y);
	}
}

void Player::Spawn(int sizeX, int sizeY)
{
    m_shape.setRadius(50.f);
    m_shape.setOutlineColor(sf::Color::Red);
    m_shape.setFillColor(sf::Color(100, 250, 50));
    m_shape.setPosition(sizeX, sizeY);
    m_shape.setOrigin(sf::Vector2f(50, 50));
}