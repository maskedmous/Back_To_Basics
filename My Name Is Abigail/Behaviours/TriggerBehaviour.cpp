#include "TriggerBehaviour.hpp"

#include <iostream>


TriggerBehaviour::TriggerBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer, int aInt, std::string aString = "")
:	Behaviour( aParent ), tipSystem(aTipsystem)
{
    world = aWorld;
    inventory = aInventory;
    audioPlayer = aAudioPlayer;
    soundToPlay = aString;

    reUseTrigger = true;
    continuous = false;
    isVoiceActing = false;
    countdown = aInt;

    if(countdown == 0) {
        reUseTrigger = false;
    }
    if(countdown < 0){
        continuous = true;
    }
    if(countdown == 666){
        isVoiceActing = true;
        reUseTrigger = false;
    }
    active = true;

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

        if(isVoiceActing)
        {
            audioPlayer->PlayVoicActing(soundToPlay);
            active = false;
        }

        tipSystem->getTip(parent->getName());

        if(soundToPlay != "NULL")
        {
            if(continuous == true)
            {
                if(audioPlayer->CheckStatus() != 2)
                {
                    audioPlayer->Play(soundToPlay,false);
                }
            }
            if(continuous == false)
            {
                audioPlayer->Play(soundToPlay,false);
                active = false;
                countdown = 30;
            }
        }

    }
}

