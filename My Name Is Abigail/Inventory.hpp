#ifndef INVENTORY_H
#define INVENTORY_H

#include "GameObject.hpp"
#include "World.hpp"
#include <vector>
class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();
        void addToInventory(GameObject * item);
        void removeFromInventory(std::string& aString);
        void removeFromInventory(GameObject * aItem);
        bool mergeItems(GameObject * itemA, GameObject * itemB);
        void mergeItems(std::string& itemA, std::string& itemB);
        std::vector< GameObject * > getInventory();
        GameObject * getFromInventory(unsigned int itemIndex);
        bool checkValidItemIndex(unsigned int itemIndex);
        bool CheckContainItem(std::string& aString);
        std::string getItemName(unsigned int index);
    protected:
        std::vector< GameObject * > items;
    private:

};

#endif // INVENTORY_H
