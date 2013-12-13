#include <cassert>

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
#include "Behaviours/DoorBehaviour.hpp"
#include "Behaviours/TextureSwappingBehaviour.hpp"
#include "Behaviours/RotatingBehaviour.hpp"

Game::Game()
:	window(NULL), hud(NULL), renderer(NULL), world(NULL),interperter(NULL), camera(NULL), light(NULL)
{
	window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "My Name Is Abigail" ); // get a window
	std::cout << "Init Glew" << glewInit() << std::endl;
	hud = new Hud( window );
	//window->setVerticalSyncEnabled( true ); // sync with monitor ->60 hz approx
	renderer = new Renderer( window );
}

Game::~Game()
{
	//dtor
}

void Game::build()
{
	renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );

	camera = new Camera( "Camera", glm::vec3( 0, 1, 3.464 ) );
        //Behaviour * keysBehaviour = new KeysBehaviour(camera);
        //camera->setBehaviour( keysBehaviour );

	light = new Light( "Light", glm::vec3( 2.0f, 10.0f, 15.0f ) ); // not used now, just ambient light

	world = new World( "World" );
		world->add( camera );
		world->add( light );

    Inventory * inventory = new Inventory();

    interperter = new Interperter (world);
		interperter->readFile( "LevelOne", world);



    GameObject * item = new GameObject("Item", glm::vec3(-2.0f, 2.0f, .15f));
        item->setMesh(Mesh::load("models/myPlane.obj"));
        item->setColorMap(Texture::load("models/bricks.jpg"));
        //item->setBehaviour( new RotatingBehaviour(item) );
        item->setCollider( new Collider(1.0f, item) );
        world->add(item);

    GameObject * firstDoor = new GameObject("firstDoor", glm::vec3(2.0f, 2.0f, .15f));
        firstDoor->setMesh(Mesh::load("models/myPlane.obj"));
        firstDoor->setColorMap(Texture::load("models/bricks.jpg"));

        Behaviour * doorBehaviour = new DoorBehaviour(firstDoor, world);
        firstDoor->setBehaviour( doorBehaviour );

        firstDoor->setCollider( new Collider(1.0f, firstDoor) );
        world->add(firstDoor);

    GameObject * blockWall = new GameObject("Wall", glm::vec3(5.0f, 0.0f, 0.0f));
        blockWall->setCollider( new Collider (3.0f, blockWall));
        world->add(blockWall);

    GameObject * character = new GameObject("Character", glm::vec3(0.0f, 0.0f,0.2f));
        character->setMesh(Mesh::load("models/AbigailCharacter.obj"));
        character->setColorMap(Texture::load("models/Abigail_side.png"));
        Behaviour * characterController = new PlayerController( character, window, renderer, world, inventory );
        character->setBehaviour( characterController );
        character->setCollider( new Collider( 1.0f, character));
        hud->setInventory( inventory );
        world->add(character);
    camera->setBehaviour( new LookAtBehaviour(camera, character));

}

void Game::run()
{
	running = true;
	while ( running ) {
		Time::update();
		FPS::update();
		control();
		if ( running ) { // control may have changed running;
			update( Time::step() );
			draw();
		}
	}
}

void Game::stop()
{
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
	assert( world != NULL );
	world->update( step );
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


