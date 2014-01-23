#include "DoorBehaviour.hpp"

#include <iostream>

#include <string>

DoorBehaviour::DoorBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory , TipSystem * aTipsystem, AudioPlayer * aAudioPlayer, const std::string recievedItemName)
:	Behaviour( aParent ), tipSystem(aTipsystem)
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
    audioPlayer = aAudioPlayer;
    tipSystem = aTipsystem;
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
        audioPlayer->Play("puzzleSolved", false);
        //std::cout << "using the item the door opens" << std::endl;

        if(parent->getName() == "lanternoff"){

            std::string toFindKey = "CellarKey";
            GameObject * cellerKey = world->findGameObject(toFindKey);
            cellerKey->setPosition(glm::vec3(16.5, -3.45, 0.15));

            std::string ddd = "StorageRoomDARK";
            GameObject * randomGameObject = world->findGameObject(ddd);
            randomGameObject->getBehaviour()->swapTexture();

    	}

    	if(parent->getName() == "storage-CellarDoor"){
            std::string removeOne = "BlockWallMainCellar";
            world->remove(removeOne);

            std::string removeTwo = "triggerBasementDoor";
            world->remove(removeTwo);
    	}

    	if(parent->getName() == "chest"){
    	    std::string ItemName = "thread";
    	    GameObject * threadObj = world->findGameObject(ItemName);
            tipSystem->getFeedback(threadObj->getName());
            inventory->addToInventory(threadObj);
    	}

        if(parent->getName() == "fire"){

            std::string removeTwo = "fireAnimation";
            world->remove(removeTwo);

            std::string removeTrigger = "fireTrigger";
            world->remove(removeTrigger);

            std::string keyname = "stone";
    	    GameObject * stoneObj = world->findGameObject(keyname);
            stoneObj->setPosition(parent->getLocation());
            tipSystem->sendTip("Hey a stone! maybe i should pick it up");



            //inventory->addToInventory(key2);

        }
        if(parent->getName() == "MasterBedRoomDoor"){
            std::string keyname = "BlockWallMasterBedRoom";
            world->remove(keyname);
            audioPlayer->Play("destroyDoor",false);
            audioPlayer->PlayMusic("masterBedroomMusic");
    	    //GameObject * key2 = world->findGameObject(keyname);
            //key2->setPosition(parent->getLocation());

        }
        /*
        if(parent->getName() == "MasterBedRoomDoor2"){
            std::string keyname = "BlockWallMasterBedRoom2";
    	    GameObject * key2 = world->findGameObject(keyname);
            key2->setPosition(parent->getLocation());
        }
*/
    	world->remove(parent);
    	inventory->removeFromInventory(requiredItem);



    } else {
        tipSystem->getTip(parent->getName());
        //tipSystem->sendTip("You Might need an item to open this door");
        //std::cout << "You Might need an item to open this door, you need " << requiredItem <<  std::endl;


    }
 }

