#ifndef PLAYERCONTROLLER_HPP_INCLUDED
#define PLAYERCONTROLLER_HPP_INCLUDED
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include "../glm.hpp"
#include "../Renderer.hpp"
#include "../Behaviour.hpp"
#include "../Inventory.hpp"
#include "../World.hpp"
#include "../Hud.hpp"
#include "../Time.hpp"

class PlayerController : public Behaviour
{
    private:
        sf::Window * window;
        Renderer * renderer;
        World * world;
        Inventory * inventory;
        Hud * hud;
        glm::vec4 mouseInWorld;
        glm::vec3 oldPos;
        GameObject * targetItem;
        std::vector< Texture * > animation;
        bool ableToMove;

        enum charState {intro,frozen,moving};
        charState characterState;

        float mylittlevar;

    protected:
        std::string mouseState;
        std::string interactButton;
        std::vector< GameObject * > items;

    public:
        PlayerController( GameObject * aParent, sf::Window * aWindow, Renderer * aRenderer, World * aWorld, Inventory * aInventory, Hud * aHud );
        virtual ~PlayerController();
        virtual void update(float step);
        void OnMouseDown();
        void InteractWithObject();
        virtual void onCollision(GameObject * otherObject);
        virtual void onBlock();

        void moveCharacter(float step);
        void checkPosition();
        void mergeItems( GameObject * itemA, GameObject * itemB);
        std::vector< GameObject * >  getInventory();
        virtual void setAbleToMove();
        virtual void setState(int aState);
};


#endif // PLAYERCONTROLLER_HPP_INCLUDED
