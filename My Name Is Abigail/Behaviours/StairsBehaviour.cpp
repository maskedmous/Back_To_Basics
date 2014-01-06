#include "StairsBehaviour.h"

#include <iostream>


StairsBehaviour::StairsBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory)
:	Behaviour( aParent )
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
}

StairsBehaviour::~StairsBehaviour()
{
    //dtor
}

void StairsBehaviour::update(float step ){


}

void StairsBehaviour::onCollision( GameObject * otherGameObject )
{
	//std::cout << "You walk up the Stairs!" <<  std::endl;
    otherGameObject->translate( glm::vec3(0.0f , 4.0f, 0.0f));
    //otherGameObject->getLocation().x;
	//otherGameObject->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	//world->remove(parent);
    //inventory->addToInventory(parent, world);
}


