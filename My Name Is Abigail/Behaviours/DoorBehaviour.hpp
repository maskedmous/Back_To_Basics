#ifndef DOORBEHAVIOUR_H
#define DOORBEHAVIOUR_H

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"

#include <string>

class DoorBehaviour : public Behaviour
{
    public:
        DoorBehaviour(GameObject* aParent, World* aWorld, Inventory* aInventory);
        virtual ~DoorBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;
        Inventory * inventory;
        std::string myString;

};

#endif // DOORBEHAVIOUR_H
