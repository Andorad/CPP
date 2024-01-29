#include <SFML/Graphics.hpp>
#include "BasicEnemy.h"
#include <iostream>
#include <cstdlib>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Exemple de texte");
    std::vector<Character*> enemyList;
    int targetX = 100;
    int targetY = 100;

    srand(time(nullptr));


    while (window.isOpen())
    {

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