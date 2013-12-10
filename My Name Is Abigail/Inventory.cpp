#include "Inventory.hpp"

Inventory::Inventory()
{
    //ctor
}

Inventory::~Inventory()
{
    //dtor
}

void Inventory::addToInventory(GameObject * item, World* world)
{
    std::cout << "Obtained: " << item->getName() << std::endl;
    items.push_back(item);
    world->remove(item);
    //targetItem = NULL;
    //std::cout << items << std::endl;
}
