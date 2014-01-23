#include <cassert>
#include <SFML/Window.hpp>

#include "Time.hpp"
#include "FPS.hpp"

#include "Hud.hpp"
#include "Renderer.hpp"
#include "ShaderProgram.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "Interperter.hpp"
#include "Camera.hpp"
#include "Collider.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Inventory.hpp"
#include "Behaviours/KeysBehaviour.hpp"
#include "Behaviours/PlayerController.hpp"
#include "Behaviours/LookAtBehaviour.hpp"
#include "Behaviours/WASDBehaviour.hpp"
#include "Behaviours/InvadableBehaviour.hpp"
#include "Behaviours/DoorBehaviour.hpp"
#include "Behaviours/ItemBehaviour.hpp"
#include "Behaviours/TriggerBehaviour.hpp"
#include "Behaviours/StairsBehaviour.h"
#include "Behaviours/TextureSwappingBehaviour.hpp"
#include "Behaviours/RotatingBehaviour.hpp"
#include "MainMenu.hpp"
#include "TipSystem.hpp"

Game::Game()
:	state("Loading"),window(NULL), hud(NULL), renderer(NULL), world(NULL),interperter(NULL), camera(NULL), light(NULL), tipSystem(NULL)
{
	window = new sf::RenderWindow( sf::VideoMode( 1280, 720 ), "My Name Is Abigail" ); // get a window
	//window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "My Name Is Abigail" ); // get a window
    //1280 720
	std::cout << "Init Glew" << glewInit() << std::endl;
	hud = new Hud( window, this );
	window->setVerticalSyncEnabled( true ); // sync with monitor ->60 hz approx
	renderer = new Renderer( window );
}

Game::~Game()
{
	//dtor
}

void Game::build()
{
	renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );

	camera = new Camera( "Camera", glm::vec3( 0, 1, 5) );
	world = new World( "World" );
		world->add( camera );

    audioPlayer = new AudioPlayer();
    hud->setAudioPlayer(audioPlayer);
    mainMenu = new MainMenu(hud, window, this);
    audioPlayer->PlayMusic("menu");
    setState("Main Menu");
}

void Game::buildLevel()
{
    light = new Light( "Light", glm::vec3( 2.0f, 10.0f, 15.0f ) ); // not used now, just ambient light
        world->add( light );

    Inventory * inventory = new Inventory();

    tipSystem = new TipSystem(hud);

    interperter = new Interperter (world);
		interperter->readFile( "LevelOne", world, inventory, tipSystem, audioPlayer);

    GameObject * blockWall = new GameObject("Wall", glm::vec3(4.5f, 0.0f, -1.0f));
        blockWall->setCollider( new Collider (1.0f, 2.0f, blockWall));
        world->add(blockWall);

    GameObject * character = new GameObject("Character", glm::vec3(17.0f, -4.45f,0.2f));
        character->setMesh(Mesh::load("models/AbigailCharacter.obj"));
        character->setColorMap(Texture::load("models/Abigailside.png"));
        character->setBehaviour( new PlayerController( character, window, renderer, world, inventory, hud) );

        character->setCollider( new Collider( 1.0f, 1.75f, character));
        hud->setInventory( inventory );
        world->add(character);
    camera->setBehaviour( new LookAtBehaviour(camera, character));


    GameObject * fireTrigger = new GameObject("fireTrigger", glm::vec3(4.5f, -0.45f, -1.0f));
        fireTrigger->setCollider( new Collider( 4.0f, 2.0f, fireTrigger));
        std::string soundForTrigger = "fireloop";
        fireTrigger->setBehaviour( new TriggerBehaviour(fireTrigger, world, inventory, tipSystem, audioPlayer, -1 , soundForTrigger) );
        world->add(fireTrigger);

    audioPlayer->PlayMusic("musicAct1");
    setState("Intro");


}

void Game::run()
{
	running = true;
	while ( running )
    {
        Time::update();
        FPS::update();
        control();  //should be done while running

		if ( running )
		{   // control may have changed running;
			update( Time::step() );
			draw();
		}
	}
}

void Game::stop()
{
}

void Game::closeGame()
{
    running = false; // running = false;
    window->close(); // oeps, still drawing after this one !!!!!!
}

// private functions

void Game::control()
{
	sf::Event event;
	while( window->pollEvent( event ) ) { // we must empty the event queue
		if ( event.type == sf::Event::Closed ) {
			window->close(); // oeps, still drawing after this one !!!!!!
			running = false; // running = false;
		}
	}
}

void Game::update( float step )
{

    if(state == "Intro")
    {
        if(sf::Keyboard::isKeyPressed( sf::Keyboard::W) || sf::Keyboard::isKeyPressed( sf::Keyboard::Space) )
        {
            state = "Play";
            audioPlayer->Play("intro", false);
        }
    }
	if(state == "Play")
    {
        assert( world != NULL );
        world->update( step );

        if(sf::Keyboard::isKeyPressed( sf::Keyboard::Escape))
        {
            state = "Ingame Menu";
        }
    }

	if(state == "Main Menu" || state == "GoMenu")
    {
        assert( mainMenu != NULL );
        mainMenu->Update(step);
    }
	assert( hud != NULL);
	hud->countdown(step);

	if(tipSystem != NULL)
    {
        tipSystem->countdown(step);
    }

    if(state == "GoToMenu")
    {
        setState("Destroying");
        DestroyGame();
    }


}

void Game::draw()
{
	assert( window != NULL );
	assert( renderer != NULL );
	assert( world != NULL );

	renderer->draw( world );
	hud->draw();
	window->display(); // swap colorbuffer to screen
}

void Game::setState(std::string newState)
{
    state = newState;
}

std::string Game::getState()
{
    return state;
}

void Game::DestroyGame()
{
    std::cout << "destroying game!!" << std::endl;
    world->removeEveryChild();
    world->add( camera );
    audioPlayer->Stop();
    audioPlayer->PlayMusic("menu");
    setState("GoMenu");
}
