#include "TriggerBehaviour.hpp"

#include <iostream>


TriggerBehaviour::TriggerBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer, int aInt, std::string aString = "")
:	Behaviour( aParent ), tipSystem(aTipsystem)
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
    audioPlayer = aAudioPlayer;
    soundToPlay = aString;

    reUseTrigger = true;
    continuous = false;
    countdown = aInt;

    if(countdown == 0) {
        reUseTrigger = false;
    }
    if(countdown < 0){
        continuous = true;
    }
    active = true;;
}

TriggerBehaviour::~TriggerBehaviour()
{
    //dtor
}

void TriggerBehaviour::update(float step ){
	//std::cout << "TRIGGERD GAWD DAMN IT" << std::endl;
	if(reUseTrigger == true){
        if(active == false){
            //std::cout << countdown << std::endl;
            if(countdown > 0){
                countdown -= 1 * step;
            }
            if(countdown <= 0){
                countdown = 0;
                active = true;
            }
        }
	}

}

void TriggerBehaviour::onCollision( GameObject * otherGameObject )
{
	//std::cout << "TRIGGERD GAWD DAMN IT" << std::endl;

    if(active == true){
        tipSystem->getTip(parent->getName());
        if(soundToPlay != "NULL"){
            if(audioPlayer->CheckStatus() != 2){
                //std::cout << audioPlayer->CheckStatus() << std::endl;
                audioPlayer->Play(soundToPlay,false);
            }
        }
        if(continuous == false){
            active = false;
            countdown = 30;
        }
    }
	//world->remove(parent);
    //inventory->addToInventory(parent);

}

