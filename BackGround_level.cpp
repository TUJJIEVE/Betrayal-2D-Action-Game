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
	if (!test_tex.loadFromFile("images_f/test.png"))printf("unable to form texturte in background_level object");
	test_sprite.setTexture(test_tex);
	printf("it came to level background\n");
}
int BackGround_level::point_lie_in_rectangle(sf::Vector2f point ,float x , float y , float l , float b) {
	printf("%f %f %f %f %f %f are need to be checked in rectange\n ",point.x,point.y,x,y,l,b);
	if (point.x >= x && point.y >= y && point.x <= x + l && point.y <= y + b)return 1;
	printf("failure\n");
	return 0;
}
int BackGround_level::move_background(char direction, float speed, sf::Vector2f point1, sf::Vector2f point2) { //point2 needs to move
	float x = x_, y = y_;
	int flag = 0;
	/*point1 += sf::Vector2f(x_, y_);
	point1 += sf::Vector2f(x_, y_);*/
	sf::Vector2f f_point1 = point1, f_point2 = point2;// future points for both players
	if (direction == 'u') {
		y = y - speed;
		f_point1.y += speed;
		f_point2.y -= speed;
	}
	else if (direction == 'd') {
		y = y + speed;
		f_point1.y -= speed;
		f_point2.y += speed;
	}
	else if (direction == 'r') {
		x = x + speed;
		f_point1.x -= speed;
		f_point2.x += speed;
	}
	else if (direction == 'l') {
		x = x - speed;
		f_point1.x += speed;
		f_point2.x -= speed;
	}
	if (point_lie_in_rectangle(f_point2, 0, 0, length, breadth) == 1 && point_lie_in_rectangle(point1, 0,0, length, breadth) == 1) {
		flag = 2;	//need to change player position
	}
	if (point_lie_in_rectangle(f_point2+sf::Vector2f(x_,y_),x,y,length,breadth) == 1 && point_lie_in_rectangle(f_point1+sf::Vector2f(x_,y_), x, y, length, breadth) == 1 && flag == 2) {
		if (x >= 0 && y >= 0 && x + length <= img_len && y + breadth <= img_brd) {
			//move background 
			x_ = x;
			y_ = y;
			bg.setTextureRect(sf::IntRect(x_, y_, length, breadth));
			flag = 1;   //1 when background is changed no need to change position of player sprite
		}
	}
	printf("%d flag in background\n",flag);
	return flag;
}
void BackGround_level::draw_back_ground(sf::RenderWindow * window_) {
	
	//window_->draw(test_sprite);
	window_->draw(bg);
	//printf("came here to draw in background\n");
}
BackGround_level::~BackGround_level()
{
}
