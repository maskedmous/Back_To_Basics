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

class PlayerController : public Behaviour
{
    private:
        sf::Window * window;
        Renderer * renderer;
        World * world;
        Inventory * inventory;
        glm::vec4 mouseInWorld;
        GameObject * targetItem;
    protected:
        std::string mouseState;
        std::vector< GameObject * > items;

    public:
        PlayerController( GameObject * aParent, sf::Window * aWindow, Renderer * aRenderer, World * aWorld, Inventory * aInventory );
        virtual ~PlayerController();
        virtual void update(float step);
        void OnMouseDown();
        virtual void onCollision(GameObject * otherObject);
        void moveCharacter(float step);
        void checkPosition();
        void mergeItems( GameObject * itemA, GameObject * itemB);
        std::vector< GameObject * >  getInventory();
};


#endif // PLAYERCONTROLLER_HPP_INCLUDED
