#include <cassert>
#include <iostream>
#include "Behaviour.hpp"

Behaviour::Behaviour( GameObject * aParent )
:	parent( aParent )
{
}

Behaviour::~Behaviour()
{
	//dtor
}

void Behaviour::update( float step )
{
	std::cout << "Behavour handles update. Should not be ! " << std::endl;
}

void Behaviour::onCollision( GameObject * otherGameObject )
{
	std::cout << "Behavour handles collision. Should not be ! " << std::endl;
}

void Behaviour::onBlock(){

}

void Behaviour::setAbleToMove(){
}

void Behaviour::swapTexture(){

    std::cout << "should not be called" << std::endl;
}

void Behaviour::setState(int aState)
{
    std::cout << "should not be called!!!" << std::endl;
}
