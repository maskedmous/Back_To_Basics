#ifndef DOORBEHAVIOUR_H
#define DOORBEHAVIOUR_H

#include "../Behaviour.hpp"
#include "../World.hpp"

class DoorBehaviour : public Behaviour
{
    public:
        DoorBehaviour(GameObject* aParent, World* aWorld);
        virtual ~DoorBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;

};

#endif // DOORBEHAVIOUR_H
