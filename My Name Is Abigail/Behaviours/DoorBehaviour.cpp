#include "DoorBehaviour.hpp"

#include <iostream>

#include <string>

DoorBehaviour::DoorBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory , const std::string recievedItemName)
:	Behaviour( aParent )
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
    requiredItem = recievedItemName;
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
    myString = "Key";
    if(inventory->CheckContainItem(requiredItem)){
        std::cout << "using the item the door opens" << std::endl;

        if(parent->getName() == "lantern"){

    	}

    	world->remove(parent);
    	inventory->removeFromInventory(requiredItem);

    } else std::cout << "You Might need an item to open this door, you need " << requiredItem <<  std::endl;
}

