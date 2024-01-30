#include "UI.h"

UI::UI(sf::RenderWindow &_window)
{
    if (!targetTexture.loadFromFile("D:/Cours_2023-2024/CPP/test sfml/target.png"))
    {
        // Gérer l'erreur si la texture n'a pas pu être chargée
    }
    targetTexture.setSmooth(true);

    //On cache le curseur de la souris et on le remplace par un sprite
    onMouseSprite.setTexture(targetTexture);
    onMouseSprite.setScale(sf::Vector2f(0.1f, 0.1f));
    _window.setMouseCursorVisible(false);

    //spriteOffset.x -= 50.f;
    //spriteOffset.y -= 50.f;

    if (!font.loadFromFile("charbb_reg.ttf"))
    {
        // Gérer l'erreur si la police n'a pas pu être chargée
    }
    //On initialise nos textes
    scoreText.setFont(font);
    scoreText.setCharacterSize(70);
    scoreText.setPosition(0, 0);

    ammoText.setFont(font);
    ammoText.setCharacterSize(70);
    ammoText.setPosition(_window.getSize().x - 60, _window.getSize().y - 70);
}


void UI::ModifyScoreValue(int _score)
{
    //On modifie la string du score à afficher en fonction du score
    scoreText.setString("Score : " + std::to_string(_score));
}

void UI::UpdateUI(sf::RenderWindow& window)
{
    //On update le UI
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mousePositionWorld = window.mapPixelToCoords(mousePosition);
    onMouseSprite.setOrigin(sf::Vector2f(onMouseSprite.getLocalBounds().width / 2, onMouseSprite.getLocalBounds().height / 2));
    onMouseSprite.setPosition(mousePositionWorld);

    Draw(window);
}

void UI::Draw(sf::RenderWindow& window)
{
    //On draw le UI
    window.draw(scoreText);
    window.draw(ammoText);
    window.draw(onMouseSprite);
}

void UI::ModifyAmmoValue(int ammo)
{
    //On modifie la string des balles à afficher en fonction du score
    ammoText.setString(std::to_string(ammo));
}