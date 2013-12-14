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
        void addToInventory(GameObject * item, World * world);
        std::vector< GameObject * > getInventory();
        bool CheckContainItem(std::string& aString);
    protected:
        std::vector< GameObject * > items;
    private:

};

#endif // INVENTORY_H
