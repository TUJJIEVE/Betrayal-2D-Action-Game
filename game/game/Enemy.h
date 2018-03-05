#pragma once

#include <SFML\Audio.hpp>
#include "threadPool.h"
#include <SFML\Audio.hpp>
#include "menu.h"
#include "Map.h"
#include "GunBullet.h"
class Enemy{
public:
	Enemy(int,sf::Texture , sf::Texture, sf::Texture,sf::SoundBuffer, sf::Vector2f, int, int,int,sf::Vector2f,sf::Vector2u);
	int loadFiles();
	void movement(sf::Vector2f);
	void update(sf::Vector2f,sf::FloatRect);
	void draw(sf::RenderTarget *);
	int initialize();
	int shoot();
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
	int takeDamage(int damage);
	int type;
	float vectorLength(sf::Vector2f v);
	sf::Vector2f normalize(sf::Vector2f v, float length);
	int playerNr;

private:
	sf::Sprite sprite;
	sf::Texture groundTex;
	sf::Texture bulletTexture;
	sf::Texture spaceTexture;
	sf::Vector2u windowBounds;
	std::string enemy1, enemy2;
	
	std::vector<GunBullet> bullets;
	int damageMin;
	int damageMax;
	std::vector<sf::Text> playerFollowText;
	Maps * currentMap;
	int currentLevel;
	sf::Vector2f direction;
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


};