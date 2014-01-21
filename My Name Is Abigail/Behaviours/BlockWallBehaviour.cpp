#include "BlockWallBehaviour.hpp"

#include <iostream>


BlockWallBehaviour::BlockWallBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer)
:	Behaviour( aParent ), tipSystem(aTipsystem)
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
    audioPlayer = aAudioPlayer;

}

BlockWallBehaviour::~BlockWallBehaviour()
{
    //dtor
}

void BlockWallBehaviour::update(float step ){
	//std::cout << "TRIGGERD GAWD DAMN IT" << std::endl;

}

void BlockWallBehaviour::onCollision( GameObject * otherGameObject )
{
	//std::cout << "TRIGGERD GAWD DAMN IT" << std::endl;
	otherGameObject->getBehaviour()->onBlock();
	//world->remove(parent);
    //inventory->addToInventory(parent);

}

