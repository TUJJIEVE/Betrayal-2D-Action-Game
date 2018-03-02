#include "Enemy.h"
#include <thread>
Enemy::Enemy(std::string path, std::string bullet, sf::Vector2f initialPosition, int hp, int dmgValue,int t,sf::Vector2f d,sf::Vector2u wb) {

	srand(2);
	damageMin = dmgValue;
	level = 1;
	speed = 3.5f;
	damageMax = 20;
	currentLevel = 0;
	speed = 3.5f;
	imgPath = path;
	bulletPath = bullet;
	direction = d;
	maxhp = hp;
	type = t;
	initialPos = initialPosition;

	windowBounds = wb;
	loadFiles();

}
int Enemy::initialize() {
	if (currentLevel ==1) sprite.setTexture(spaceTexture);
	else sprite.setTexture(groundTex);
//	sprite.setPosition(initialPos);
	sprite.setPosition((rand() % windowBounds.x)+ 1240 , (rand() % windowBounds.y )+ sprite.getGlobalBounds().height);
	return 0;
}

int Enemy::loadFiles() {
	int i = 0;
	while (imgPath[i] != '@') enemy1= enemy1 + imgPath[i++];
	i++;
	if (!groundTex.loadFromFile(enemy1))printf("unable to form texturtes");
	while (imgPath[i] != '@')enemy2 = enemy2 + imgPath[i++];
	i++;
	if (!spaceTexture.loadFromFile(enemy2))printf("unable to form texturtes");

	if (!bulletTexture.loadFromFile(bulletPath)) {
		std::cout << "Bullet texture not loaded" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "loaded bullet texture" << std::endl;

	if (!gunBuffer.loadFromFile("sounds_f/bullet.wav")) {
		return EXIT_FAILURE;
		std::cout << "Error loading the gun sound files for hero" << std::endl;
	}


}
int Enemy::takeDamage(int damage) {
	this->hp -= damage;
	if (this->hp <= 0) {
		this->hp = 0;
	}
	return 0;
}

void Enemy::movement() {
	
	this->sprite.move(direction * speed);
}

void Enemy::update() {
	this->movement();
}
void Enemy::draw(sf::RenderTarget * target) {
	target->draw(this->sprite);
}


