#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class GunBullet {
public:

	GunBullet(sf::Texture tex, const sf::Vector2f position, char direction);
	int movement();
	int update();
	inline sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
	inline bool isOutOfBounds(sf::Vector2u windowBounds) {
		if (sprite.getPosition().x > windowBounds.x /*|| sprite.getPosition().x <0 || sprite.getPosition().y < 0 || sprite.getPosition().y > windowBounds.y*/) {
			std::cout << sprite.getPosition().x << "and" << sprite.getPosition().y << std::endl;
			return true;
		}
		else return false;
	}
	int draw(sf::RenderTarget *target);
private:
	
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f maxVelocity;

};