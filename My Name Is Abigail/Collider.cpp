#include <iostream>
#include "Collider.hpp"

Collider::Collider( float aWidth, float aHeight, GameObject * aParent)
: width(aWidth), height(aHeight), parent(aParent)
{}

Collider::~Collider()
{}

bool Collider::isColliding(GameObject * otherObject)
{
    float parentWidth = width;
    float parentHeight = height;
    float parentX = parent->getLocation().x;
    float parentY = parent->getLocation().y;

    float parentRight   = parentX + (parentWidth  / 2);
    float parentLeft    = parentX - (parentWidth  / 2);
    float parentTop     = parentY + (parentHeight / 2);
    float parentBottom  = parentY - (parentHeight / 2);


    float otherObjectWidth = otherObject->getCollider()->getWidth();
    float otherObjectHeight = otherObject->getCollider()->getHeight();
    float otherObjectX = otherObject->getLocation().x;
    float otherObjectY = otherObject->getLocation().y;

    float otherObjectRight  = otherObjectX + (otherObjectWidth  / 2);
    float otherObjectLeft   = otherObjectX - (otherObjectWidth  / 2);
    float otherObjectTop    = otherObjectY + (otherObjectHeight / 2);
    float otherObjectBottom = otherObjectY - (otherObjectHeight / 2);

    bool checkX = false;
    //check X direction
    if(parentRight > otherObjectLeft)
    {
        if(parentLeft < otherObjectRight)
        {
            checkX = true;
        }
    }

    if(checkX == true)
    {
        //checkY
        if(parentTop < otherObjectTop)
        {
            if(parentBottom > otherObjectBottom)
            {
                //std::cout << "colliding" << std::endl;
                //match in Y
                return true;
            }
        }
    }

    return false;

}

float Collider::getWidth()
{
    return width;
}

float Collider::getHeight()
{
    return height;
}
