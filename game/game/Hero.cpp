#include "Hero.h"

Hero::Hero(std::string path, int hp,int dmgValue) :Player(path, hp) {
	damage = dmgValue;
	level = 1;
	xp = 0;
	score = 0;
}

void Hero::movement() {

}

void Hero::update() {

}

void Hero::draw() {

}

Hero::~Hero() {

}