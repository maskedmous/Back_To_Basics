#include "TextureSwappingBehaviour.hpp"
#include <sfml/window.hpp>
#include "../GameObject.hpp"

#include "../Texture.hpp"

#include <string>

TextureSwappingBehaviour::TextureSwappingBehaviour( GameObject * aParent ,GameObject * mememe ,std::string firstTexture , std::string secondTexture)
: Behaviour( aParent )
{
    myParent = mememe;
    textureDelay = 0;
    textureState = 1;
}

TextureSwappingBehaviour::~TextureSwappingBehaviour()
{}

//void TextureSwappingBehaviour::update( glm::mat4 & transformation, float step ,  Body * aBody)
void TextureSwappingBehaviour::update(float step)

{
    if(textureDelay > 0){
        textureDelay -=1 * step ;
    }
    if(textureDelay < 1){
         if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up )) {
            if(textureState == 1){
                myParent->setColorMap( Texture::load("models/bricks.jpg") );
                //player->setColorMap( Texture::load("models/bricks.jpg") );

                //Texture * texture = Texture::load( "wallPillar.png" );
                //aBody->setTexture( texture );
                textureState = 2;
            } else if(textureState == 2){

                myParent->setColorMap( Texture::load("models/monkey.jpg") );
                //Texture * texture = Texture::load( "Dice.jpg" );
                //aBody->setTexture( texture );+
                textureState = 1;
            }


            textureDelay = 500;
        }
    }

}
