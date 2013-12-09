#ifndef PLAYERCONTROLLER_HPP_INCLUDED
#define PLAYERCONTROLLER_HPP_INCLUDED
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include "../glm.hpp"
#include "../Renderer.hpp"
#include "../Behaviour.hpp"
#include "../World.hpp"

class PlayerController : public Behaviour
{
    private:
        sf::Window * window;
        Renderer * renderer;
        World * world;
        glm::vec4 mouseInWorld;
        GameObject * targetItem;
    protected:
        std::string mouseState;
        std::vector< GameObject * > items;

    public:
        PlayerController( GameObject * aParent, sf::Window * aWindow, Renderer * aRenderer, World * aWorld );
        virtual ~PlayerController();
        virtual void update(float step);
        void OnMouseDown();
        void moveCharacter(float step);
        void checkPosition();
        virtual void addToInventory(GameObject * item);
        void mergeItems( GameObject * itemA, GameObject * itemB);
        std::vector< GameObject * >  getInventory();
};


#endif // PLAYERCONTROLLER_HPP_INCLUDED
