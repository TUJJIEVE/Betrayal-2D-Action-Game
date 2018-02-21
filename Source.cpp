#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Clock clock;
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	sf::SoundBuffer bulletBuffer;
	sf::Sound bullet;
	if (!bulletBuffer.loadFromFile("bullet.wav"))return EXIT_FAILURE;
	if (!soundBuffer.loadFromFile("sound.wav"))return EXIT_FAILURE;
	sound.setBuffer(soundBuffer);
	bullet.setBuffer(bulletBuffer);
	// load something into the sound buffer...
	while (window.isOpen())
	{
		clock.restart();
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
					if (Event.key.code == sf::Keyboard::Escape)
						window.close();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						sound.play();
					if (Event.key.code == sf::Keyboard::Right)
						bullet.play();
					break;
			}

			window.clear();
			//window.draw(shape);
			window.display();
		}
	}
	return 0;
}