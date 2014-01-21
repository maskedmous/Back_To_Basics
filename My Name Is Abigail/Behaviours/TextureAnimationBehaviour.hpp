#ifndef TEXTUREANIMATIONBEHAVIOUR_HPP_INCLUDED
#define TEXTUREANIMATIONBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"

class TextureAnimationBehaviour : public Behaviour
{
    public:
        TextureAnimationBehaviour(GameObject* aParent, World* aWorld, Inventory * aInventory, TipSystem * aTipsystem, AudioPlayer * aAudioPlayer);
        virtual ~TextureAnimationBehaviour();
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


        Texture * textureOne;
        Texture * textureTwo;
        Texture * textureThree;
        Texture * textureFour;
        Texture * textureFive;

        int activeTexture;
        float countdown;
        float delay;

};

#endif // TEXTUREANIMATIONBEHAVIOUR_HPP_INCLUDED
