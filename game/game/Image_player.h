#pragma once
#include <SFML\Graphics.hpp>
class Image_player
{
public:
	int num_strings,sleep_time;
	std::string * str; 
	Image_player(std::string a , int n,int ti);
    int image_display_function(sf::RenderWindow * );
	~Image_player();
};

