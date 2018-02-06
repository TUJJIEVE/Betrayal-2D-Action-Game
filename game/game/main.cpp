#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <mutex>
#include "threadPool.h"
#include <functional>
#include <SFML/Graphics.hpp>



int main() {
	sf::RenderWindow gameWindow(sf::VideoMode(1366, 768), "OPEN-WINDOW", sf::Style::Fullscreen);
	sf::Texture tex;
	sf::Sprite sp;
	tex.setSmooth(true);
	if (!tex.loadFromFile("openingimage2.png")) {
		std::cout << "Failure";
		int n;
		std::cin >> n;
		return EXIT_FAILURE;
	}
	sp.setTexture(tex);
	sf::Event event;
	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				gameWindow.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code== sf::Keyboard::Escape) {
					gameWindow.close();
				}
			}
		}
		gameWindow.draw(sp);
		gameWindow.display();

	}
	return 0;
}

