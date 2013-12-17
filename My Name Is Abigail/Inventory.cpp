#include "Inventory.hpp"

//#include <boolean>
#include <string>

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
    //world->remove(item);
    //targetItem = NULL;
    //std::cout << items << std::endl;
}
void Inventory::removeFromInventory(std::string& aString)
{
    for (unsigned int i = 0; i < items.size(); ++i){
        if(items[i]->getName() == aString){
            items.erase(items.begin()+i);
            std::cout << "removing: " << items[i]->getName() << std::endl;
        }
    }
}

void Inventory::removeFromInventory(GameObject* aItem)
{
    for (unsigned int i = 0; i < items.size(); ++i){
        if ( items[i] == aItem){
            items.erase(items.begin()+i);
            std::cout << "removing: " << items[i]->getName() << std::endl;
        }
    }
}



std::vector< GameObject * > Inventory::getInventory()
{
    return items;
}

bool Inventory::CheckContainItem(std::string& aString){
    for (unsigned int i = 0; i < items.size(); ++i){

        std::cout << aString << items[i]->getName() << std::endl;

        if(items[i]->getName() == aString){
            std::cout << "in infentory: " << items[i]->getName() << std::endl;
            return true;
        }
    }
    return false;

}
