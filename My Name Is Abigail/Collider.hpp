#ifndef COLLIDER_HPP_INCLUDED
#define COLLIDER_HPP_INCLUDED

#include "GameObject.hpp"
#include "glm.hpp"

class Collider
{
    protected:
    float width;
    float height;
    GameObject * parent;
    glm::vec3 position;

    public:
        Collider(float aWidth, float aHeight, GameObject * aParent);
        virtual ~Collider();
        bool isColliding(GameObject * otherObject);
        float getWidth();
        float getHeight();
};

#endif // COLLIDER_HPP_INCLUDED
