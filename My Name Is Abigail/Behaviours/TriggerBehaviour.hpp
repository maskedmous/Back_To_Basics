#ifndef TRIGGERBEHAVIOUR_HPP_INCLUDED
#define TRIGGERBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"
#include "../AudioPlayer.hpp"

class TriggerBehaviour : public Behaviour
{
    public:
        TriggerBehaviour(GameObject* aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer,int aInt, std::string aString);
        virtual ~TriggerBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;
        Inventory * inventory;
        TipSystem * tipSystem;
        AudioPlayer * audioPlayer;
        std::string soundToPlay;

        float countdown;
        bool active;
        bool reUseTrigger;
        bool continuous;
};

#endif // TRIGGERBEHAVIOUR_HPP_INCLUDED



