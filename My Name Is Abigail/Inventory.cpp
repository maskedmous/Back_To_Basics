#include "Inventory.hpp"

#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "Texture.hpp"

Inventory::Inventory()
{
    //ctor
}

Inventory::~Inventory()
{
    //dtor
}

void Inventory::addToInventory(GameObject * item)
{
    std::cout << "Obtained: " << item->getName() << std::endl;
    items.push_back(item);
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

void Inventory::mergeItems(GameObject * itemA, GameObject * itemB)
{
    //std::cout << itemA << " " << itemB << std::endl;

    std::string line = "";
    std::string seperator = ";";

    std::string tempItemA = "";
    std::string tempItemB = "";

    std::string itemC = "";
    std::string itemCTexture = "";

    std::ifstream mergeItems ("mergeItems.txt");

    if(mergeItems.is_open())
    {
        unsigned int i = 0;
        while(mergeItems.good())
        {
            getline(mergeItems, line);
            //std::cout << line << std::endl;
            size_t current;
            size_t next = -1;

            do
            {
                current = next + 1;
                next = line.find_first_of( seperator, current );
                i++;

                if(i == 1)
                {
                    tempItemA = line.substr(current, next - current);
                    //std::cout << "temp itemA: " << tempItemA << std::endl;
                }
                if(i == 2)
                {
                    tempItemB = line.substr(current, next - current);
                    //std::cout << "temp itemB: " << tempItemB << std::endl;
                }
                if(i == 3)
                {
                    itemC = line.substr(current, next - current);
                    //std::cout << "itemC: " << itemC << std::endl;
                }
                if(i == 4)
                {
                    itemCTexture = line.substr(current, next - current);
                    //std::cout << "texture: " << itemCTexture << std::endl;
                }

                if(tempItemA != "" && tempItemB != "" && itemC != "" && itemCTexture != "")
                {
                    if(tempItemA == itemA->getName() && tempItemB == itemB->getName())
                    {
                        //std::cout << "found a match! merging items" << std::endl;
                        //std::cout << itemA->getName() << " " << itemB->getName() << " becomes " << itemC << std::endl;
                        //check if everything is valid

                        //remove items A and B cause they're destroyed in merging
                        removeFromInventory(itemA);
                        removeFromInventory(itemB);
                        //create the new item
                        GameObject * newItem = new GameObject(itemC, glm::vec3(0.0f,0.0f,0.0f));
                        newItem->setColorMap(Texture::load(itemCTexture));
                        //new item is made add it to the inventory!
                        addToInventory(newItem);
                    }
                    else
                    {
                        //search further
                        i=0;
                        tempItemA = "";
                        tempItemB = "";
                        itemC = "";
                        itemCTexture = "";
                    }
                }

            }
            while(next != std::string::npos);
        }
        mergeItems.close();
    }
}

std::vector< GameObject * > Inventory::getInventory()
{
    return items;
}

GameObject * Inventory::getFromInventory(unsigned int itemIndex)
{
    return items[itemIndex];
}

bool Inventory::checkValidItemIndex(unsigned int itemIndex)
{
    if (itemIndex <= items.size() && items.size() != 1)
    {
        return true;
    }

    return false;
}

bool Inventory::CheckContainItem(std::string& aString){
    for (unsigned int i = 0; i < items.size(); ++i){

        std::cout << aString << items[i]->getName() << std::endl;

        if(items[i]->getName() == aString){
            std::cout << "in inventory: " << items[i]->getName() << std::endl;
            return true;
        }
    }
    return false;

}
