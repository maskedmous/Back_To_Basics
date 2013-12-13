#include "DoorBehaviour.hpp"

#include <iostream>


DoorBehaviour::DoorBehaviour(GameObject * aParent, World* aWorld)
:	Behaviour( aParent )
{
    world = aWorld;
    parent = aParent;
}

DoorBehaviour::~DoorBehaviour()
{
    //dtor
}

void DoorBehaviour::update(float step ){


}

void DoorBehaviour::onCollision( GameObject * otherGameObject )
{
	std::cout << "i am a door!" << std::endl;
	world->remove(parent);
}

