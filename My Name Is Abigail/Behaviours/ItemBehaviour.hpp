#ifndef ITEMBEHAVIOUR_HPP_INCLUDED
#define ITEMBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"
#include "../AudioPlayer.hpp"
#include "../Game.hpp"

class ItemBehaviour : public Behaviour
{
    public:
        ItemBehaviour(GameObject* aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer, Game * aGame);
        virtual ~ItemBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;
        Inventory * inventory;
        TipSystem * tipSystem;
        AudioPlayer * audioPlayer;
        Game * myGame;
};




#endif // ITEMBEHAVIOUR_HPP_INCLUDED
