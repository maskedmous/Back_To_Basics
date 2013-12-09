#include <iostream>
#include "Collider.hpp"

Collider::Collider( float aRadius, GameObject * aParent)
: radius(aRadius), parent(aParent)
{}

Collider::~Collider()
{}

bool Collider::isColliding(glm::vec3 rayOrigin, glm::vec3 rayDirection)
{
    return true;
    //calculate the closest point

    //ray end point
    glm::vec3 endPoint = rayOrigin + (7.0f * rayDirection);

    //A = ray Origin
    //B = endPoint
    //P = sphere center

    //B - A
    glm::vec3 AB = endPoint - rayOrigin;
    //AB dot AB
    float ab2 = glm::dot(AB, AB);
    //P - A
    glm::vec3 AP = parent->getLocation() - rayOrigin;
    //AP dot AB
    float AP_dot_AB = glm::dot(AP, AB);
    //AP dot AB / AB dot AB
    float t = AP_dot_AB / ab2;

    if(t < 0.0f) t = 0.0f;
    else if (t > 1.0f) t = 1.0f;

    //closest point
    glm::vec3 Q = rayOrigin + (AB * t);

    //check if that point is within the sphere
    glm::vec3 PQ = Q - parent->getLocation();
    float pq2 = glm::dot(PQ, PQ);
    float r2 = radius * radius;

    if(pq2 > r2) return false;

    return true;
}
