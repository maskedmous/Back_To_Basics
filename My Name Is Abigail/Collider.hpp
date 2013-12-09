#ifndef COLLIDER_HPP_INCLUDED
#define COLLIDER_HPP_INCLUDED

#include "GameObject.hpp"
#include "glm.hpp"

class Collider
{
    protected:
    float radius;
    GameObject * parent;

    public:
        Collider(float aRadius, GameObject * aParent);
        virtual ~Collider();
        bool isColliding(glm::vec3 rayOrigin, glm::vec3 rayDirection);
};

#endif // COLLIDER_HPP_INCLUDED
