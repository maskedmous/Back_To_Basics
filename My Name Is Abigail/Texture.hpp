#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

class Mesh;
class ShaderProgram;

class Texture
{
	private:
		const char * name;
		GLuint id; // OpenGL id for texture buffer
		static std::map< const char *, Texture * > textures; //all previously loaded meshes;
        static std::map< const std::string, sf::Image > sfImages;

	private:
		Texture( const char * aName );

	public:
		static Texture * load( const char * aName );
		virtual ~Texture();

		GLuint getId();
		static sf::Image getImage( const std::string aName );

};

#endif // TEXTURE_H
