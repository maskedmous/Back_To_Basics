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

Hud::Hud( sf::RenderWindow * aWindow )
:	window( aWindow )
{
	assert ( window != NULL );

    if ( theHUDTex.loadFromFile("models/HUD.png") ) { // when succesfull loaded
		theHUD.setTexture( theHUDTex); // provide sprite with texture
		theHUD.setPosition(0,window->getSize().y - 200); // put it somewhere anoying
    } else {
		std::cout << "Could not load sprite" << std::endl;
	}
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
		window->draw( theHUD );
		//get the inventory
        std::vector< GameObject * > items = inventory->getInventory();

		//draw inventory
		int position = 0;
		for(unsigned int i=0; i<items.size(); ++i)
        {
            GameObject * thisItem = items[i];
            sf::Texture thisItemTex;
            thisItemTex.loadFromImage( Texture::getImage( ("models/" + thisItem->getName() + ".png").c_str() ) );
            sf::Sprite thisItemSprite;
            thisItemSprite.setTexture( thisItemTex );
            position = (10 + ((i+1) * 85) + (i * 150));
            thisItemSprite.setPosition( position, window->getSize().y - 175 );
            window->draw(thisItemSprite);
        }

		window->draw( text );
	window->popGLStates();
}

void Hud::setInventory(Inventory * aInventory)
{
    inventory = aInventory;
}
