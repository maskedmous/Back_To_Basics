#ifndef STAIRSBEHAVIOUR_H_INCLUDED
#define STAIRSBEHAVIOUR_H_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../AudioPlayer.hpp"

class StairsBehaviour : public Behaviour
{
    public:
        StairsBehaviour(GameObject* aParent, World* aWorld, Inventory * aInventory, AudioPlayer * aAudioPlayer, std::string aString);
        virtual ~StairsBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
        World * world;
        GameObject * parent;
        Inventory * inventory;
        AudioPlayer * audioPlayer;
        std::string stairsExit;
};



#endif // STAIRSBEHAVIOUR_H_INCLUDED
