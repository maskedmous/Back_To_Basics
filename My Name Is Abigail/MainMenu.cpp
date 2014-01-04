#include "MainMenu.hpp"

MainMenu::MainMenu(Hud * aHud, sf::RenderWindow * aWindow, Game * aGame)
: hud(aHud), window(aWindow), game(aGame)
{
//buttons are a graphic with a button collider
//the update function will handle what it should do in the desired menu (aka main menu)

//background as a button but no function


//create a button for start game
startButton = new Button("models/StartGame.png", glm::vec2(640, 100));
hud->addButtonToMainMenu(startButton);
//create a button for options
optionsButton = new Button("models/Options.png", glm::vec2(640, 280));
hud->addButtonToMainMenu(optionsButton);
//create a button for exit game
exitButton = new Button("models/ExitGame.png", glm::vec2(640, 460));
hud->addButtonToMainMenu(exitButton);

mouseState = "Standby";
}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::Update(float step)
{
    //on mouse down
    if(mouseState == "Standby")
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            //call on mouse down
            OnMouseDown(step);
            mouseState = "Down";
        }
    }
    //if it is down
    if(mouseState == "Down")
    {
        //check if it is up
        if(! sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            //mouse is up so put it back to standby
            mouseState = "Standby";
        }
    }
}

void MainMenu::OnMouseDown(float step)
{
    glm::vec2 mousePosition = glm::vec2(glm::ivec2(sf::Mouse::getPosition(* window).x, sf::Mouse::getPosition(* window).y));

    if(startButton->hitButton(mousePosition))
    {
        //start button is clicked
        //build the game
        game->buildLevel();
    }
    if(optionsButton->hitButton(mousePosition))
    {
        //options button is clicked
        //could be just muting sound since thats the only thing
        std::cout << "options not doing anything yet" << std::endl;
    }
    if(exitButton->hitButton(mousePosition))
    {
        //exit button is clicked
        game->closeGame();
    }
}
