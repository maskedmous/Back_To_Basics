#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Hud
{
	private:
		sf::RenderWindow * window;
		Behaviour * characterController;
		sf::Font font;
		sf::Texture theHUDTex;
		sf::Sprite theHUD;
	public:
		Hud( sf::RenderWindow * aWindow );
		virtual ~Hud();

		void draw( );
		void setCharacter(Behaviour * aCharacterController);
};

#endif // HUD_H
