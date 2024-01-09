
#include "UI.h"
UI::UI(sf::RenderWindow &_window)
{
    score = 0;
    maxAmmoInLoader = 10;
    ammo = maxAmmoInLoader;
    if (!font.loadFromFile("charbb_reg.ttf"))
    {
        // Gérer l'erreur si la police n'a pas pu être chargée
    }
    scoreText.setString("Score : " + std::to_string(score));
    scoreText.setFont(font);
    scoreText.setCharacterSize(70);
    scoreText.setPosition(0, 0);

    ammoText.setString(std::to_string(ammo));
    ammoText.setFont(font);
    ammoText.setCharacterSize(70);
    ammoText.setPosition(_window.getSize().x - 60, _window.getSize().y - 70);
}
UI::~UI() = default;


int UI::ModifyScoreValue(int _score, int modif)
{
    _score += modif;

    if (_score <= 0)
    {
        _score = 0;
    }

    return _score;
}

int UI::ModifyAmmoValue(int _ammo, int modif)
{
    _ammo += modif;

    if (_ammo <= 0)
    {
        _ammo = 0;
    }

    return _ammo;
}

//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Exemple de texte");
//
//    UI ui(window);
//    
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//                ----score = ModifyScoreValue(score, 5);
//                ----scoreText.setString("Score : " + std::to_string(score));
//            
//            ----if(event.type == sf::Event::MouseButtonPressed)
//            ----{
//                ----else if (event.key.code == sf::Mouse::Left)
//                ----{
//                    ----if(ammo > 0)
//                    ----{
//                        ----ammo = ModifyAmmoValue(ammo, -1);
//                        ----ammoText.setString(std::to_string(ammo));
//                    ----}
//                    ----else
//                    ----{
//                        ----ammo = ModifyAmmoValue(ammo, (maxAmmoInLoader - ammo));
//                        ----ammoText.setString(std::to_string(ammo));
//                    ----}
//                ----}
//                ----else if(event.key.code == sf::Keyboard::R)
//                ----{
//                    ----ammo = ModifyAmmoValue(ammo, (maxAmmoInLoader - ammo));
//                    ----ammoText.setString(std::to_string(ammo));
//                ----}
//            ----}
//        }
//        window.clear();
//        ---- window.draw(scoreText);
//        ---- window.draw(ammoText);
//        window.display();
//    }
//
//    return 0;
//}

