#pragma once
#include <SFML\Graphics.hpp>
#include "threadPool.h"
#include "Player.h"
#include "menu.h"
#include "IntroDisplay.h"
#include "Hero.h"
#include <SFML\Audio.hpp>
#include "Map.h"
/* First create the players using players class then create the game pass the player pointers to the game
   
*/
class Game {
	public:

		Game(int numWorkerThreads,sf::RenderWindow *,int numLevels,std::string maps);

		~Game();
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
		Menu * mainMenu;
		sf::RenderWindow * gameWindow;
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
	/*Atrributes for the game class */

	sf::Event event;  
	threadPool * workerPool;

	std::vector<sf::Sprite> spriteSheet;
	std::vector<sf::Sound> sounds;
	std::vector<Maps> gameMaps;

	std::string mapPaths;

	Player *srikanth, *ujjieve;

	sf::Music *mainMenuSong;
	sf::Music *storySong;
	sf::Music *openingSong;

	int currentLevel, totalLevels;
	int isopen;
	bool iskey;
	bool isMenuActive; // if menu active or not
	bool gameActive; // if game is active or not if yes then update and render methods are invoked else not invoked
					 
	/*Methods used by game class*/

	// For displaying purposes
	int displayStory();
	// For updating purposes
	int playersUpdate();
	int mapUpdate();
	// For rendering purposes
	void playerRender();
	void mapRender();
	// For loading purposes
	int loadMenu();
	int loadMaps();

};