#include <iostream>
#include "Collider.hpp"

Collider::Collider( float aWidth, GameObject * aParent)
: width(aWidth), parent(aParent)
{}

Collider::~Collider()
{}

bool Collider::isColliding(GameObject * otherObject)
{
    //left side
    float parentX = parent->getLocation().x;
    float parentWidth = width;

    float otherObjectX = otherObject->getLocation().x;
    float otherObjectWidth = otherObject->getCollider()->getWidth();

    if(parentX + (parentWidth / 2) > otherObjectX)
    {
        if(parentX + (parentWidth / 2) < otherObjectX + otherObjectWidth)
        {
            return true;
        }
    }


    return false;
}

float Collider::getWidth()
{
    return width;
}
