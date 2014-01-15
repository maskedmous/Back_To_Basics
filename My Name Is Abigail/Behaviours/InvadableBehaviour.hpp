#ifndef INVADABLEBEHAVIOUR_HPP_INCLUDED
#define INVADABLEBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"

class InvadableBehaviour : public Behaviour
{
    public:
        InvadableBehaviour(GameObject* aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, std::string respondingObject );
        virtual ~InvadableBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;
        Inventory * inventory;
        TipSystem * tipSystem;
        std::string responder;
};



#endif // INVADABLEBEHAVIOUR_HPP_INCLUDED

