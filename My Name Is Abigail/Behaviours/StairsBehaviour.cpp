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
    countdown = false;
}

StairsBehaviour::~StairsBehaviour()
{
    //dtor
}

void StairsBehaviour::update(float step ){
    if(countdown == true){
        if(blackScreencountdown <= 0){
            std::string objName = "BlackScreen";
            GameObject * blackWallObj = world->findGameObject(objName);
            blackWallObj->setPosition ( glm::vec3(0,0,-10) );
            countdown = false;

            std::string charName = "Character";
            GameObject * charObj = world->findGameObject(charName);
            charObj->getBehaviour()->setState(2);
        }
        else {
            blackScreencountdown = blackScreencountdown - step;
        }
    }
}

void StairsBehaviour::onCollision( GameObject * otherGameObject )
{
    GameObject * otherStairObject = world->findGameObject(stairsExit);
    otherGameObject->setPosition ( glm::vec3(otherStairObject->getLocation().x, otherStairObject->getLocation().y -1.45, otherGameObject->getLocation().z) );
    otherGameObject->getBehaviour()->setState(1);
    audioPlayer->Play("walkStairway",false);

    std::string objName = "BlackScreen";
    GameObject * blackWallObj = world->findGameObject(objName);
    blackWallObj->setPosition ( glm::vec3(otherStairObject->getLocation().x, otherStairObject->getLocation().y, 1) );
    countdown = true;
    blackScreencountdown = 1;


    /*
    if(upOrDown == true){
        otherGameObject->translate( glm::vec3(-3.0f , 4.0f, 0.0f));

    }
    if(upOrDown == false){
        otherGameObject->translate( glm::vec3(3.0f , -4.0f, 0.0f));

    }
    */
}


