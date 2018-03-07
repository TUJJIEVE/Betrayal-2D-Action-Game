#pragma once
#include <SFML\Graphics.hpp>
#include "threadPool.h"
#include <future>
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
		bool runGame, isgameOver;// if menu active or not
		int restart();

private :
	sf::View currentView;
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
	std::packaged_task <int()> *task1;
	std::packaged_task <int()>* task2;
	std::packaged_task <int()> *task3;
	std::packaged_task <int()> *task4;
	Hero *srikanth, *ujjieve;
	
	sf::Music *mainMenuSong;
	sf::Music *storySong;
	sf::Music *openingSong;
	sf::SoundBuffer enemyGunSound,gameOverBuffer,gameLoadedBuffer,enemyMissileBuffer;
	sf::Sound gameOverSound,gameLoadedSound,enemyMissileSound;
	sf::Texture spaceEnemy, groundEnemy,bulletEnemy;
	sf::Text gameOverText,gameLoadedText;
	sf::Font fontStyle;

	int enemyspawntimer, enemyspawntimermax,enemyShootTimer,enemyShootTimerMax;
	int currentLevel, totalLevels;
	int totalenemies;
	
	int isopen;
	bool islevelCompleted;
	bool iskey;
	bool isMenuActive, isPauseActive,spacebarInactive;
	 // if game is active or not if yes then update and render methods are invoked else not invoked
	std::future <int> *f1;
	std::future <int> *f2;
	std::future <int> *f3;
	std::future <int> *f4;

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
	int loadSounds();
	int reloadEnemies();

};