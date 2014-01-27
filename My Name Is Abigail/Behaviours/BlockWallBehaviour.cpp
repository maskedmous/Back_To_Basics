#include "BlockWallBehaviour.hpp"

#include <iostream>


BlockWallBehaviour::BlockWallBehaviour(GameObject * aParent)
:	Behaviour( aParent )
{}

BlockWallBehaviour::~BlockWallBehaviour()
{
    //dtor
}

void BlockWallBehaviour::update(float step )
{
}

void BlockWallBehaviour::onCollision( GameObject * otherGameObject )
{
	otherGameObject->getBehaviour()->onBlock();
}

