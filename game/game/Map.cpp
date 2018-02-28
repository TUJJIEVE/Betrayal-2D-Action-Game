#include "Map.h"



Maps::Maps(std::string a, float t1, float t2, int l)
{
	
	img_file = a + ".png";
	collision_layer_file = a + ".txt";
	img_brd = t2;
	img_len = t1;
	lines = l;
}
int  Maps::initialize(float a, float b, float c, float d) {
	x_ = a;
	y_ = b;
	length = c;
	breadth = d;
	if (!tex.loadFromFile(img_file)) {
		std::cout << "unable to load the map" << std::endl;
		return EXIT_FAILURE;
	}
	backGround.setTexture(tex);
	backGround.setTextureRect(sf::IntRect(a, b, c, d));
	getTilePositions();
	return 0;
	
}
void Maps::used_in_boundarycollision(sf::Vector2f point, int start, int *result) {
	std::fstream file(collision_layer_file);
	file.seekg(std::ios::beg);
	for (int i = 0; i < start - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::string temp;
	float x = 0, y = 0, l = 32, b = 32;
	*result = 0;
	for (int i = 0, j = 0; i < 1000 && file.eof(); i++) {
		file >> temp;
		while (temp[j++] != 'x');
		while (temp[j++] != '"');
		j++;
		while (temp[j++] != '"')x = x * 10 + (float)(temp[j] - '0');
		j++;
		while (temp[j++] != '"');
		j++;
		while (temp[j++] != '"')y = y * 10 + (float)(temp[j] - '0');
		if (isColliding(point, x, y, l, b) == 1) {
			*result = 1;
			break;
		}
	}
}
int Maps::getTilePositions() {

	std::fstream file(collision_layer_file);
	if (!file) {
		std::cout << "Error opening the tile file" << std::endl;
		return EXIT_FAILURE;
	}
	std::string temp;
	float x = 0.0, y = 0.0, l = 32.0, b = 32.0;
	std::cout << "no of lines " << lines << std::endl;
	for (int i = 0, j = 0; i<lines; i++)
	{
		x = 0.0;
		y = 0.0;
		file >> temp;
		file >> temp;
		file >> temp;
		std::cout << "printing the temp value " << temp << std::endl;
		j = 0;
		while (temp[j++] != '"');
		while (temp[j] != '"')x = x * 10 + (int)(temp[j++] - '0');
		j = 0;
		file >> temp;
		std::cout << temp << std::endl;
		while (temp[j++] != '"');
		while (temp[j] != '"')y = y * 10 + (int)(temp[j++] - '0');
		tilePositions.push_back(sf::Vector2f(x, y));
		file >> temp;
		file >> temp;
		file >> temp;
		file >> temp;
		file >> temp;
		file >> temp;
		file >> temp;
		file >> temp;
	}


}
int Maps::check_collision_with_boundary(char direction, float speed, sf::Vector2f point) {	//checks parralaraly
	printf("entered to check_collision_with_boundary!!\n");
	int flag = 0;
	if (direction == 'u') point.y -= speed;
	else if (direction == 'd') point.y += speed;
	else if (direction == 'r')point.x += speed;
	else if (direction == 'l')point.x -= speed;

	point.y += y_;
	point.x += x_;

	for (int i = 0; i<tilePositions.size(); i++)
	{
		if (tilePositions[i].x > point.x && tilePositions[i].y > point.y)return 0;	//helps in cheking only some pats of file as file is sorted
		if (isColliding(point, tilePositions[i].x, tilePositions[i].y, 32, 32) == 1) {
			flag = 1;
			return flag;
		}
	}
	printf("exited from check collision with boundary!!\n");
	return flag;
}
int Maps::isColliding(sf::Vector2f point, float x, float y, float l, float b) {
	printf("%f %f %f %f %f %f are need to be checked in rectange\n ", point.x, point.y, x, y, l, b);
	if (point.x >= x && point.y >= y && point.x <= x + l && point.y <= y + b)return 1;
	printf("failure\n");
	return 0;
}
int Maps::move_background(char direction, float speed, sf::Vector2f point1, sf::Vector2f point2) { //point2 needs to move
	float x = x_, y = y_;
	int flag = 0;
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
	if (check_collision_with_boundary(direction, speed, point2) == 1)return flag;
	if (isColliding(f_point2, 0, 0, length, breadth) == 1 && isColliding(point1, 0, 0, length, breadth) == 1) {
		flag = 2;	//need to change player position
	}
	if (isColliding(f_point2 + sf::Vector2f(x_, y_), x, y, length, breadth) == 1 && isColliding(f_point1 + sf::Vector2f(x_, y_), x, y, length, breadth) == 1 && flag == 2) {
		if (x >= 0 && y >= 0 && x + length <= img_len && y + breadth <= img_brd) {
			//move background 
			x_ = x;
			y_ = y;
			backGround.setTextureRect(sf::IntRect(x_, y_, length, breadth));
			flag = 1;   //1 when background is changed no need to change position of player sprite
		}
	}
	printf("%d flag in background\n", flag);
	return flag;
}
void Maps::renderMap(sf::RenderTarget * target) {

	target->draw(backGround);

}
Maps::~Maps()
{
}