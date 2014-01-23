#include "ItemBehaviour.hpp"

#include <iostream>


ItemBehaviour::ItemBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer)
:	Behaviour( aParent ), tipSystem(aTipsystem)
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
    audioPlayer = aAudioPlayer;
}

ItemBehaviour::~ItemBehaviour()
{
    //dtor
}

void ItemBehaviour::update(float step ){


}

void ItemBehaviour::onCollision( GameObject * otherGameObject )
{
	tipSystem->getFeedback(parent->getName());
    audioPlayer->Play("pickUpItem", false);
	world->remove(parent);
    inventory->addToInventory(parent);

    if(parent->getName() == "Suicidenote"){
        audioPlayer->Play("5_Find_Note",false);
    }
}

