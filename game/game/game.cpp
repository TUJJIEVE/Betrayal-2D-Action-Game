#include "game.h"
#include "threadPool.h"
#include "Player.h"
Game::Game(int numWorkerThreads,Player * p1,Player * p2) {
	workerPool = new threadPool(numWorkerThreads);
	// increment the num of players as player joins or leaves.
	hero1 = p1;
	hero2 = p2;
}

void Game::init(sf::RenderWindow * window, int frameLimit) {
	this->gameWindow = window;
	this->gameWindow->setFramerateLimit(frameLimit);
}
void Game::handleEvents() {

}
void Game::update() {


}

void Game::render() {


}


