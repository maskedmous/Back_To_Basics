#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Hud.hpp"
#include <SFML/Window.hpp>
#include "Game.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>

class MainMenu
{
    public:
        MainMenu( Hud * aHud, sf::RenderWindow * aWindow, Game * aGame);
        virtual ~MainMenu();
        virtual void Update(float step);
        virtual void OnMouseDown( float step);
    protected:
        Hud * hud;
        sf::RenderWindow * window;
        Game * game;

        Button * background;

        Button * startButton;
        Button * optionsButton;
        Button * exitButton;

    private:
        std::string mouseState;
};

#endif // MAINMENU_HPP
