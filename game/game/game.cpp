#include "game.h"
#include "threadPool.h"
#include "Player.h"
#include <SFML\Audio.hpp>
#include "IntroDisplay.h"
#include "menu.h"
/* Added Main menu feature */
Game::Game(int numWorkerThreads,sf::RenderWindow * window) {
	workerPool = new threadPool(numWorkerThreads);
	this->gameWindow = window;
	this->gameWindow->setFramerateLimit(60);
	this->spriteSheet.reserve(20);
	this->sounds.reserve(20);
	this->mainMenu = new Menu(window);  // To create menu
	this->mainMenuSong = new sf::Music();
	this->storySong = new sf::Music();
	std::function<int()> job = std::bind(&Game::loading, this); // Once game created it starts laoding all the prerequisites.
	this->workerPool->addJob(job);
}
int Game::loading() {
	/* MEthod to load the sprites textures for the players enemies etc..*/
	sf::Texture tex;

	std::cout << "Loaded files" << std::endl;
	if (!storySong->openFromFile("music_f/storymusic.ogg")) {
		std::cout << "Failure to load the music";

		return EXIT_FAILURE;
	}



//	std::function<int()> job = std::bind(&Menu::loadMenu, this->mainMenu);
 // this->workerPool->addJob(job);
	this->mainMenu->loadMenu();

/*	for (int i = Sprites::mainScreen; i!=Lastsprite; i++) {
		switch(i) {
		case mainScreen:
			if (!tex.loadFromFile("images_f / openingimage1.png")) {
				std::cout << "Error loading" << i;
				return EXIT_FAILURE;
			}
			spriteSheet.push_back(sf::Sprite(tex));
			break;

			case player1:
			if (!tex.loadFromFile("sourcePath")) {
				std::cout << " Error loading" << i;
				return EXIT_FAILURE;
			}
			spriteSheet.push_back(sf::Sprite(tex));
			break;
		case player2:
			if (!tex.loadFromFile("sourcePath")) {
				std::cout << " Error loading" << i;
				return EXIT_FAILURE;
			}
			spriteSheet.push_back(sf::Sprite(tex));
			break;
		case enemy:
			if (!tex.loadFromFile("sourcePath") ){
				std::cout << " Error loading" << i;
				return EXIT_FAILURE;
			}
			spriteSheet.push_back(sf::Sprite(tex));
			break;
		case boss:
			if (!tex.loadFromFile("sourcePath")) {
				std::cout << " Error loading" << i;
				return EXIT_FAILURE;
			}
			spriteSheet.push_back(sf::Sprite(tex));
			break;
		
		}
	}
	sf::SoundBuffer buff;
	for (int i = Sounds::bullet; i!=Lastsound; i++) {
		switch (i) {
		case bullet:
			if (!buff.loadFromFile("bullet.wav")) {
				std::cout << "Error loading sound " << i;
				return EXIT_FAILURE;
			}
			sounds.push_back(sf::Sound(buff));
		case flame:
			if (!buff.loadFromFile("flame.wav")) {
				std::cout << "Error loading sound " << i;
				return EXIT_FAILURE;
			}
			sounds.push_back(sf::Sound(buff));


		}
	}
*/
	return 0;
}
int Game::displayTitlescreen() {  /* Function to print the title Screen*/
	if (!mainMenuSong->openFromFile("music_f/mainMenuSong2.ogg")) {
		std::cout << "Failure to load the music";

		return EXIT_FAILURE;
	}

	mainMenuSong->play();
	sf::Texture tex;
	sf::Sprite sp;
	tex.setSmooth(true);
	if (!tex.loadFromFile("images_f/openingimage1.png")) {
		std::cout << "Failure";
		return EXIT_FAILURE;
	}

	
	sp.setTexture(tex);

	this->gameWindow->draw(sp);
	this->gameWindow->display();
	return 0;
}
int Game::displayStory() {
	mainMenuSong->pause();
	storySong->play();

	gameWindow->setActive(true);
	std::string image = "images_f/1story.png@images_f/2story.png@images_f/3story.png@images_f/4story.png@";
	std::string waitTime = "6@6@5@4@";
	Image_player img_list(image,waitTime, 4);
	img_list.image_display_function(gameWindow);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	storySong->stop();
	gameWindow->setActive(false);
	return 0;
}
void Game::handleEvents() {
	int isPlaymode = 0;
	while (gameWindow->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			gameWindow->close();
	
			break;

		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Escape) {
/*				if (isPlaymode) {
					gameWindow->setActive(false);
					std::function<int()> job = std::bind(&Menu::displayMenu, this->mainMenu);
					workerPool->addJob(job);

				}
*/				break;
			}
			else if (event.key.code == sf::Keyboard::Return) {
				std::cout << "Menu no." << mainMenu->menuSelected << std::endl;
				std::function<int()> job;
				switch (mainMenu->menuSelected) {
				case 0:
					mainMenuSong->pause();
					gameWindow->setActive(false);
					job= std::bind(&Game::displayStory, this);
					workerPool->addJob(job);
					isPlaymode = 1;
					break;

				case 1:

					break;
				case 2:
					gameWindow->clear(sf::Color::Black);
					gameWindow->close();
					break;
				}
			
			}
			else if (event.key.code == sf::Keyboard::Up) {
				gameWindow->setActive(true);
				mainMenu->moveUp();
				break;
			}
			else if (event.key.code == sf::Keyboard::Down) {
				gameWindow->setActive(true);
				mainMenu->moveDown();
				break;
			}

			else if (event.key.code == sf::Keyboard::Space) {
				mainMenuSong->pause();
				mainMenuSong->play();
				gameWindow->setActive(false);
				std::function<int()> job = std::bind(&Menu::displayMenu,this->mainMenu);
				workerPool->addJob(job);
				break;
			}

		}
	}
}
void Game::update() {


}

void Game::render() {


}

Game::~Game() {

}

