#include <sfml/window.hpp>
#include <iostream>
#include "PlayerController.hpp"
#include "../GameObject.hpp"


PlayerController::PlayerController( GameObject * aParent, sf::Window * aWindow, Renderer * aRenderer, World * aWorld , Inventory* aInventory)
:   Behaviour( aParent ), window(aWindow), renderer(aRenderer), world(aWorld),inventory(aInventory) , mouseInWorld(0.0f, 0.0f, 0.0f, 1.0f), targetItem(NULL) ,mouseState("Standby")
{}

PlayerController::~PlayerController()
{}

void PlayerController::update(float step)
{
    //if left mouse button is cliked
    if(mouseState == "Standby")
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            //call on mouse down
            OnMouseDown();
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

    if(sf::Keyboard::isKeyPressed( sf::Keyboard::Right))
    {
        parent->translate( glm::vec3(3.0f * step, 0.0f, 0.0f));
    }
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::Left))
    {
        parent->translate( glm::vec3(-3.0f * step, 0.0f, 0.0f));
    }

    if(targetItem != NULL)
    {
        checkPosition();
        moveCharacter(step);
    }
}

void PlayerController::OnMouseDown()
{
	//middle = 0,0
	glm::ivec2 screenPosition = glm::ivec2( sf::Mouse::getPosition( *window ).x, sf::Mouse::getPosition( *window ).y );
    glm::vec2 mousePosition = glm::vec2(screenPosition.x, screenPosition.y);

    glm::vec2 screen = glm::vec2( 800, 600);
    glm::mat4 projection = glm::perspective( 45.0f, 4.0f/3.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    //get mouse coord in cam space
    glm::vec3 point;
    point.x = -( 2.0f * mousePosition.x / screen.x - 1) / projection[0][0];
    point.y = (2.0f * mousePosition.y / screen.y - 1) / projection[1][1];
    point.z = 1.0f;

    //from cam space to world space by inverse view
    glm::mat4 inverseView = glm::inverse(view);
    glm::vec3 rayDirection = glm::normalize( glm::vec3( inverseView * glm::vec4( point, 0.0f)));
    glm::vec3 rayOrigin = glm::vec3( inverseView * glm::vec4 (0.0f, 0.0f, 0.0f, 1.0f) );


    std::cout << "Ray Direction: " << rayDirection << std::endl;
    std::cout << "Ray Origin: " << rayOrigin << std::endl;

    //check for collision
    GameObject * collided = world->checkCollision(rayOrigin, rayDirection);

    if(collided != NULL)
    {
        std::cout << collided->getName() << std::endl;
        targetItem = collided;
        mouseInWorld = glm::vec4(collided->getLocation(), 1.0);
    }
    else
    {
        std::cout << "Did not collide" << std::endl;
    }
    //set the mouseInWorld to the coordinates of the ray
    //mouseInWorld.x = rayWorld.x;
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
            parent->translate(glm::vec3(1.0f * step, 0.0f, 0.0f));
        }
        else
        {
            //mouse position is at the left side of the character
            parent->translate(glm::vec3(-1.0f * step, 0.0f, 0.0f));
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
        inventory->addToInventory(targetItem, world);
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

    //list of mergable items
    //if( itemA == "" && itemB == "") merge();
}

std::vector< GameObject * > PlayerController::getInventory()
{
    return items;
}
