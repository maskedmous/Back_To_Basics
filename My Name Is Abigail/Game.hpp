#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sfml/audio.hpp>
#include "AudioPlayer.hpp"

class Hud;
class Renderer;
class World;
class Interperter;
class Camera;
class Light;
class MainMenu;
class TipSystem;

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
		AudioPlayer * audioPlayer;
		Light * light;
        MainMenu * mainMenu;
        TipSystem * tipSystem;
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
		void DestroyGame();

        sf::SoundBuffer bufferMenuMusic;
        sf::Sound menuMusic;

        sf::SoundBuffer bufferMainMusic;
        sf::Sound mainMusic;


};

#endif // GAME_H
