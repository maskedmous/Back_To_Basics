#include <sfml/window.hpp>
#include <iostream>
#include "../Texture.hpp"
#include "PlayerController.hpp"
#include "../GameObject.hpp"

PlayerController::PlayerController( GameObject * aParent, sf::Window * aWindow, Renderer * aRenderer, World * aWorld , Inventory* aInventory, Hud * aHud)
:   Behaviour( aParent ), window(aWindow), renderer(aRenderer), world(aWorld),inventory(aInventory) , hud(aHud),mouseInWorld(0.0f, 0.0f, 0.0f, 1.0f), targetItem(NULL) ,mouseState("Standby") , interactButton("Standby")
{
    ableToMove = true;
    animation.push_back(Texture::load("models/AbigailsideLeft.png"));
    animation.push_back(Texture::load("models/AbigailsideRight.png"));
    animation.push_back(Texture::load("models/AbigailIdle.png"));
    parent->setColorMap(animation[2]);
    characterState = intro;
}

PlayerController::~PlayerController()
{}

void PlayerController::update(float step)
{
    if(characterState == intro)
    {
        if(interactButton == "Standby")
        {
            if((sf::Keyboard::isKeyPressed( sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed( sf::Keyboard::Space)))
            {
                //set the game state to "play"
                setState(2);
                interactButton = "Down";
            }
        }
        //if it is down
        if(interactButton == "Down")
        {
            //check if it is up
            if(!sf::Keyboard::isKeyPressed( sf::Keyboard::W) && (!sf::Keyboard::isKeyPressed( sf::Keyboard::Space)))
            {
                //mouse is up so put it back to standby
                interactButton = "Standby";
            }
        }
    }

    if(characterState == frozen)
    {
        if(interactButton == "Standby")
        {
            if((sf::Keyboard::isKeyPressed( sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed( sf::Keyboard::Space)))
            {
                //call on mouse down
                interactButton = "Down";
            }
        }
        //if it is down
        if(interactButton == "Down")
        {
            //check if it is up
            if(!sf::Keyboard::isKeyPressed( sf::Keyboard::W) && (!sf::Keyboard::isKeyPressed( sf::Keyboard::Space)))
            {
                //mouse is up so put it back to standby
                interactButton = "Standby";
            }
        }
    }

    if(characterState == moving)
    {
        //if left mouse button is cliked
        if(mouseState == "Standby")
         {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
                hud->setSlotTrigger();  //merge items
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
                interactButton = "Standby";
             }
         }


        if(interactButton == "Standby")
        {
            if((sf::Keyboard::isKeyPressed( sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed( sf::Keyboard::Space)))
            {
                //call on mouse down
                InteractWithObject();
                interactButton = "Down";
            }
        }
        //if it is down
        if(interactButton == "Down")
        {
            //check if it is up
            if(!sf::Keyboard::isKeyPressed( sf::Keyboard::W) && (!sf::Keyboard::isKeyPressed( sf::Keyboard::Space)))
            {
                //mouse is up so put it back to standby
                interactButton = "Standby";
            }
        }

        oldPos = parent->getLocation();

        if((sf::Keyboard::isKeyPressed( sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
        {
            parent->translate( glm::vec3(3.0f * step, 0.0f, 0.0f));
            //std::cout << "right is loved" << std::endl;
                if(parent->getTexture()->getName() != "models/AbigailsideRight.png")
                {
                    parent->setColorMap(animation[1]);
                }
        }
        if((sf::Keyboard::isKeyPressed( sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
        {
            parent->translate( glm::vec3(-3.0f * step, 0.0f, 0.0f));
            //std::cout << "left is loved" << std::endl;
            if(parent->getTexture()->getName() != "models/AbigailsideLeft.png")
            {
                parent->setColorMap(animation[0]);
            }
        }

        if(targetItem != NULL)
        {
            checkPosition();
            moveCharacter(step);
        }
    }
}

void PlayerController::InteractWithObject(){

    world->checkCollision(parent);


}

void PlayerController::OnMouseDown()
{
    hud->setSlotTrigger();
    glm::vec2 mousePosition = glm::vec2(glm::ivec2(sf::Mouse::getPosition( *window ).x, sf::Mouse::getPosition( *window ).y));
    //if the click is within the inventory space dont check for collision
    if(mousePosition.y > 520)
    {
        //do nothing
    }
    else
    {
        world->checkCollision(parent);
    }
}

void PlayerController::onCollision(GameObject * otherObject)
{

}


void PlayerController::onBlock(){
    parent->setPosition(oldPos);
}

//moves the character where the user has clicked last
void PlayerController::moveCharacter(float step)
{
    float distance = glm::abs(mouseInWorld.x - parent->getLocation().x);
    if(distance > 0.01f)
    {
        if(mouseInWorld.x > parent->getLocation().x)
        {
            //mouse position is at the right side of the character
            parent->translate(glm::vec3(3.0f * step, 0.0f, 0.0f));

        }
        else
        {
            //mouse position is at the left side of the character
            parent->translate(glm::vec3(-3.0f * step, 0.0f, 0.0f));

        }
    }

}

void PlayerController::checkPosition()
{
    //check the distance between character and the item
    float distance = glm::abs(mouseInWorld.x - parent->getLocation().x);
    if(distance < 0.01f)
    {
        //add item to inventory cause you're near it
        inventory->addToInventory(targetItem);
        targetItem = NULL;
    }
    else
    {
        //move character (is in update)
    }
}


void PlayerController::mergeItems(GameObject * itemA, GameObject * itemB)
{
    std::cout << "Merging: " << itemA->getName() << " with " << itemB->getName() << std::endl;
}

std::vector< GameObject * > PlayerController::getInventory()
{
    return items;
}

void PlayerController::setAbleToMove()
{
    if(ableToMove == true){
        ableToMove = false;
    } else
    {
        ableToMove = true;
    }
}

void PlayerController::setState(int aState)
{
    if(aState == 0)
    {
        characterState = intro;
    }
    if(aState == 1)
    {
        characterState = frozen;
        parent->setColorMap(animation[2]);
    }
    if(aState == 2)
    {
        characterState = moving;
    }
}
