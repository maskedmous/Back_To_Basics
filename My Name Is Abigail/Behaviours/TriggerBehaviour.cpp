#include "TriggerBehaviour.hpp"

#include <iostream>


TriggerBehaviour::TriggerBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer, std::string aString)
:	Behaviour( aParent ), tipSystem(aTipsystem)
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
    audioPlayer = aAudioPlayer;
    soundToPlay = aString;

    countdown = 0;
    active = false;
}

TriggerBehaviour::~TriggerBehaviour()
{
    //dtor
}

void TriggerBehaviour::update(float step ){
	//std::cout << "TRIGGERD GAWD DAMN IT" << std::endl;
	if(active){
	    std::cout << countdown << std::endl;
        if(countdown > 0){
            countdown -= 1 * step;
        }
        if(countdown <= 0){
            countdown = 0;
            parent->translate(glm::vec3(0,100,0));
            active = false;
        }
	}

}

void TriggerBehaviour::onCollision( GameObject * otherGameObject )
{
	//std::cout << "TRIGGERD GAWD DAMN IT" << std::endl;
	tipSystem->getTip(parent->getName());
	audioPlayer->Play(soundToPlay,false);
	parent->translate(glm::vec3(0,-100,0));
	active = true;
	countdown = 50;

	//world->remove(parent);
    //inventory->addToInventory(parent);

}

