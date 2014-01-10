#include "DoorBehaviour.hpp"

#include <iostream>

#include <string>

DoorBehaviour::DoorBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory , TipSystem * aTipsystem, const std::string recievedItemName)
:	Behaviour( aParent ), tipSystem(aTipsystem)
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
        std::cout << parent->getName() << "WTF IS GOING ON!" << std::endl;
        tipSystem->getTip(parent->getName());

        std::cout << "using the item the door opens" << std::endl;

        if(parent->getName() == "lanternoff"){
            std::string bbb = "BlockWall2";
            world->remove(bbb);


            std::string ddd = "wallName5";
            GameObject * randomGameObject = world->findGameObject(ddd);

            randomGameObject->getBehaviour()->swapTexture();



    	}

    	//world->remove(parent);
    	inventory->removeFromInventory(requiredItem);



    } else std::cout << "You Might need an item to open this door, you need " << requiredItem <<  std::endl;
}

