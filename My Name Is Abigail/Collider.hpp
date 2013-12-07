#ifndef COLLIDER_HPP_INCLUDED
#define COLLIDER_HPP_INCLUDED

class Collider
{
    protected:
    float m_x, m_y, width, height;

    public:
        Collider(float aX, float aY, float aWidth, float aHeight);
        virtual ~Collider();
        bool isColliding(float aX, float aY);
};

#endif // COLLIDER_HPP_INCLUDED
