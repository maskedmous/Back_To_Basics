#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Hud;
class Renderer;
class World;
class Interperter;
class Camera;
class Light;
class Game


{
	private: // data members
		sf::RenderWindow * window;
		Hud * hud;
		Renderer * renderer;
		World * world;
        Interperter * interperter;
		Camera * camera;
		Light * light;


		bool running;

	public: // functions
		Game();
		virtual ~Game();

		void build();
		void run();
		void stop();

	private:
		void control();
		void update( float step );
		void draw();
		void drawHud();

};

#endif // GAME_H
