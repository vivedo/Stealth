//
// Created by vivedo on 09/05/20.
//

#ifndef STEALTH_MAINMENU_HPP
#define STEALTH_MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameState.hpp"
#include "Stealth.hpp"
#include "Game.hpp"

enum MenuOption {
    NONE,
    NEW_GAME,
    QUIT
};

class MainMenu : public GameState {
public:
    ~MainMenu();

    void init(Stealth &stealth) override;

    void unload() override;

    void update(Stealth &stealth) override;

protected:
    void handleEvent(Stealth &stealth, sf::Event &event) override;

private:
    sf::Clock clock;
    sf::Music *music;
    sf::SoundBuffer selectionSfxBuffer;
    sf::SoundBuffer unselectionSfxBuffer;
    sf::Sound selectionSfx;
    sf::Sound unselectionSfx;
    sf::Font titleFont;
    sf::Texture bgTexture;
    sf::Sprite bgSprite;
    sf::Text mainMenuTxt;
    sf::Font selectionFont;
    sf::Text newGameTxt;
    sf::Text missionTxt;
    sf::Text quitTxt;

    sf::Cursor selectCursor;
    sf::Cursor defaultCursor;

    MenuOption selectedOption = NONE;

    const sf::Color selectedColor = sf::Color(152, 251, 152);
    const sf::Color defaultColor = sf::Color(50, 205, 50);

};


#endif //STEALTH_MAINMENU_HPP
