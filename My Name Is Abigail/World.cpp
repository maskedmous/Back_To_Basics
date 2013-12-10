#include <cassert>

#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Collider.hpp"

World::World( std::string aName )
:	GameObject( aName )
{
	//ctor
}

World::~World()
{
	//dtor
}

void World::update( float step )
{
	//camera->update( step );
	GameObject::update( step );
}

GameObject * World::checkCollision( glm::vec3 playerPosition )
{
    //go through the array of gameobjects
    for(unsigned int i=0; i<children.size(); ++i)
    {
        //if it has a collider proceed
        if(children[i]->hasCollider())
        {
            if(glm::abs(children[i]->getLocation().x - playerPosition.x) < 1.0f )
            {
                return children[i];
            }
        }
    }
    return NULL;
}

void World::draw( Renderer * renderer )
{
	assert( renderer != NULL );
	GameObject::draw( renderer ); // draw children Game Objects
}
