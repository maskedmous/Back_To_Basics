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
:	window( aWindow ), game(aGame), inventory(NULL), audioPlayer(NULL)
{
	assert ( window != NULL );

    if ( theHUDTex.loadFromFile("models/HUD.png") ) //when successful loaded
    {
		theHUD.setTexture( theHUDTex);                      //set the texture of the sprite
		theHUD.setPosition(0,window->getSize().y - 200);    //place the sprite note: top left corner
    }
    else { std::cout << "Could not load HUD.png" << std::endl; }

    if ( introTex.loadFromFile("models/intro.png"))
    {
        intro.setTexture(introTex);
        intro.setPosition(0,0);
    }


    if(selectionTex.loadFromFile("models/selection.png"))
    {
        selection.setTexture(selectionTex);
    }
    else { std::cout << "could not load selection.png" << std::endl; }

    if(tipBackgroundTex.loadFromFile("models/backgroundText.png"))
    {
        tipBackground.setTexture(tipBackgroundTex);
        tipBackground.setPosition(0, 480);
    }

    if(font.loadFromFile("Fonts/Cardinal.ttf"))
    {
        //setFont(itemNameText, font);
        itemNameText.setFont(font);
        tipText.setFont(font);
    }
    else { std::cout << "could not load this font" << std::endl; }

    resumeButton = new Button("models/resumeButton.png", glm::vec2(840, (window->getSize().y / 2 - 150)));
    addButtonToIngameMenu(resumeButton);

    quitToMenuButton = new Button("models/quitbutton.png", glm::vec2(840, (window->getSize().y / 2 + 50)));
    addButtonToIngameMenu(quitToMenuButton);

    firstTrigger = 999;
    slot1Trigger = false;
    slot2Trigger = false;
    slot3Trigger = false;
    slot4Trigger = false;
    slot5Trigger = false;

    mouseState = "Standby";
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

    if(game->getState() == "Intro")
    {
        window->draw(intro);
    }

    //get the inventory
    if(game->getState() == "Play")
    {
        window->draw( theHUD );
        std::vector< GameObject * > items = inventory->getInventory();

		//draw inventory
		int position = 0;                   //int cause round numbers

		for(unsigned int i=0; i<items.size(); ++i)
        {
            //preventing more than 5 items being drawn (optimization / error prevention)
            if(i <= 4)
            {
                sf::Texture thisItemTex;
                sf::Sprite thisItemSprite;
                thisItemSprite.setScale( 1, -1);    //flip the sprite its flipped in the world

                GameObject * thisItem = items[i];
                thisItemTex.loadFromImage( Texture::getImage( (thisItem->getTexture()->getName()).c_str() ) );
                thisItemSprite.setTexture( thisItemTex );
                position = (10 + ((i+1) * 85) + (i * 150));
                thisItemSprite.setPosition( position, window->getSize().y - 25 );
                window->draw(thisItemSprite);
            }
        }

        if(slot1Trigger)
        {
            selection.setPosition(90, 540);
            window->draw(selection);
        }
        if(slot2Trigger)
        {
            selection.setPosition(325, 540);
            window->draw(selection);
        }
        if(slot3Trigger)
        {
            selection.setPosition(560, 540);
            window->draw(selection);
        }
        if(slot4Trigger)
        {
            selection.setPosition(795, 540);
            window->draw(selection);
        }
        if(slot5Trigger)
        {
            selection.setPosition(1030, 540);
            window->draw(selection);
        }


        glm::vec2 mousePosition = glm::vec2(glm::ivec2(sf::Mouse::getPosition( *window ).x, sf::Mouse::getPosition( *window ).y));

        if(mousePosition.y > 520)
        {
            std::string itemName;
            //inventory space
            //where did it click? any inventory slots?
            if(mousePosition.x > 95 && mousePosition.x < 245)
            {
                itemName = inventory->getItemName(0);
            }
            if(mousePosition.x > 330 && mousePosition.x < 480)
            {
                itemName = inventory->getItemName(1);
            }
            if(mousePosition.x > 565 && mousePosition.x < 715)
            {
                itemName = inventory->getItemName(2);
            }
            if(mousePosition.x > 800 && mousePosition.x < 950)
            {
                itemName = inventory->getItemName(3);
            }
            if(mousePosition.x > 1035 && mousePosition.x < 1185)
            {
                itemName = inventory->getItemName(4);
            }
            itemNameText.setCharacterSize(30);
            itemNameText.setColor(sf::Color::White);
            itemNameText.setString(itemName);
            itemNameText.setPosition((mousePosition.x+10), mousePosition.y);
            window->draw(itemNameText);
        }

        if(tipBool)
        {
            window->draw(tipBackground);
            tipText.setCharacterSize(40);
            tipText.setColor(sf::Color::White);
            tipText.setPosition(5, 475);
            window->draw(tipText);
        }
    }

    if(game->getState() == "Ingame Menu")
    {
        window->draw( theHUD );
        for(unsigned int k = 0; k<ingameMenuButtons.size(); ++k)
        {
            Button * ingameButton = ingameMenuButtons[k];
            window->draw(ingameButton->getButtonSprite());
        }

        glm::vec2 mousePosition = glm::vec2(glm::ivec2(sf::Mouse::getPosition(* window).x, sf::Mouse::getPosition(* window).y));

        if(mouseState == "Standby")
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
                if(resumeButton->hitButton(mousePosition))
                {
                    game->setState("Play");
                    std::cout << "setting state to play" << std::endl;
                }
                if(quitToMenuButton->hitButton(mousePosition))
                {

                    std::cout << "End Game" << std::endl;
                    tipBool = false;
                    tipText.setString("");
                    tipTimer = 0;
                    game->setState("GoToMenu");
                }
                mouseState = "Down";
            }
        }
         //if it is down
        if(mouseState == "Down")
         {
             //check if it is up
            if(! sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
                 //mouse is up so put it back to standby
                mouseState = "Standby";
             }
         }
    }

    window->draw( text );
	window->popGLStates();
}

void Hud::setSlotTrigger()
{
    glm::vec2 mousePosition = glm::vec2(glm::ivec2(sf::Mouse::getPosition( *window ).x, sf::Mouse::getPosition( *window ).y));

    if(mousePosition.y > 520)
    {
        if(firstTrigger == 999)
        {
            //inventory space
            //where did it click? any inventory slots?
            if(mousePosition.x > 95 && mousePosition.x < 245)
            {
                if(inventory->checkValidItemIndex(0))
                {
                    slot1Trigger = true;
                    firstTrigger = 0;
                }
            }
            if(mousePosition.x > 330 && mousePosition.x < 480)
            {
                if(inventory->checkValidItemIndex(1))
                {
                    slot2Trigger = true;
                    firstTrigger = 1;
                }
            }
            if(mousePosition.x > 565 && mousePosition.x < 715)
            {
                if(inventory->checkValidItemIndex(2))
                {
                    slot3Trigger = true;
                    firstTrigger = 2;
                }
            }
            if(mousePosition.x > 800 && mousePosition.x < 950)
            {
                if(inventory->checkValidItemIndex(3))
                {
                    slot4Trigger = true;
                    firstTrigger = 3;
                }
            }
            if(mousePosition.x > 1035 && mousePosition.x < 1185)
            {
                if(inventory->checkValidItemIndex(4))
                {
                    slot5Trigger = true;
                    firstTrigger = 4;
                }
            }
        }
        else
        {
            //there is already an item selected!
            if(mousePosition.x > 95 && mousePosition.x < 245)
            {
                if(slot1Trigger != true && inventory->checkValidItemIndex(0))
                {
                    itemA = inventory->getFromInventory(firstTrigger);
                    itemB = inventory->getFromInventory(0);
                }
            }
            if(mousePosition.x > 330 && mousePosition.x < 480)
            {
                if(slot2Trigger != true && inventory->checkValidItemIndex(1))
                {
                    itemA = inventory->getFromInventory(firstTrigger);
                    itemB = inventory->getFromInventory(1);
                }
            }
            if(mousePosition.x > 565 && mousePosition.x < 715)
            {
                if(slot3Trigger != true && inventory->checkValidItemIndex(2))
                {
                    itemA = inventory->getFromInventory(firstTrigger);
                    itemB = inventory->getFromInventory(2);
                }
            }
            if(mousePosition.x > 800 && mousePosition.x < 950)
            {
                if(slot4Trigger != true && inventory->checkValidItemIndex(3))
                {
                    itemA = inventory->getFromInventory(firstTrigger);
                    itemB = inventory->getFromInventory(3);
                }
            }
            if(mousePosition.x > 1035 && mousePosition.x < 1185)
            {
                if(slot5Trigger != true && inventory->checkValidItemIndex(4))
                {
                    itemA = inventory->getFromInventory(firstTrigger);
                    itemB = inventory->getFromInventory(4);
                }
            }

            if(itemA != NULL && itemB != NULL)
            {
                if(inventory->mergeItems(itemA, itemB))
                {
                    std::cout << "I merged items!" << std::endl;
                    audioPlayer->Play("merge", false);
                }
                else
                {
                    std::cout << "I failed merging items" << std::endl;
                    audioPlayer->Play("negativemerge", false);
                }
            }
            else
            {
                std::cout <<  "I failed merging items" << std::endl;
                audioPlayer->Play("negativemerge", false);
            }
            //reset slots!
            firstTrigger = 999;
            itemA = NULL;
            itemB = NULL;
            slot1Trigger = false;
            slot2Trigger = false;
            slot3Trigger = false;
            slot4Trigger = false;
            slot5Trigger = false;
        }
    }
}

void Hud::setInventory(Inventory * aInventory)
{
    inventory = aInventory;
}

void Hud::addButtonToMainMenu(Button * newButton)
{
    mainMenuButtons.push_back(newButton);
}

void Hud::addButtonToIngameMenu(Button * newButton)
{
    ingameMenuButtons.push_back(newButton);
}

void Hud::setTip(std::string aTip)
{
    tipText.setString(aTip);
    tipBool = true;
    tipTimer = 6;
}

void Hud::countdown(float step)
{
    if(tipTimer >= 0)
    {
        tipTimer -= step;
    }
    else
    {
        tipBool = false;
        tipText.setString("");
    }
}

void Hud::setAudioPlayer(AudioPlayer * m_audioPlayer)
{
    audioPlayer = m_audioPlayer;
    std::cout << "Setting the audioplayer!!" << audioPlayer << std::endl;
}
