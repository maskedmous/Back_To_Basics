#include "ArrowBehaviour.hpp"
#include "../Time.hpp"
#include <iostream>

ArrowBehaviour::ArrowBehaviour(GameObject * aParent, std::string aDirection)
: Behaviour( aParent ), direction(aDirection), sinFloat(0.0f), sinTime(0.0f)
{
    //ctor
}

ArrowBehaviour::~ArrowBehaviour()
{
    //dtor
}

void ArrowBehaviour::update(float step)
{
    glm::vec3 aPosition = parent->getLocation();
    sinTime = Time::now();

    sinFloat = 0.01 * glm::sin(sinTime * 3.14159);

    if(direction == "Horizontal")
    {
        aPosition.x += sinFloat;
        parent->setPosition(aPosition);
    }
    if(direction == "Vertical")
    {
        aPosition.y += sinFloat;
        parent->setPosition(aPosition);
    }
}
