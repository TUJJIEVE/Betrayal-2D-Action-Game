#pragma once
#include <SFML\Graphics.hpp>
#include "threadPool.h"
#include "Player.h"
#include <SFML\Audio.hpp>
/* First create the players using players class then create the game pass the player pointers to the game
   
*/
class Game {
	public:
		Game(int numWorkerThreads,sf::RenderWindow *);

		inline ~Game() {
			this->gameWindow->clear(sf::Color::Black);
			this->gameWindow->display();
		}
		void init();
		void handleEvents();
		void update();
		void render();

		int displayTitlescreen();
		inline	sf::RenderWindow * getGameWindow() {
			return this->gameWindow;   // Can be *this->gameWindow??
		}
		inline bool running() {
			if (gameWindow->isOpen()) return true;
			else return false;
		}
		inline void clean() {
	
			gameWindow->close();
		
		}

private :
	enum Sprites
	{
		mainScreen = 0,
		player1,
		player2,
		enemy,
		boss,
		Lastsprite
	};
	enum Sounds
	{
		bullet=0,
		flame,
		Lastsound

	};
		sf::RenderWindow * gameWindow;
		threadPool * workerPool;
		Player *hero1, *hero2;
		int isopen;
		sf::Event event;
		std::vector<Player> players;
		int displayStory();
		int loading();
		std::vector<sf::Sprite> spriteSheet;
		std::vector<sf::Sound> sounds;

};