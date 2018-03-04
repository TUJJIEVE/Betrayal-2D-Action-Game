#pragma once
#include <SFML\Graphics.hpp>
#include "threadPool.h"

#include "menu.h"
#include "IntroDisplay.h"
#include "Hero.h"
#include <SFML\Audio.hpp>
#include "Map.h"
#include "Enemy.h"
/* First create the players using players class then create the game pass the player pointers to the game
   
*/
class Game {
	public:

		Game(int numWorkerThreads,sf::RenderWindow *,int numLevels,int enemies,std::string maps);

		~Game();
		int init();
		void handleEvents();
		void update();
		void render();
		bool gameActive;
		int displayTitlescreen();
		int displayGameOver();
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
		Menu * mainMenu,*pauseMenu;
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
	int numEnemies;
	sf::Event event;  
	threadPool * workerPool;
	std::vector<Enemy> enemies;
//	std::vector<sf::Sprite> spriteSheet;
//	std::vector<sf::Sound> sounds;
	std::vector<Maps> gameMaps;

	std::string mapPaths;

	Hero *srikanth, *ujjieve;
	
	sf::Music *mainMenuSong;
	sf::Music *storySong;
	sf::Music *openingSong;
	sf::SoundBuffer enemyGunSound,gameOverBuffer;
	sf::Sound gameOverSound;
	sf::Texture spaceEnemy, groundEnemy,bulletEnemy;
	sf::Text gameOver;
	sf::Font fontStyle;
	int enemyspawntimer, enemyspawntimermax;
	int currentLevel, totalLevels;
	int totalenemies;
	int isopen;
	bool iskey;
	bool isMenuActive, isPauseActive;
	bool runGame;// if menu active or not
	 // if game is active or not if yes then update and render methods are invoked else not invoked
					 
	/*Methods used by game class*/

	// For displaying purposes
	int displayStory();
	// For updating purposes
	int playersUpdate();
	int mapUpdate();
	int levelUpdate();
	int enemyUpdate();
	// For rendering purposes
	void playerRender();
	void mapRender();
	// For loading purposes
	int loadMenu();
	int loadMaps();
	int loadEnemies();

};