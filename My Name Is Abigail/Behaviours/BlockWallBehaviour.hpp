#ifndef BLOCKWALLBEHAVIOUR_HPP_INCLUDED
#define BLOCKWALLBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"
#include "../AudioPlayer.hpp"

class BlockWallBehaviour : public Behaviour
{
    public:
        BlockWallBehaviour(GameObject* aParent);
        virtual ~BlockWallBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
};




#endif // BLOCKWALLBEHAVIOUR_HPP_INCLUDED
