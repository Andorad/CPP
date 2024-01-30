#include <SFML/Graphics.hpp>
#include "BasicEnemy.h"
#include "WaveManager.h"
#include <iostream>
#include <cstdlib>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Exemple de texte");
    std::vector<Character*> enemyList;
    WaveManager waveManager;
    int targetX = 100;
    int targetY = 100;// A remplacer par la position du joueur
    int enemiesToSpawn = 1;

    srand(time(nullptr));

    while (window.isOpen())
    {
        //Si tous les ennemis sont morts on lance la nouvelle vague
        if(enemyList.size() == 0)
        {
            waveManager.InstantiateWaves(enemyList, window.getSize().x, window.getSize().y, enemiesToSpawn);
            enemiesToSpawn *= 2;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::A)
                {
                    if(!enemyList.empty())
                    {
                        enemyList[0]->TakeDamage();
                        if (enemyList[0]->GetHealth() <= 0)
                        {
                            delete(enemyList[0]);
                            enemyList[0] = nullptr;
                            enemyList.erase(enemyList.begin());
                        }
                    }
                }
                else if(event.key.code == sf::Keyboard::Z)
                {
                    enemyList.push_back(new BasicEnemy);
                    enemyList[enemyList.size() - 1]->Spawn(window.getSize().x, window.getSize().y);
                }
                else if (event.key.code == sf::Keyboard::E)
                {
                    targetX = rand() % window.getSize().x;
                    targetY = rand() % window.getSize().y;
                }
            }
        }

        window.clear();
        //Si on a des ennemis dans la scène, on les déplace et on les redessine à leur nouvelle position
        if(!enemyList.empty())
        {
            for (size_t i = 0; i < enemyList.size(); i++)
            {
                enemyList[i]->Move(targetX, targetY);
                enemyList[i]->Draw(window);
            }
        }
        window.display();
    }

    return 0;
}