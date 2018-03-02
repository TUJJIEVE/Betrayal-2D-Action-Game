#include "GunBullet.h"

GunBullet::GunBullet(sf::Texture tex,const sf::Vector2f position, char direction) {
	this->texture = tex;
//	this->sprite.setTexture(tex);
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
	this->sprite.setTextureRect(sf::IntRect(position.x, position.y, 100, 100));
	this->sprite.setScale(sf::Vector2f(3.f, 3.f));
	acceleration = 0.5f;
	
	switch (direction) {
	case 'r':
		this->maxVelocity = sf::Vector2f(20.0f, 0.0f);
		this->direction = sf::Vector2f(1.f, 0.0f);
		break;
	case 'l':
		this->maxVelocity = sf::Vector2f(-20.0f, 0.0f);
		this->direction = sf::Vector2f(-1.f, 0.0f);
		break;
	case 'u':
		this->maxVelocity = sf::Vector2f(0.0f, -20.0f);
		this->direction = sf::Vector2f(0.0f, -1.0f);
		break;
	case 'd':
		this->maxVelocity = sf::Vector2f(0.0f, 20.0f);
		this->direction = sf::Vector2f(0.0f, 1.0f);
		break;

	}
	this->currentVelocity = sf::Vector2f(5.f * this->direction.x, 5.f * this->direction.y);
}


int GunBullet::movement() {
	if (acceleration > 0.f) {
		if (currentVelocity.x < this->maxVelocity.x) {
			this->currentVelocity.x += this->acceleration * this->direction.x;
		}
		if (currentVelocity.y < this->maxVelocity.y) {
			this->currentVelocity.y += this->acceleration * this->direction.y;
		}
	}
	else {
		this->currentVelocity = sf::Vector2f(this->maxVelocity.x, this->maxVelocity.y);
	}
	this->sprite.move(this->currentVelocity);
	
	return 0;
}

int GunBullet::update() {
	this->movement();
	return 0;
}

void GunBullet::draw(sf::RenderTarget * target) {
	std::cout << "drawing bullets"<<std::endl;
	target->draw(this->sprite);

}

