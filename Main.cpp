#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "Image_player.h"
#include <thread>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "OPEN-WINDOW",sf::Style::Fullscreen);
	sf::Texture tex;
	sf::Sprite cartoon;
	tex.setSmooth(true);

	if (!tex.loadFromFile("images_f/openingimage1.png")) {
		return EXIT_FAILURE;
	}
	
	cartoon.setTexture(tex);
	std::string a = "images_f/1story.png@images_f/2story.png@images_f/3story.png@images_f/4story.png@";
	Image_player img_list(a,"6@7@8@3@",4);
	sf::Event event;
	sf::Music music;
	if (!music.openFromFile("music_f\\tittlemusic.ogg")) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return -1;//error
	}
	music.play();
	while (window.isOpen())
	{
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
				else {
					// starts other thread for music and then other for image display
					std::cout << "some other key is pressed" << std::endl;
					img_list.image_display_function(&window);
					std::this_thread::sleep_for(std::chrono::seconds(10));
					//start vedio
				}
				break;

				// we don't process other types of events
			default:
				break;
			}
	
		}
		window.clear();
		window.draw(cartoon);
		window.display();
		
	}
	return 0;
}
