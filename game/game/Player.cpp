#include "Player.h"

Player::Player(std::string imgPath, sf::Vector2f position, int health,std::string bullet) {
	this->imgPath = imgPath;
	this->bulletPath = bullet;
	this->maxhp = hp;
	this->initialPos = position;
}

Player::~Player()
{
	std::cout << "Deleted player";
}

