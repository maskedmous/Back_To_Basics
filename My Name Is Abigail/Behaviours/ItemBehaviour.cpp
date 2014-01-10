#include "ItemBehaviour.hpp"

#include <iostream>


ItemBehaviour::ItemBehaviour(GameObject * aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem)
:	Behaviour( aParent ), tipSystem(aTipsystem)
{
    world = aWorld;
    parent = aParent;
    inventory = aInventory;
}

ItemBehaviour::~ItemBehaviour()
{
    //dtor
}

void ItemBehaviour::update(float step ){


}

void ItemBehaviour::onCollision( GameObject * otherGameObject )
{
	tipSystem->getTip(parent->getName());

	world->remove(parent);
    inventory->addToInventory(parent);
}

