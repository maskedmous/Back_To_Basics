#ifndef ARROWBEHAVIOUR_HPP
#define ARROWBEHAVIOUR_HPP

#include "../Behaviour.hpp"
#include "../GameObject.hpp"
#include <string>

class ArrowBehaviour : public Behaviour
{
    public:
        ArrowBehaviour(GameObject * aParent, std::string aDirection);
        virtual ~ArrowBehaviour();
        virtual void update(float step);
    protected:
    private:
        std::string direction;
        float sinFloat;
        float sinTime;
};

#endif // ARROWBEHAVIOUR_HPP
