#pragma once
#include "Player.h"

class Hero :public Player {
public:
	Hero(std::string,int,int);
	~Hero();
	void movement();
	void update();
	void draw();

private:
	int score;
	int xp;
	
	


};