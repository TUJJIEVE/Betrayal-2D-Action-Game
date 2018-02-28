
#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <thread>
#include <iostream>
#include <fstream>



class Maps
{
public:

	Maps(std::string a, float t1, float t2, int l);
	int initialize(float a, float b, float c, float d);
	int move_background(char direction, float speed, sf::Vector2f hero1Position, sf::Vector2f hero2Position);
	void renderMap(sf::RenderTarget * target);
	int getTilePositions();
	~Maps();

private:
	std::vector<sf::Vector2f> tilePositions;
	int isColliding(sf::Vector2f point, float x, float y, float l, float b);
	int check_collision_with_boundary(char direction, float speed, sf::Vector2f point);
	void used_in_boundarycollision(sf::Vector2f point, int start, int *result);


	std::string img_file, collision_layer_file;
	int lines;
	float x_, y_, length, breadth, scale_x, scale_y, img_len, img_brd;
	sf::Texture tex;  //background img
	sf::Sprite backGround; // background


};