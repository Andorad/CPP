#include <SFML/Graphics.hpp>
#include "UI.h"

int score = 0;
int maxAmmoInLoader = 10;
int ammo = maxAmmoInLoader;

void AddScore(UI& ui)
{
    score += 5;
    ui.ModifyScoreValue(score);
}

void Reload(UI& ui)
{
    ammo += maxAmmoInLoader - ammo;
    ui.ModifyAmmoValue(ammo);
}

void Shoot(UI& ui)
{
    if(ammo > 0)
    {
        ammo--;
        ui.ModifyAmmoValue(ammo);
    }
    else
    {
        Reload(ui);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Exemple de texte");

    UI ui(window);

    ui.ModifyAmmoValue(ammo);

    ui.ModifyScoreValue(score);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.key.code == sf::Mouse::Left)
                {
                    Shoot(ui);
                }
            }
             if(event.type == sf::Event::KeyPressed)
             {
                 if (event.key.code == sf::Keyboard::R)
                 {
                     Reload(ui);
                 }
                 else if (event.key.code == sf::Keyboard::P)
                 {
                     AddScore(ui);
                 }
             }
        }

        window.clear();
        ui.UpdateUI(window);
        window.display();
    }

    return 0;
}