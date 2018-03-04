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
		enemies = &e;
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
	std::vector<Enemy> * enemies;
	bool is_right = 1, is_side = 1;
	std::vector<GunBullet> bullets;
	int score;
	int xp;
	int hControls[5];
	sf::Vector2u windowBounds;


	std::vector<sf::Text> playerFollowText;
	Maps * currentMap;
	int currentLevel;
	char presentdirection = 'd';
	std::string imgPath, bulletPath;
	sf::SoundBuffer gunBuffer;
	sf::Sound gunSound;
	sf::RectangleShape hitbox;
	sf::Font fontStyle;
	float speed;
	int currentHp;  // current Health
	int maxhp; // max health
	sf::Vector2f initialPos;
	sf::Vector2f currentPos;
	sf::Vector2f nextPos;
	int level;
	int damage,damagemax;

};