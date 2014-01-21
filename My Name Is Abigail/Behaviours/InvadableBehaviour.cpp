#include "InvadableBehaviour.hpp"

#include <iostream>


InvadableBehaviour::InvadableBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer ,std::string respondingObject)
:	Behaviour( aParent ), tipSystem(aTipsystem)
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
    responder = respondingObject;
    audioPlayer = aAudioPlayer;

}

InvadableBehaviour::~InvadableBehaviour()
{
    //dtor
}

void InvadableBehaviour::update(float step ){

}

void InvadableBehaviour::onCollision( GameObject * otherGameObject )
{
	tipSystem->getTip(parent->getName());
	//std::cout  << "hey im a NPC" << std::endl;

    //std::string ddd = "wallName5";
    audioPlayer->Play("creakingdoor", false);
    otherGameObject->getBehaviour()->setAbleToMove();
    GameObject * randomGameObject = world->findGameObject(responder);
    randomGameObject->getBehaviour()->swapTexture();

}

