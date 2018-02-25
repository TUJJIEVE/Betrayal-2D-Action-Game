#include <SFML/Graphics.hpp>
#include "player_1.h"
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Game_v_2");	//opens window
	player_1 srikanth("images_f/sfr.png@images_f/sfl.png@images_f/sbr.png@images_f/sbl.png@images_f/srr.png@images_f/srl.png@images_f/srm.png@images_f/slr.png@images_f/sll.png@images_f/slm.png@");
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
					if (srikanth.intialseimage(sf::Vector2f(150,150)))std::cout << "file not opened!!\n";
				}
				else if (event.key.code == sf::Keyboard::Up) {
					srikanth.move_player('u', 2.0f);
					std::cout << "up key is pressed\n";
				}
				else if (event.key.code == sf::Keyboard::Down) {
					srikanth.move_player('d', 2.0f);
					std::cout << "down key is pressed\n";
				}
				else if (event.key.code == sf::Keyboard::Right) {
					srikanth.move_player('r', 2.0f);
					std::cout << "right key is pressed\n";
				}
				else if (event.key.code == sf::Keyboard::Left) {
					srikanth.move_player('l', 2.0f);
					std::cout << "left key is pressed\n";
				}
				break;
			}
		}
		
		window.clear();
		srikanth.drawplayer(&window);
		window.display();
	}

	return 0;
}