#include "GunBullet.h"

GunBullet::GunBullet(sf::Texture tex,const sf::Vector2f position, char direction) {
	this->texture = tex;
	this->sprite.setTexture(tex);
	this->sprite.setScale(0.1f, 0.1f);
	this->sprite.setPosition(position);
	switch (direction) {
	case 'r':
		this->maxVelocity = sf::Vector2f(10.0f, 0.0f);
		break;
	case 'l':
		this->maxVelocity = sf::Vector2f(-10.0f, 0.0f);
		break;
	case 'u':
		this->maxVelocity = sf::Vector2f(0.0f, -10.0f);
		break;
	case 'd':
		this->maxVelocity = sf::Vector2f(0.0f, 10.0f);
		break;

	}

}


int GunBullet::movement() {
	this->sprite.move(this->maxVelocity.x, this->maxVelocity.y);
	return 0;
}

int GunBullet::update() {
	this->movement();
	return 0;
}

int GunBullet::draw(sf::RenderTarget * target) {
	std::cout << "drawing bullets"<<std::endl;
	target->draw(this->sprite);
	return 0;
}

