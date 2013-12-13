#ifndef ITEMBEHAVIOUR_HPP_INCLUDED
#define ITEMBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"

class ItemBehaviour : public Behaviour
{
    public:
        ItemBehaviour(GameObject* aParent, World* aWorld);
        virtual ~ItemBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;

};




#endif // ITEMBEHAVIOUR_HPP_INCLUDED
