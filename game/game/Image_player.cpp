#include "Image_player.h"
#include <thread>
#include <SFML\Graphics.hpp>

Image_player::Image_player(std::string a, int n,int ti)	//ti is time for sleep if ti is negative it will take random time
{
	sleep_time = ti;
	num_strings = n;
	str = new std::string[n];
	for (int i = 0,j=0; i < n; i++) {
		std::string temp = "";
		for (; ; j++)
		{
			if (a[j] == '@')break;
			temp = temp + a[j];
		}
		j = j + 1;
		*(str + i) = temp;
	}
}

int Image_player::image_display_function(sf::RenderWindow * window) {
	//std::string imag[2] = { "1.jpg","2.png" };
	sf::Vector2f targetSize(window->getSize().x, window->getSize().y);
	for (int  i = 0; i < num_strings ; i++)
	{
		sf::Texture texture;
		if (!texture.loadFromFile(*(str + i)))return 1;
		
		sf::Sprite img_f;
		img_f.setTexture(texture);
		img_f.setScale(targetSize.x / img_f.getLocalBounds().width,targetSize.y / img_f.getLocalBounds().height);
		window->draw(img_f);
		window->display();
		std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
	}
	return 0;
}

Image_player::~Image_player()
{
	delete[]str;
}
