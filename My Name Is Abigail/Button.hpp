#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "glm.hpp"

class Button
{
    public:
        Button(std::string texturePath, glm::vec2 position);
        virtual ~Button();
        virtual sf::Sprite getButtonSprite();
        virtual bool hitButton(glm::vec2 mousePosition);
    protected:
        sf::Texture buttonTexture;
        sf::Sprite buttonSprite;
    private:
        float buttonWidth;
        float buttonHeight;
        glm::vec2 buttonPosition;
};

#endif // BUTTON_HPP
