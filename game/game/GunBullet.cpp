#include "GunBullet.h"

GunBullet::GunBullet(sf::Texture tex,const sf::Vector2f position, sf::Vector2f maxVelocity) {
	this->texture = tex;
	this->sprite.setTexture(texture);
	this->maxVelocity = maxVelocity;
	this->sprite.setScale(0.1f, 0.1f);
	this->sprite.setPosition(position);

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
	target->draw(this->sprite);
	return 0;
}

