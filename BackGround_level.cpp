#include "BackGround_level.h"



BackGround_level::BackGround_level(std::string a , float t1, float t2)
{
	img_file = a;
	img_brd = t2;
	img_len = t1;
}
void BackGround_level::init_(float a, float b, float c, float d) {
	x_ = a;
	y_ = b;
	length = c;
	breadth = d;
	if (!tex.loadFromFile(img_file))printf("unable to form texturte in background_level object");
	bg.setTexture(tex);
	bg.setTextureRect(sf::IntRect(a, b, c, d));
	printf("it came to level background\n");
}
int BackGround_level::point_lie_in_rectangle(sf::Vector2f point ,float x , float y , float l , float b) {
	if (point.x >= x && point.y >= y && point.x <= x + l && point.y <= y + b)return 1;
	return 0;
}
int BackGround_level::move_background(char direction, float speed, sf::Vector2f point1, sf::Vector2f point2) {
	float x = x_, y = y_;
	if (direction == 'w') y = y - speed;
	else if (direction == 'd') y = y + speed;
	else if (direction == 'r') x = x + speed;
	else if (direction == 'l') x = x - speed;
	if (point_lie_in_rectangle(point2,x,y,length,breadth) == 1 && point_lie_in_rectangle(point1, x, y, length, breadth) == 1) {
		if (x >= 0 && y >= 0 && x + length <= img_len && y + breadth <= img_brd) {
			//move background 
			x_ = x;
			y_ = y;
			bg.setTextureRect(sf::IntRect(x_, y_, length, breadth));
			return 1;   //1 when background is changed no need to change position of player sprite
		}
		else if (point_lie_in_rectangle(point2, x_, y_, length, breadth) == 1 && point_lie_in_rectangle(point1, x_, y_, length, breadth) == 1) {
			return 2;	//need to change player position
		}
	}
	return 0;
}
void BackGround_level::draw_back_ground(sf::RenderWindow * window_) {
	window_->draw(bg);
	printf("came here to draw in background\n");
}
BackGround_level::~BackGround_level()
{
}
