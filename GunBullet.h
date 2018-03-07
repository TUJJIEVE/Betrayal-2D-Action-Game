#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class GunBullet {
public:
	GunBullet();
	GunBullet(int,int,sf::Texture tex, const sf::Vector2f position, char direction);
	int movement(sf::Vector2f playerPos);
	int update(sf::Vector2f playerPos);
	inline sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
	inline bool isOutOfBounds(sf::Vector2u windowBounds) {
		if (sprite.getPosition().x > windowBounds.x || sprite.getPosition().x<0 || sprite.getPosition().y>windowBounds.y || sprite.getPosition().y<0) {
			std::cout << sprite.getPosition().x << "and" << sprite.getPosition().y << std::endl;
			return true;
		}
		else return false;
	}
	inline sf::FloatRect getGlobalBounds() {
		return sprite.getGlobalBounds();
	}
	inline sf::Vector2f getDirection() {
		return this->direction;
	}
	void draw(sf::RenderTarget &target);
	float vectorLength(sf::Vector2f v);
	sf::Vector2f normalize(sf::Vector2f v, float length);

	int playerFollow;
	float acceleration, speed;
private:

	int type;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f maxVelocity,direction;
	sf::Vector2f currentVelocity;
};