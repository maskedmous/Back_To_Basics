#include "TextureAnimationBehaviour.hpp"

#include "../Texture.hpp"
#include <iostream>


TextureAnimationBehaviour::TextureAnimationBehaviour(GameObject * aParent)
:	Behaviour( aParent )
{
    textureOne = Texture::load(("models/fire1.png" ));
    textureTwo = Texture::load(("models/fire2.png" ));
    textureThree = Texture::load(("models/fire3.png"));
    textureFour = Texture::load(("models/fire4.png"));
    textureFive = Texture::load(("models/fire5.png"));

    delay = 0.1;
    countdown = delay;
    activeTexture = 1;

}

TextureAnimationBehaviour::~TextureAnimationBehaviour()
{
    //dtor
}

void TextureAnimationBehaviour::update(float step ){
    //std::cout << delay << "empty" <<activeTexture  << std::endl;
    if(countdown <= 0){
        if(activeTexture == 1){
            parent->setColorMap( textureOne);
            activeTexture++;
            countdown = delay;
        } else if(activeTexture == 2){
            parent->setColorMap( textureTwo);
            activeTexture++;
            countdown = delay;
        }else if(activeTexture == 3){
            parent->setColorMap( textureThree);
            activeTexture++;
            countdown = delay;
        }else if(activeTexture == 4){
            parent->setColorMap( textureFour);
            activeTexture++;
            countdown = delay;
        }else if(activeTexture == 5){
            parent->setColorMap( textureFive);
            activeTexture = 1;
            countdown = delay;
        }


    }else countdown -= step;
}

void TextureAnimationBehaviour::onCollision( GameObject * otherGameObject )
{


}

