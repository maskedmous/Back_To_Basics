#include "ItemBehaviour.hpp"

#include <iostream>


ItemBehaviour::ItemBehaviour(GameObject * aParent, World* aWorld)
:	Behaviour( aParent )
{
    world = aWorld;
    parent = aParent;
}

ItemBehaviour::~ItemBehaviour()
{
    //dtor
}

void ItemBehaviour::update(float step ){


}

void ItemBehaviour::onCollision( GameObject * otherGameObject )
{
	std::cout << "i am a ITEM!" << std::endl;
	world->remove(parent);
}

