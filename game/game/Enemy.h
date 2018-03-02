#pragma once

#include <SFML\Audio.hpp>
#include "threadPool.h"
#include <SFML\Audio.hpp>
#include "menu.h"
#include "Map.h"

class Enemy{
public:

	Enemy(std::string, std::string, sf::Vector2f, int, int,int,sf::Vector2f,sf::Vector2u);
	int loadFiles();
	void movement();
	void update();
	void draw(sf::RenderTarget *);
	int initialize();
	
	inline int setLevel(int level) {
		currentLevel = level;
		return 0;
	}
	inline sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
	inline sf::Vector2f getDirection() {
		return direction;
	}
	inline int setCurrentMap(Maps newmap) {
		currentMap = &newmap;
		return 0;
	}
	inline int getHP() const {
		return this->hp;
	}
	inline sf::FloatRect getGlobalBound() {
		return sprite.getGlobalBounds();
	}
	inline int isDead() const { return this->hp <= 0; }


private:
	sf::Sprite sprite;
	sf::Texture groundTex;
	sf::Texture bulletTexture;
	sf::Texture spaceTexture;
	sf::Vector2u windowBounds;
	std::string enemy1, enemy2;
	int type;
	int damageMin;
	int damageMax;
	std::vector<sf::Text> playerFollowText;
	Maps * currentMap;
	int currentLevel;
	sf::Vector2f direction;
	std::string imgPath, bulletPath;
	sf::SoundBuffer gunBuffer;
	sf::Sound gunSound;
	sf::RectangleShape hitbox;
	sf::Font fontStyle;
	float speed;
	int hp;  // current Health
	int maxhp; // max health
	sf::Vector2f initialPos;
	sf::Vector2f currentPos;
	sf::Vector2f nextPos;
	int level;
	int damage;

	int takeDamage(int damage);

};