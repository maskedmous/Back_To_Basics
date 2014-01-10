#ifndef ITEMBEHAVIOUR_HPP_INCLUDED
#define ITEMBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"

class ItemBehaviour : public Behaviour
{
    public:
        ItemBehaviour(GameObject* aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem);
        virtual ~ItemBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;
        Inventory * inventory;
        TipSystem * tipSystem;
};




#endif // ITEMBEHAVIOUR_HPP_INCLUDED
