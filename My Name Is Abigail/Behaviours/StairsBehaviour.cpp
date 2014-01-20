#include "StairsBehaviour.h"

#include <iostream>


StairsBehaviour::StairsBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory, AudioPlayer * aAudioPlayer, std::string aString)
:	Behaviour( aParent )
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
    stairsExit = aString;
    audioPlayer = aAudioPlayer;
}

StairsBehaviour::~StairsBehaviour()
{
    //dtor
}

void StairsBehaviour::update(float step ){


}

void StairsBehaviour::onCollision( GameObject * otherGameObject )
{
    GameObject * otherStairObject = world->findGameObject(stairsExit);
    otherGameObject->setPosition ( glm::vec3(otherStairObject->getLocation().x, otherStairObject->getLocation().y -1.45, otherGameObject->getLocation().z) );
    audioPlayer->Play("walkStairway",false);
    /*
    if(upOrDown == true){
        otherGameObject->translate( glm::vec3(-3.0f , 4.0f, 0.0f));

    }
    if(upOrDown == false){
        otherGameObject->translate( glm::vec3(3.0f , -4.0f, 0.0f));

    }
    */
}


