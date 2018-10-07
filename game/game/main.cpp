#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <string>
#include "threadPool.h"
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "game.h"
#include "Player.h"


int main() {
	sf::RenderWindow *gameWindow=new sf::RenderWindow(sf::VideoMode(1366, 768), "BETRAYAL=>GAME", sf::Style::Fullscreen);
	Game * game = new Game(10, gameWindow);
	game->displayTitlescreen();
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
		
		return 0;
}


