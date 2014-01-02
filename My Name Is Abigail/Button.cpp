#include "Button.hpp"

Button::Button(std::string texturePath, glm::vec2 position)
{
    //fill the texture / sprite
    if(buttonTexture.loadFromFile(texturePath))
    {
        buttonPosition = glm::vec2((position.x - (buttonTexture.getSize().x/2)), position.y);
        buttonSprite.setTexture(buttonTexture);
        buttonSprite.setPosition((position.x - (buttonTexture.getSize().x / 2)), position.y);
        buttonWidth = buttonTexture.getSize().x;
        buttonHeight = buttonTexture.getSize().y;
    }
    else
    {
        std::cout << "button graphic not loaded: " << texturePath << std::endl;
    }
}

Button::~Button()
{
    //dtor
}

sf::Sprite Button::getButtonSprite()
{
    return buttonSprite;
}

bool Button::hitButton(glm::vec2 mousePosition)
{
    float rightSide = buttonPosition.x + buttonWidth;
    float leftSide = buttonPosition.x;
    float bottomSide = buttonPosition.y + buttonHeight;
    float topSide = buttonPosition.y;

    //if current mouse position is within the position of the button
    if(mousePosition.x > leftSide && mousePosition.x < rightSide && mousePosition.y < bottomSide && mousePosition.y > topSide)
    {
        std::cout << "this button is clicked " << buttonPosition.y << std::endl;
        return true;
    }
    return false;
}
