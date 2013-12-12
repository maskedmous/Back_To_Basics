#ifndef COLLIDER_HPP_INCLUDED
#define COLLIDER_HPP_INCLUDED

#include "GameObject.hpp"
#include "glm.hpp"

class Collider
{
    protected:
    float width;
    GameObject * parent;

    public:
        Collider(float aWidth, GameObject * aParent);
        virtual ~Collider();
        bool isColliding(GameObject * otherObject);
        float getWidth();
};

#endif // COLLIDER_HPP_INCLUDED
