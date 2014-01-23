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
    invading = false;
    firstInvade = true;

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
    audioPlayer->Play("infiltrate", false);
    if(invading == false){
        if(parent->getName() == "Earnest"){
            audioPlayer->PlayMusic("ernestInvadeMusic");
        }
        if(parent->getName() == "Grace"){
            audioPlayer->PlayMusic("holyGrace");
        }
        tipSystem->getTip(parent->getName());
        invading = true;
    }else {
        audioPlayer->PlayMusic("musicAct1");
        invading = false;
        if((firstInvade == true) && (parent->getName() == "Earnest")){
            audioPlayer->Play("3_Meeting_Ernest_2", false);
            firstInvade = false;
        }
    }

    otherGameObject->getBehaviour()->setAbleToMove();
    GameObject * randomGameObject = world->findGameObject(responder);
    randomGameObject->getBehaviour()->swapTexture();

    if(parent->getName() == "Earnest"){
        std::string anotherName = "EntranceHallLayer2";
        GameObject * moreGameObjects = world->findGameObject(anotherName);
        moreGameObjects->getBehaviour()->swapTexture();
    }
}

