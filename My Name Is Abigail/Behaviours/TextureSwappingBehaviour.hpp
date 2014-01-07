#ifndef TEXTURESWAPPINGBEHAVIOUR_H_INCLUDED
#define TEXTURESWAPPINGBEHAVIOUR_H_INCLUDED


#include <string>

#include "../Texture.hpp"
#include "../Behaviour.hpp"

class TextureSwappingBehaviour : public Behaviour
{
    public:
        TextureSwappingBehaviour(GameObject * aParent, GameObject * mememe, std::string firstTexture , std::string secondTexture);
        virtual ~TextureSwappingBehaviour();

        virtual void update (float step);
        //virtual void update( glm::mat4 & transformation, float step ,  Body * aBody );
    protected:
    private:
        GameObject * myParent;
        int textureDelay;
        int textureState;


        Texture * textureOne;
        Texture * textureTwo;

        //std::string textureOne;
        //std::string textureTwo;
};

#endif // TEXTURESWAPPINGBEHAVIOUR_H_INCLUDED
