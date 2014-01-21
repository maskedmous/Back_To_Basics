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
        //std::cout << parent->getName() << "WTF IS GOING ON!" << std::endl;
        tipSystem->getFeedback(parent->getName());

        //std::cout << "using the item the door opens" << std::endl;

        if(parent->getName() == "lanternoff"){
            std::string bbb = "BlockWallMainCellar";
            world->remove(bbb);

            std::string ddd = "StorageRoomDARK";
            GameObject * randomGameObject = world->findGameObject(ddd);

            randomGameObject->getBehaviour()->swapTexture();

    	}
    	if(parent->getName() == "chest"){
    	    std::string keyname = "key3";
    	    GameObject * key3 = world->findGameObject(keyname);
            inventory->addToInventory(key3);
    	}

        if(parent->getName() == "fire"){
            std::string keyname = "key2";
    	    GameObject * key2 = world->findGameObject(keyname);
            key2->setPosition(parent->getLocation());
            //inventory->addToInventory(key2);
        }
        if(parent->getName() == "MasterBedRoomDoor"){
            std::string keyname = "BlockWallMasterBedRoom";
    	    GameObject * key2 = world->findGameObject(keyname);
            key2->setPosition(parent->getLocation());
        }
        if(parent->getName() == "MasterBedRoomDoor2"){
            std::string keyname = "BlockWallMasterBedRoom2";
    	    GameObject * key2 = world->findGameObject(keyname);
            key2->setPosition(parent->getLocation());
        }

    	world->remove(parent);
    	inventory->removeFromInventory(requiredItem);



    } else {
        tipSystem->getTip(parent->getName());
        //tipSystem->sendTip("You Might need an item to open this door");
        //std::cout << "You Might need an item to open this door, you need " << requiredItem <<  std::endl;


    }
 }

