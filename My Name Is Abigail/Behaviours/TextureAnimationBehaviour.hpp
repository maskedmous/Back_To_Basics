#ifndef TEXTUREANIMATIONBEHAVIOUR_HPP_INCLUDED
#define TEXTUREANIMATIONBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"
#include "../World.hpp"
#include "../Inventory.hpp"
#include "../TipSystem.hpp"

class TextureAnimationBehaviour : public Behaviour
{
    public:
        TextureAnimationBehaviour(GameObject* aParent);
        virtual ~TextureAnimationBehaviour();
        virtual void onCollision(GameObject * aGameObject);
        virtual void update(float step );
    protected:
    private:
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
