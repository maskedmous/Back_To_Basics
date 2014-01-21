#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <vector>

class GameObject;
class Behaviour
{
	protected:
		GameObject * parent;

	public:
		Behaviour( GameObject * aParent );
		virtual ~Behaviour();

		virtual void update( float step );
		virtual void onCollision( GameObject * otherGameObject );
		virtual void onBlock();
		virtual void swapTexture();
        virtual void setAbleToMove();
};

#endif // BEHAVIOUR_H
