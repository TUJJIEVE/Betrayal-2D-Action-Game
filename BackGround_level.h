#pragma once
#include <string>
#include <SFML\Graphics.hpp>
class BackGround_level
{
public:
	std::string img_file;
	float x_, y_, length, breadth, scale_x, scale_y, img_len, img_brd;
	sf::Texture tex;  //background img
	sf::Sprite bg; // background
	BackGround_level(std::string a , float t1 , float t2);
	void init_(float a, float b, float c, float d);
	int move_background(char direction, float speed, sf::Vector2f point1, sf::Vector2f point2);
	int point_lie_in_rectangle(sf::Vector2f point, float x, float y, float l, float b);
	void draw_back_ground(sf::RenderWindow * window_);
	~BackGround_level();
};

