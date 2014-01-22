#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <string>
#include "glm.hpp"

class Transform;
class Collider;
class Renderer;
class Mesh;
class Texture;
class Behaviour;

class GameObject
{
	protected:
		std::string name;
		glm::mat4 transform;
		Behaviour * behaviour;
		Collider * collider;
		Mesh * mesh;
		Texture * colorMap;


		std::vector< GameObject * > children;

	public:
		GameObject( std::string aName = NULL, glm::vec3 aPosition = glm::vec3( 0.0f, 0.0f, 0.0f ) );
		virtual ~GameObject();

		void translate( glm::vec3 translation );
		void setPosition( glm::vec3 aPosition);
		void setTransform(glm::mat4 aTransform);
		void rotate( float angle, glm::vec3 axis );

		const std::string getName();
		glm::vec3 getLocation();
		bool hasCollider();
        Collider * getCollider();
		void setBehaviour( Behaviour * aBehaviour );
		Behaviour * getBehaviour();
		void setCollider( Collider * aCollider );
		void setMesh( Mesh * aMesh );
		void setColorMap( Texture * aColorMap );
        Texture * getTexture();
		virtual void update( float step );
		virtual void onCollision(  GameObject * otherGameObject );
		virtual void onBlock();
		virtual void draw( Renderer * renderer, glm::mat4 parentTransform = glm::mat4(1) );


		void add( GameObject * child );
		void remove (GameObject * child );
		void remove (std::string& child );
		void removeEveryChild();
		GameObject* findGameObject( std::string& object);


	protected:

};

#endif // GAMEOBJECT_H
