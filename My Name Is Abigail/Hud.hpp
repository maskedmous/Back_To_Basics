#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Button.hpp"
#include "Inventory.hpp"
#include "GameObject.hpp"
#include "AudioPlayer.hpp"

class Hud
{
	private:
		sf::RenderWindow * window;
		Game * game;
		Inventory * inventory;
		AudioPlayer * audioPlayer;

		sf::Font font;
		sf::Text itemNameText;
		sf::Font itemNameFont;
		sf::Texture theHUDTex;
		sf::Sprite theHUD;

        sf::Texture introTex;
        sf::Sprite intro;

		sf::Texture selectionTex;
		sf::Sprite selection;

        sf::Text tipText;
        sf::Texture tipBackgroundTex;
        sf::Sprite tipBackground;

        float tipTimer;
        bool tipBool;

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
		void setTip(std::string aTip);
		void countdown(float step);
		void setAudioPlayer(AudioPlayer * m_audioPlayer);
};

#endif // HUD_H
