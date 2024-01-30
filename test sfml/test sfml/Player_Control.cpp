////#include "Player_Control.h"
////
////#include <iostream>
////
////Player_Control::Player_Control(Player* player) : ptrGame_Player(player)
////{
////	xpos = ptrGame_Player->GetShape().getPosition().x;
////	ypos = ptrGame_Player->GetShape().getPosition().y;
////};
////
////Player_Control::~Player_Control() = default;
////
////void Player_Control::isDeplacement(sf::Event Game_event)
////{
////		if (Game_event.type == sf::Event::KeyPressed)
////		{
////			if (Game_event.key.code == sf::Keyboard::Z)
////			{
////				keypressedZ = true;
////			}
////			else if (Game_event.key.code == sf::Keyboard::S)
////			{
////				keypressedS = true;
////			}
////			if (Game_event.key.code == sf::Keyboard::D)
////			{
////				keypressedD = true;
////			}
////			else if (Game_event.key.code == sf::Keyboard::Q)
////			{
////				keypressedQ = true;
////			}
////		}
////		else if (Game_event.type == sf::Event::KeyReleased)
////		{
////			if (Game_event.key.code == sf::Keyboard::Z)
////			{
////				keypressedZ = false;
////			}
////			else if (Game_event.key.code == sf::Keyboard::S)
////			{
////				keypressedS = false;
////			}
////			if (Game_event.key.code == sf::Keyboard::D)
////			{
////				keypressedD = false;
////			}
////			else if (Game_event.key.code == sf::Keyboard::Q)
////			{
////				keypressedQ = false;
////			}
////		}
////};
////
////void Player_Control::deplacement()
////{
////	if (keypressedZ)
////	{
////		ypos -= 5.f;
////		ptrGame_Player->GetShape().setPosition(xpos, ypos);
////		//std::cout << "up!" << std::endl;
////	}
////	if (keypressedS)
////	{
////		ypos += 5.f;
////		ptrGame_Player->GetShape().setPosition(xpos, ypos);
////		//std::cout << "down!" << std::endl;
////	}
////	if (keypressedQ)
////	{
////		xpos -= 5.f;
////		ptrGame_Player->GetShape().setPosition(xpos, ypos);
////		//std::cout << "left!" << std::endl;
////	}
////	if (keypressedD)
////	{
////		xpos += 5.f;
////		ptrGame_Player->GetShape().setPosition(xpos, ypos);
////		//std::cout << "right!" << std::endl;
////	}
////	//ptrGame_Player->setRotation();
////
////}
////
//void Player_Control::isFire(sf::Event Game_event)
//{
//	if (Game_event.type == sf::Event::MouseButtonPressed)
//	{
//		isFiring = true;
//	}
//	else if (Game_event.type == sf::Event::MouseButtonReleased)
//	{
//		isFiring = false;
//	}
//}
//
//bool Player_Control::Fire()
//{
//	//Pistol pistol* = new Pistol;
//	//weaponType().Getfirerate()
//	if(isFiring)
//	{
//		if (rate >= 1)
//		{
//			rate = 0;
//			return true;
//		}
//		else
//		{
//			rate += 0.1;
//			return false;
//		}
//	}
//	else
//	{
//		rate = 1000000000;
//		return false;
//	}
//}
////
////
////void Player_Control::selectWeapon()
////{
////}
