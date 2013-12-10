#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "Inventory.hpp"
#include "GameObject.hpp"

class Hud
{
	private:
		sf::RenderWindow * window;
		Inventory * inventory;
		sf::Font font;
		sf::Texture theHUDTex;
		sf::Sprite theHUD;
	public:
		Hud( sf::RenderWindow * aWindow );
		virtual ~Hud();

		void draw( );
		void setInventory(Inventory * aInventory);
};

#endif // HUD_H
