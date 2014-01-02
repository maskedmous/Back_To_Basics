#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Button.hpp"
#include "Inventory.hpp"
#include "GameObject.hpp"

class Hud
{
	private:
		sf::RenderWindow * window;
		Game * game;
		Inventory * inventory;
		sf::Font font;
		sf::Texture theHUDTex;
		sf::Sprite theHUD;
        std::vector< Button * > mainMenuButtons;
	public:
		Hud( sf::RenderWindow * aWindow, Game * aGame );
		virtual ~Hud();

		void draw( );
		void setInventory(Inventory * aInventory);
		void addButtonToMainMenu(Button * newButton);
};

#endif // HUD_H
