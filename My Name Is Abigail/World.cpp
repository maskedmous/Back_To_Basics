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
	checkBlock();
}

void World::checkCollision( GameObject* firstCollider )
{
    glm::vec3 playerPosition = firstCollider->getLocation();
    //go through the array of gameobjects
    for(unsigned int i=0; i<children.size(); ++i)
    {
        if(children[i]->getName() != "Character")
        {
            //if it has a collider proceed

            if(children[i]->hasCollider() && children[i]->getLocation().z == 0.15f)
            {

                if(glm::abs(children[i]->getLocation().y - playerPosition.y - 1.5) < 1.5f ){
                        //std::cout << children[i]->getName() << std::endl;
                    if(glm::abs(children[i]->getLocation().x - playerPosition.x) < 0.5f )
                    {
                        //return children[i];
                        std::cout << children[i]->getName() << std::endl;
                        children[i]->onCollision(firstCollider);
                    }
                }
            }

        }
    }
    //return NULL;
}

void World::checkBlock()
{
    for(unsigned int i=0; i<children.size(); ++i)
    {
        if(children[i]->hasCollider())
        {
            if(children[i]->getName() == "Character")
            {
                for(unsigned int j=0; j<children.size(); ++j)
                {
                   if(children[j]->getName() != "Character")
                    {
                        //wall blocks are at Z -1.0f
                        if(children[j]->hasCollider() && children[j]->getLocation().z == -1.0f)
                        {
                            //check if its colliding
                            if(children[i]->getCollider()->isColliding(children[j]))
                            {
                                //std::cout << "colliding"  << std::endl;
                                //its colliding so put her back
                                children[i]->onCollision(children[j]);
                            }
                        }
                    }
                }
            }
        }
    }
}

void World::draw( Renderer * renderer )
{
	assert( renderer != NULL );
	GameObject::draw( renderer ); // draw children Game Objects
}
