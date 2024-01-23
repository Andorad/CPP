#include <SFML/Graphics.hpp>
#include "BasicEnemy.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Exemple de texte");
    std::vector<Character*> enemyList;

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
                }
            }
        }

        window.clear();
        if(!enemyList.empty())
        {
            for (size_t i = 0; i < enemyList.size(); i++)
            {
                enemyList[i]->Move();
                enemyList[i]->Draw(window);
            }
        }
        window.display();
    }

    return 0;
}