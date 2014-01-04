#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Hud;
class Renderer;
class World;
class Interperter;
class Camera;
class Light;
class MainMenu;

class Game
{
    public:
        std::string state;
	private: // data members
		sf::RenderWindow * window;
		Hud * hud;
		Renderer * renderer;
		World * world;
        Interperter * interperter;
		Camera * camera;
		Light * light;
        MainMenu * mainMenu;
		bool running;

	public: // functions
		Game();
		virtual ~Game();

		void build();
		void buildLevel();
		void run();
		void stop();
		void closeGame();
		void setState(std::string newState);
        std::string getState();

	private:
		void control();
		void update( float step );
		void draw();
		void drawHud();


};

#endif // GAME_H
