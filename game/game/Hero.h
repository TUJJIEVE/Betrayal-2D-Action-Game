#pragma once

#include <SFML\Audio.hpp>
#include "threadPool.h"
#include <SFML\Audio.hpp>
#include "menu.h"
#include "Map.h"
#include "GunBullet.h"
#include "Enemy.h"

class Hero {
public:
	Hero(std::string,std::string,sf::Vector2f,int,int,int,int,int,int,int,sf::Vector2u);

	~Hero();
	int loadFiles();
	void movement();
	int update();
	void draw(sf::RenderTarget *);
	int initialize();
	int takeDamage(int damage);
	inline int setLevel(int level) {
		currentLevel = level;
		return 0;
	}
	inline sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
	inline char getDirection() {
		return presentdirection;
	}
	inline int setCurrentMap(Maps newmap) {
		currentMap = &newmap;
		return 0;
	}
	inline void setEnemies(std::vector<Enemy>& e) {
		enemies =& e;
		std::cout << "the numer safsadfs " << e.size() << "and "<<enemies->size() << std::endl;
	
	}
	inline std::vector<GunBullet> getBullets() {
		return bullets;
	}
	inline sf::FloatRect getGlobalBounds() {
		return this->sprite.getGlobalBounds();
	}
	inline int getDamage() { return rand() % this->damagemax + this->damage; }

	bool isAlive;

private:
	std::string fr, fl, br, bl, rr, rl, rm, lr, ll, lm,space; //fr = front side and right leg front similarly all others 
	sf::Texture fr_, fl_, br_, bl_, rr_, rl_, rm_, lr_, ll_, lm_;
	sf::Sprite sprite;
	sf::Texture groundTex;
	sf::Texture bulletTexture;
	sf::Texture spaceTexture;

	std::vector<Enemy>  *enemies;
	std::vector<GunBullet> bullets;
	std::vector<sf::Text> playerFollowText;

	bool is_right = 1, is_side = 1;
	int score;
	int xp;
	int hControls[5];
	int currentHp;  // current Health
	int maxhp; // max health
	int damage, damagemax;
	float acceleration;
	float maxVelocity;
	sf::Vector2u windowBounds;
	sf::Vector2f currentVelocity;
	sf::Vector2f initialPos;
	sf::Vector2f currentPos;
	sf::Vector2f nextPos,direction;

	sf::SoundBuffer gunBuffer, gunBuffer1, gunBuffer2;
	sf::Sound gunSound;
	sf::Font fontStyle;

	std::string imgPath, bulletPath;

	char presentdirection = 'd';
	float speed;
	int currentLevel;

	Maps * currentMap;

	int moveHero(sf::Vector2f);

};