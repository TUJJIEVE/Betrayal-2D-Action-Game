#include "game.h"
#include "threadPool.h"
#include "Player.h"
#include <SFML\Audio.hpp>
#include "IntroDisplay.h"
Game::Game(int numWorkerThreads,sf::RenderWindow * window) {
	workerPool = new threadPool(numWorkerThreads);
	this->gameWindow = window;
	gameWindow->setFramerateLimit(60);
	spriteSheet.reserve(20);
	sounds.reserve(20);
	std::function<int()> job = std::bind(&Game::loading, this);
	workerPool->addJob(job);
}
int Game::loading() {
	/* MEthod to load the sprites textures for the players enemies etc..*/
	sf::Texture tex;

	for (int i = Sprites::mainScreen; i!=Lastsprite; i++) {
		switch(i) {
/*		case mainScreen:
			if (!tex.loadFromFile("images_f / openingimage1.png")) {
				std::cout << "Error loading" << i;
				return EXIT_FAILURE;
			}
			spriteSheet.push_back(sf::Sprite(tex));
			break;
*/
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
}
int Game::displayTitlescreen() {
	sf::Texture tex;
	sf::Sprite sp;
	tex.setSmooth(true);
	sf::Music  *music = new sf::Music();
	if (!tex.loadFromFile("images_f/openingimage1.png")) {
		std::cout << "Failure";
		return EXIT_FAILURE;
	}
	if (!music->openFromFile("music_f/tittlemusic.ogg")) {
		std::cout << "Failure to load the music";

		return EXIT_FAILURE;
	}

	sp.setTexture(tex);
	music->play();
	this->gameWindow->draw(sp);
	this->gameWindow->display();
	return 0;
}
int Game::displayStory() {
	std::string a = "images_f/1story.png@images_f/2story.png@images_f/3story.png@images_f/4story.png@";
	Image_player img_list(a, "6@7@8@3@", 4);
	img_list.image_display_function(gameWindow);
	return 0;
}
void Game::handleEvents() {
	
	while (gameWindow->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			gameWindow->close();
	
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) {
				gameWindow->close();
				break;
			}
			else if (event.key.code == sf::Keyboard::Space) {
				//displayStory();
				gameWindow->setActive(false);
				std::function<int()> job = std::bind(&Game::displayStory,this);
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


