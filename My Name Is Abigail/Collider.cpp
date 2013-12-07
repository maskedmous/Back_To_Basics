#include <iostream>
#include "Collider.hpp"

Collider::Collider(float aX, float aY, float aWidth, float aHeight)
: m_x(aX), m_y(aY), width(aWidth), height(aHeight)
{}

Collider::~Collider()
{}

bool Collider::isColliding(float aX, float aY)
{
    std::cout << "Checking: " << "X: " << aX << " Y: " << aY << std::endl;

    //check the X axis if it is in the correct range
    if(aX > m_x && aX < m_x + width)
    {
        //check the Y axis if it is in the correct range
        if(aY > m_y && aY < m_y + height)
        {
            return true;
        }
    }
    return false;
}
