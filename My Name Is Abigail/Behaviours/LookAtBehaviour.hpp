#ifndef LOOKATBEHAVIOUR_HPP_INCLUDED
#define LOOKATBEHAVIOUR_HPP_INCLUDED

#include "../Behaviour.hpp"

class LookAtBehaviour : public Behaviour
{
    private:

    GameObject * target;

	public:
		LookAtBehaviour( GameObject * aParent, GameObject * aTarget);
		virtual ~LookAtBehaviour();

		virtual void update( float step );
};

#endif // LOOKATBEHAVIOUR_HPP_INCLUDED
