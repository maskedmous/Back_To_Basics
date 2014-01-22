#ifndef INVADABLEBEHAVIOUR_HPP_INCLUDED
#define INVADABLEBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"

class InvadableBehaviour : public Behaviour
{
    public:
        InvadableBehaviour(GameObject* aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer, std::string respondingObject );
        virtual ~InvadableBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;
        Inventory * inventory;
        TipSystem * tipSystem;
        AudioPlayer * audioPlayer;
        std::string responder;
        bool invading;
        bool firstInvade;
};



#endif // INVADABLEBEHAVIOUR_HPP_INCLUDED

