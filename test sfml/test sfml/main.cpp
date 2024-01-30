//#include <SFML/Graphics.hpp>
//#include "UI.h"
//#include "BasicEnemy.h"
//#include "WaveManager.h"
//#include <iostream>
//#include <cstdlib>
//
//
//int score = 0;
//int maxAmmoInLoader = 10;
//int ammo = maxAmmoInLoader;
//
//void AddScore(UI& ui)
//{
//    score += 5;
//    ui.ModifyScoreValue(score);
//}
//
//void Reload(UI& ui)
//{
//    ammo += maxAmmoInLoader - ammo;
//    ui.ModifyAmmoValue(ammo);
//}
//
//void Shoot(UI& ui)
//{
//    if(ammo > 0)
//    {
//        ammo--;
//        ui.ModifyAmmoValue(ammo);
//    }
//    else
//    {
//        Reload(ui);
//    }
//}
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Exemple de texte");
//
//    UI ui(window);
//
//    ui.ModifyAmmoValue(ammo);
//
//    ui.ModifyScoreValue(score);
//
//    std::vector<Character*> enemyList;
//    WaveManager waveManager;
//    int targetX = 100;
//    int targetY = 100;// A remplacer par la position du joueur
//    int enemiesToSpawn = 1;
//
//    srand(time(nullptr));
//
//    while (window.isOpen())
//    {
//        //Si tous les ennemis sont morts on lance la nouvelle vague
//        if(enemyList.size() == 0)
//        {
//            waveManager.InstantiateWaves(enemyList, window.getSize().x, window.getSize().y, enemiesToSpawn);
//            enemiesToSpawn *= 2;
//        }
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//            else if(event.type == sf::Event::KeyPressed)
//            {
//                if(event.key.code == sf::Keyboard::A)
//                {
//                    if(!enemyList.empty())
//                    {
//                        enemyList[0]->TakeDamage();
//                        if (enemyList[0]->GetHealth() <= 0)
//                        {
//                            delete(enemyList[0]);
//                            AddScore(ui);
//                            enemyList[0] = nullptr;
//                            enemyList.erase(enemyList.begin());
//                        }
//                    }
//                }
//                else if(event.key.code == sf::Keyboard::Z)
//                {
//                    enemyList.push_back(new BasicEnemy);
//                    enemyList[enemyList.size() - 1]->Spawn(window.getSize().x, window.getSize().y);
//                }
//                else if (event.key.code == sf::Keyboard::E)
//                {
//                    targetX = rand() % window.getSize().x;
//                    targetY = rand() % window.getSize().y;
//                }
//                else if (event.key.code == sf::Keyboard::R)
//                 {
//                     Reload(ui);
//                 }
//                 else if (event.key.code == sf::Keyboard::P)
//                 {
//                     AddScore(ui);
//                 }
//            }
//            
//            if (event.type == sf::Event::MouseButtonPressed)
//            {
//                if (event.key.code == sf::Mouse::Left)
//                {
//                    Shoot(ui);
//                }
//            }
//        }
//
//        window.clear();
//        //Si on a des ennemis dans la sc�ne, on les d�place et on les redessine � leur nouvelle position
//        if(!enemyList.empty())
//        {
//            for (size_t i = 0; i < enemyList.size(); i++)
//            {
//                enemyList[i]->Move(targetX, targetY);
//                enemyList[i]->Draw(window);
//            }
//        }
//        ui.UpdateUI(window);
//        window.display();
//    }
//
//    return 0;
//}