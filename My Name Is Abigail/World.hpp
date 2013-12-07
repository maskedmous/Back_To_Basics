#ifndef WORLD_H
#define WORLD_H

#include "GameObject.hpp"
class Camera;
class Light;
class World : public GameObject
{
	private:

	public:
		World( std::string aName = NULL );
		virtual ~World();

		void update( float step );
		GameObject * checkCollision( glm::vec3 rayOrigin );
		virtual void draw( Renderer * renderer );

};

#endif // WORLD_H
