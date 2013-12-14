#include "DoorBehaviour.hpp"

#include <iostream>

#include <string>

DoorBehaviour::DoorBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory)
:	Behaviour( aParent )
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
}

DoorBehaviour::~DoorBehaviour()
{
    //dtor
}

void DoorBehaviour::update(float step ){


}

void DoorBehaviour::onCollision( GameObject * otherGameObject )
{
	std::cout << "I am a " << parent->getName() << "!" << std::endl;
    std::string myString;
    myString = "Item";
    if(inventory->CheckContainItem(myString)){
    	world->remove(parent);
    }
}

