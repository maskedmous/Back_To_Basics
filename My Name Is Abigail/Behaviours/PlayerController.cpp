#include <sfml/window.hpp>
#include <iostream>
#include "PlayerController.hpp"
#include "../GameObject.hpp"


PlayerController::PlayerController( GameObject * aParent, sf::Window * aWindow, Renderer * aRenderer, World * aWorld)
:   Behaviour( aParent ), window(aWindow), renderer(aRenderer), world(aWorld), mouseInWorld(0.0f, 0.0f, 0.0f, 1.0f), targetItem(NULL) ,mouseState("Standby")
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

    moveCharacter(step);

    if(targetItem != NULL)
    {
        checkPosition();
    }
}

void PlayerController::OnMouseDown()
{
    //std::cout << "Left MouseButton Clicked" << std::endl;
	//middle = 0,0
	glm::ivec2 screenPosition = glm::ivec2( sf::Mouse::getPosition( *window ).x - (window->getSize().x / 2) , sf::Mouse::getPosition( *window ).y - (window->getSize().y / 2) );
    glm::vec4 mousePosition = glm::vec4(screenPosition.x, screenPosition.y, 6, 1);
    //range -1, 1
    mousePosition.x = mousePosition.x / (window->getSize().x / 2);
    mousePosition.y = mousePosition.y / (window->getSize().y / 2);
    //inverse matrix
    //glm::mat4 inverseMatrix = glm::inverse(renderer->getView()) * glm::inverse(renderer->getProjection());
    //apply inversed matrix
    //mouseInWorld = inverseMatrix * mousePosition;

    //ray in clip space (screen space)
    glm::vec4 rayClip = glm::vec4(mousePosition.x, mousePosition.y, -1.0, 1.0);
    //ray in eye space
    glm::vec4 rayEye = glm::inverse(renderer->getProjection()) * rayClip;
    //direction of the ray
    rayEye = glm::vec4(rayEye.x, rayEye.y, -1.0, 0.0);

    glm::vec3 rayWorld = glm::vec3(glm::inverse(renderer->getView()) * rayEye);
    rayWorld = glm::normalize(rayWorld);

    //std::cout << rayWorld << std::endl;

    //check for collision
    GameObject * collided = world->checkCollision(rayWorld);

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
        addToInventory(targetItem);
    }
    else
    {
        //move character (is in update)
    }
}

void PlayerController::addToInventory(GameObject * item)
{
    std::cout << "Obtained: " << item->getName() << std::endl;
    items.push_back(item);
    targetItem = NULL;
}
