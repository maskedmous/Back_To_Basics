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

		sf::Texture selectionTex;
		sf::Sprite selection;

        std::vector< Button * > mainMenuButtons;

        unsigned int firstTrigger;
        GameObject * itemA;
        GameObject * itemB;
        bool slot1Trigger;
        bool slot2Trigger;
        bool slot3Trigger;
        bool slot4Trigger;
        bool slot5Trigger;

	public:
		Hud( sf::RenderWindow * aWindow, Game * aGame );
		virtual ~Hud();

		void draw( );
		void setSlotTrigger();
		void setInventory(Inventory * aInventory);
		void addButtonToMainMenu(Button * newButton);
};

#endif // HUD_H
