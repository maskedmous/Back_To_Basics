#ifndef DOORBEHAVIOUR_H
#define DOORBEHAVIOUR_H

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"
#include <string>

class DoorBehaviour : public Behaviour
{
    public:
        DoorBehaviour(GameObject* aParent, World* aWorld, Inventory* aInventory, TipSystem * aTipsystem, const std::string recievedItemName);
        virtual ~DoorBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;
        Inventory * inventory;
        TipSystem * tipSystem;
        std::string myString;
        std::string requiredItem;

};

#endif // DOORBEHAVIOUR_H
