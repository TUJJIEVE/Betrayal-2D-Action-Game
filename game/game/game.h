#pragma once
#include <SFML\Graphics.hpp>
#include "threadPool.h"
#include "Player.h"
/* First create the players using players class then create the game pass the player pointers to the game
   
*/
class Game {
	public:
		Game(int numWorkerThreads,Player *,Player *);

		inline ~Game() {
			this->gameWindow->clear(sf::Color::Black);
			this->gameWindow->display();
		}
		void init(sf::RenderWindow * ,int frameLimit);
		void handleEvents();
		void update();
		void render();
		inline	sf::RenderWindow * getGameWindow() {
			return this->gameWindow;   // Can be *this->gameWindow??
		}
private :
		sf::RenderWindow * gameWindow;
		threadPool * workerPool;
		Player *hero1, *hero2;


};