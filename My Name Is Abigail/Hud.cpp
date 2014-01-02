#include <cassert>
#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <vector>
#include "FPS.hpp"
#include "Hud.hpp"
#include "Behaviour.hpp"
#include "Behaviours/PlayerController.hpp"
#include "Texture.hpp"

Hud::Hud( sf::RenderWindow * aWindow, Game * aGame )
:	window( aWindow ), game(aGame), inventory(NULL)
{
	assert ( window != NULL );

    if ( theHUDTex.loadFromFile("models/HUD.png") ) //when successful loaded
    {
		theHUD.setTexture( theHUDTex); // provide sprite with texture
		theHUD.setPosition(0,window->getSize().y - 200); // put it somewhere anoying
    }
    else { std::cout << "Could not load HUD.png" << std::endl; }
}

Hud::~Hud()
{
	//dtor
}

void Hud::draw()
{
	glDisable( GL_CULL_FACE ); // needed for text, dont know why
	char fps[] = "Test";
	sprintf( fps, "%4d", FPS::getFPS() ); // put fps in char array ( primitive string )
	sf::Text text( fps );
	//text.setFont(font); // when loaded other font
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::Yellow);
	text.setPosition( 10,10);

	// Draw it
	//std::cout << "Drawing text" << std::endl;
	assert ( window != NULL );
	window->pushGLStates();

    //draw the main menu
    if(game->getState() == "Main Menu")
    {
        for(unsigned int j = 0; j<mainMenuButtons.size(); ++j)
        {
            Button * thisButton = mainMenuButtons[j];
            window->draw(thisButton->getButtonSprite());
        }
    }



    //get the inventory
    if(game->getState() == "Play")
    {
        window->draw( theHUD );


        std::vector< GameObject * > items = inventory->getInventory();

		//draw inventory
		int position = 0;
		sf::Texture thisItemTex;
		sf::Sprite thisItemSprite;
        thisItemSprite.setScale( 1, -1);
		for(unsigned int i=0; i<items.size(); ++i)
        {
            GameObject * thisItem = items[i];
            thisItemTex.loadFromImage( Texture::getImage( (thisItem->getTexture()->getName()).c_str() ) );
            thisItemSprite.setTexture( thisItemTex );
            position = (10 + ((i+1) * 85) + (i * 150));
            thisItemSprite.setPosition( position, window->getSize().y - 25 );
            window->draw(thisItemSprite);
        }
    }
		window->draw( text );
	window->popGLStates();
}

void Hud::setInventory(Inventory * aInventory)
{
    inventory = aInventory;
}

void Hud::addButtonToMainMenu(Button * newButton)
{
    mainMenuButtons.push_back(newButton);
}
