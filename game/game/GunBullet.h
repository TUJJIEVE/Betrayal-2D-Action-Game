#pragma once
#include <SFML\Graphics.hpp>
class GunBullet {
public:

	GunBullet(sf::Texture texture, const sf::Vector2f position, sf::Vector2f maxVelocity = sf::Vector2f(15.f, 0.f));
	int movement();
	int update();
	int draw(sf::RenderTarget *target);
private:
	
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f maxVelocity;

};