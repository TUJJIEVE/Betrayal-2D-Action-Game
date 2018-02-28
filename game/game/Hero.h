#pragma once
#include "Player.h"
#include <SFML\Audio.hpp>
#include "threadPool.h"
#include <SFML\Audio.hpp>
#include "menu.h"

class Hero :public Player {
public:
	Hero(std::string,std::string,sf::Vector2f,int,int,int,int,int,int,int);

	~Hero();
	int loadFiles();
	void movement();
	void update(sf::Vector2u windowBounds);
	void draw(sf::RenderTarget *);
	int initialize();
	inline sf::Vector2f getPosition() {
		return sprite.getPosition();
	}

private:
	std::string fr, fl, br, bl, rr, rl, rm, lr, ll, lm; //fr = front side and right leg front similarly all others 
	sf::Texture fr_, fl_, br_, bl_, rr_, rl_, rm_, lr_, ll_, lm_;
	float speed;
	char presentdirection = 'd';
	bool is_right = 1, is_side = 1;
	std::vector<GunBullet> bullets;
	int score;
	int xp;
	int hControls[5];
	int upcount, downcount, shootcount, leftcount, rightcount;
	


};