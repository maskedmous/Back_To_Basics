#include <cassert>
#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <vector>
#include "FPS.hpp"
#include "Hud.hpp"
#include "Behaviour.hpp"
#include "Behaviours/PlayerController.hpp"

Hud::Hud( sf::RenderWindow * aWindow )
:	window( aWindow )
{
	assert ( window != NULL );

    if ( theHUDTex.loadFromFile("models/HUD.png") ) { // when succesfull loaded
		theHUD.setTexture( theHUDTex); // provide sprite with texture
		theHUD.setPosition(0,window->getSize().y - 200); // put it somewhere anoying
    } else {
		std::cout << "Coulf not load sprite" << std::endl;
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
    //    std::vector< GameObject * > items = character->getInventory();

		//draw inventory
	//	for(unsigned int i=0; i<items.size(); ++i)
       // {
        //    GameObject * thisItem = items[i];
        //    sf::Texture thisItemTex = thisItem->getTexture();
        //    sf::Sprite thisItemSprite;
        //    thisItemSprite.setTexture( thisItemTex );
        //    thisItemSprite.setPosition( 33 + (i * 133), window->getSize().y - 200 );
        //}

		window->draw( text );
	window->popGLStates();
}

void Hud::setCharacter(Behaviour * aCharacterController)
{
    characterController = aCharacterController;
}
