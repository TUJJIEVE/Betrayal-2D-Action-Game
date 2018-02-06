#include "Player.h"

Player::Player(std::string imgPath,int maxhp) {
	this->imgPath = imgPath;
	this->maxhp = maxhp;
	setTexture();
}

Player::~Player()
{
	std::cout << "Deleted player";
}

