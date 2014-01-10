#include "TextureSwappingBehaviour.hpp"
#include <sfml/window.hpp>
#include "../GameObject.hpp"

#include "../Texture.hpp"

#include <string>

TextureSwappingBehaviour::TextureSwappingBehaviour( GameObject * aParent ,GameObject * mememe ,std::string firstTexture , std::string secondTexture)
: Behaviour( aParent )
{
    myParent = mememe;
    textureOne = Texture::load(("models/" + firstTexture).c_str());
    textureTwo = Texture::load(("models/" + secondTexture).c_str());
    textureDelay = -1;
    textureState = 1;

    //("models/" + textureName).c_str()
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
            swapTexture();
            textureDelay = 50;
        }
    }

}

void TextureSwappingBehaviour::swapTexture(){
    if(textureState == 1){
        //myParent->setColorMap( Texture::load("models/StorageRoomLIGHT.png") );
        myParent->setColorMap( textureTwo);

        //player->setColorMap( Texture::load("models/bricks.jpg") );

        //Texture * texture = Texture::load( "wallPillar.png" );
        //aBody->setTexture( texture );
        textureState = 2;
    } else if(textureState == 2){
        //myParent->setColorMap( Texture::load("models/StorageRoomDARK.png") );

        myParent->setColorMap( textureOne );
        //Texture * texture = Texture::load( "Dice.jpg" );
        //aBody->setTexture( texture );+
        textureState = 1;
    }

}
