#include <SFML/Graphics.hpp>
#include <cassert>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "OPEN-WINDOW", sf::Style::Fullscreen);
	sf::Texture tex;
	sf::Sprite cartoon;
	tex.setSmooth(true);
	//	assert(tex.loadFromFile("c:\Users\ramki\Desktop\poplproject_downloads\openingimage2.png"));
	if (!tex.loadFromFile("openingimage1.png")) {
		return EXIT_FAILURE;
	}

	cartoon.setTexture(tex);

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(cartoon);
		window.display();
	}
	return 0;
}