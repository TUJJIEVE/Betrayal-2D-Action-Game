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




int main() {
	sf::RenderWindow *gameWindow=new sf::RenderWindow(sf::VideoMode(1366, 768), "BETRAYAL=>GAME", sf::Style::Fullscreen);
	gameWindow->setKeyRepeatEnabled(false);
	
	Game * game = new Game(10, gameWindow,2,3,"maps_f/level3@maps_f/room2@");
	game->displayTitlescreen();
	while (game->running())
	{
		game->handleEvents();
		if (game->gameActive){
			game->update();
			game->render();
		}
		if (game->isgameOver) {
			game -> restart();
		}
	}
		
		return 0;
}


/*
#include <SFML/Graphics.hpp>
#include "player_1.h"
#include "Map.h"
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Game_v_2");	//opens window
	player_1 srikanth("images_f/sfr.png@images_f/sfl.png@images_f/sbr.png@images_f/sbl.png@images_f/srr.png@images_f/srl.png@images_f/srm.png@images_f/slr.png@images_f/sll.png@images_f/slm.png@");
	player_1 ujjieve("images_f/ufr.png@images_f/ufl.png@images_f/ubr.png@images_f/ubl.png@images_f/urr.png@images_f/url.png@images_f/urm.png@images_f/ulr.png@images_f/ull.png@images_f/ulm.png@");
	Maps level1("maps_f/room1", 3840, 3840, 7225);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape) {
					std::cout << "the escape key was pressed" << std::endl;
					window.close();
				}
				else if (event.key.code == sf::Keyboard::Return) {
					if (srikanth.intialseimage(sf::Vector2f(450, 450)))std::cout << "srikanth not opened!!\n";
					if (ujjieve.intialseimage(sf::Vector2f(210, 320)))std::cout << "ujjieve not opened!!\n";
					level1.initialize(0, 0, 1200, 600);
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}
				else if (event.key.code == sf::Keyboard::Up) {
					int code = level1.move_background('u', 2.0f, ujjieve.state.getPosition(), srikanth.state.getPosition());

					if (code == 2) {
						srikanth.move_player('u', 2.0f);
					}
					else if (code == 1) {
						ujjieve.shift_player('d', 2.0f);
						srikanth.move_player('u', 0.0f);
					}
					else {
						srikanth.move_player('u', 0.0f);
					}
					std::cout << "up key is pressed :: srikanth\n";
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}
				else if (event.key.code == sf::Keyboard::Down) {
					int code = level1.move_background('d', 2.0f, ujjieve.state.getPosition(), srikanth.state.getPosition());
					if (code == 2) {
						srikanth.move_player('d', 2.0f);
					}
					else if (code == 1) {
						ujjieve.shift_player('u', 2.0f);
						srikanth.move_player('d', 0.0f);
					}
					else {
						srikanth.move_player('d', 0.0f);
					}
					std::cout << "down key is pressed :: srikanth\n";
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}
				else if (event.key.code == sf::Keyboard::Right) {
					int code = level1.move_background('r', 2.0f, ujjieve.state.getPosition(), srikanth.state.getPosition());
					if (code == 2) {
						srikanth.move_player('r', 2.0f);
					}
					else if (code == 1) {
						ujjieve.shift_player('l', 2.0f);
						srikanth.move_player('r', 0.0f);
					}
					else {
						srikanth.move_player('r', 0.0f);
					}
					std::cout << "right key is pressed :: srikanth\n";
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}
				else if (event.key.code == sf::Keyboard::Left) {
					int code = level1.move_background('l', 2.0f, ujjieve.state.getPosition(), srikanth.state.getPosition());
					if (code == 2) {
						srikanth.move_player('l', 2.0f);
					}
					else if (code == 1) {
						ujjieve.shift_player('r', 2.0f);
						srikanth.move_player('l', 0.0f);
					}
					else {
						srikanth.move_player('l', 0.0f);
					}
					std::cout << "left key is pressed :: srikanth\n";
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}
				else if (event.key.code == sf::Keyboard::W) {
					int code = level1.move_background('u', 2.0f, srikanth.state.getPosition(), ujjieve.state.getPosition());
					if (code == 2) {
						ujjieve.move_player('u', 2.0f);
					}
					else if (code == 1) {
						srikanth.shift_player('d', 2.0f);
						ujjieve.move_player('u', 0.0f);
					}
					else {
						ujjieve.move_player('u', 0.0f);
					}
					std::cout << "up key is pressed :: ujjieve\n";
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}
				else if (event.key.code == sf::Keyboard::S) {
					int code = level1.move_background('d', 2.0f, srikanth.state.getPosition(), ujjieve.state.getPosition());
					if (code == 2) {
						ujjieve.move_player('d', 2.0f);
					}
					else if (code == 1) {
						srikanth.shift_player('u', 2.0f);
						ujjieve.move_player('d', 0.0f);
					}
					else {
						ujjieve.move_player('d', 0.0f);
					}
					std::cout << "down key is pressed :: ujjieve\n";
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}
				else if (event.key.code == sf::Keyboard::D) {
					int code = level1.move_background('r', 2.0f, srikanth.state.getPosition(), ujjieve.state.getPosition());
					if (code == 2) {
						ujjieve.move_player('r', 2.0f);
					}
					else if (code == 1) {
						srikanth.shift_player('l', 2.0f);
						ujjieve.move_player('r', 0.0f);
					}
					else {
						ujjieve.move_player('r', 0.0f);
					}
					std::cout << "right key is pressed :: ujjieve\n";
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}
				else if (event.key.code == sf::Keyboard::A) {
					int code = level1.move_background('l', 2.0f, srikanth.state.getPosition(), ujjieve.state.getPosition());
					if (code == 2) {
						ujjieve.move_player('l', 2.0f);
					}
					else if (code == 1) {
						srikanth.shift_player('r', 2.0f);
						ujjieve.move_player('l', 0.0f);
					}
					else {
						ujjieve.move_player('l', 0.0f);
					}
					std::cout << "left key is pressed :: ujjieve\n";
					std::cout << "positions of srikanth : ( " << srikanth.state.getPosition().x << " , " << srikanth.state.getPosition().y << " ) Positions of ujjieve : ( " << ujjieve.state.getPosition().x << " , " << ujjieve.state.getPosition().y << " )\n";
				}

				break;
			}
		}

		window.clear();
		level1.renderMap(&window);
		srikanth.drawplayer(&window);
		ujjieve.drawplayer(&window);
		//window.draw(level1.bg);
		window.display();
	}

	return 0;
}
*/