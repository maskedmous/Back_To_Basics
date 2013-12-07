#include "LookAtBehaviour.hpp"

#include <iostream>
#include <sfml/window.hpp>
#include "../glm.hpp"
#include "../GameObject.hpp"


LookAtBehaviour::LookAtBehaviour( GameObject * aParent, GameObject * aTarget)
:	Behaviour( aParent ), target(aTarget)
{
	//ctor
}

LookAtBehaviour::~LookAtBehaviour()
{
	//dtor
}

void LookAtBehaviour::update( float step )
{
	//camera position should be facing our character and follow the character over the X position
	glm::vec3 cameraPosition =  target->getLocation();//you want to be following the character over the X axis the Y and Z is depending on the initial settings
	cameraPosition = glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z + 5);	//Z should be adapted so it is at the right Z axis
	//eye is our camera position
	glm::vec3 eye = cameraPosition;                     	//the eye is the position of the camera
	//at is our target
	glm::vec3 at (target->getLocation());              		//looking at the target
	//up is just facing the right direction and not upside down aka 0, 1, 0
	glm::vec3 up ( 0.0f, 1.0f, 0.0f );                  	//up factor so it is looking in the correct direction (not upside down)
    parent->setTransform(glm::inverse( glm::lookAt( eye, at, up )));    //apply the transform
}
