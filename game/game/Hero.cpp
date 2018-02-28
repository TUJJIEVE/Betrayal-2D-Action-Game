#include "Hero.h"

enum controls
{
	UP=0,
	DOWN,
	LEFT,
	RIGHT,
	SHOOT,
	LAST
};
Hero::Hero(std::string path,std::string bullet,sf::Vector2f initialPosition, int hp,int dmgValue,int up,int down,int left,int right,int shoot):Player(path,initialPosition,hp,bullet){
	//imgPath = path;
	damage = dmgValue;
	level = 1;
	xp = 0;
	score = 0;
	speed = 1.5f;
	//presentdirection = 'd';
	std::cout << this->imgPath << std::endl;
	this->hControls[controls::UP] = up;
	this->hControls[controls::DOWN] = down;
	this->hControls[controls::LEFT] = left;
	this->hControls[controls::RIGHT] = right;
	this->hControls[controls::SHOOT] = shoot;

}

void Hero::movement() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::UP]))) {
		upcount++;
//		if (upcount > 1) return;
		std::cout << "Key pressed is" << hControls[controls::UP] << std::endl;
		if (is_right)sprite.setTexture(bl_);
		else sprite.setTexture(br_);
		sprite.move(0.0f, -speed);
		is_right = !is_right;
		presentdirection = 'u';

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::DOWN]))) {
		downcount++;
//		if (downcount > 1) return;
		std::cout << "Key pressed is" << hControls[controls::DOWN]<<std::endl;
		if (is_right)sprite.setTexture(fl_);
		else sprite.setTexture(fr_);
		sprite.move(0.0f, speed);
		is_right = !is_right;
		presentdirection = 'd';
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::LEFT]))) {
		leftcount++;
	//	if (leftcount > 1) return;
		std::cout << "Key pressed is" << hControls[controls::LEFT]<<std::endl;
		if (is_side) {
			sprite.setTexture(lm_);
			is_side = !is_side;
		}
		else {
			if (is_right)sprite.setTexture(ll_);
			else sprite.setTexture(lr_);
			is_side = !is_side;
			is_right = !is_right;
		}
		
		sprite.move(-speed, 0.0f);
		presentdirection = 'l';
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::RIGHT]))) {
		rightcount++;
	//	if (rightcount > 1) return;
		std::cout << "Key pressed is" << hControls[controls::RIGHT]<<std::endl;
		if (is_side) {
			sprite.setTexture(rm_);
			is_side = !is_side;
		}
		else {
			if (is_right)sprite.setTexture(rl_);
			else sprite.setTexture(rr_);
			is_side = !is_side;
			is_right = !is_right;
		}
		sprite.move(speed, 0.0f);
		presentdirection = 'r';
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::SHOOT]))) {
		shootcount++;
	//	if (shootcount > 1) return;
		std::cout << "Present direction is" << " " << presentdirection << std::endl;
		std::cout << "Key pressed is" << hControls[controls::SHOOT]<<std::endl;
		gunSound.play();
		std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
		this->bullets.push_back(GunBullet(bulletTexture, sf::Vector2f(this->sprite.getPosition().x, this->sprite.getPosition().y),presentdirection));

	}
	
	currentPos = sprite.getPosition();

}
int Hero::initialize() {
	// Used to initilaize the position of the player
	sprite.setTexture(fr_);
	sprite.setPosition(initialPos);
	return 0;
}
void Hero::update(sf::Vector2u windowBounds) {
	//std::cout << "updating" << std::endl;
	this->movement();
	for (size_t i = 0; i < bullets.size(); i++) {
		this->bullets[i].update();
		if (bullets[i].isOutOfBounds(windowBounds)){
			std::cout << "Erasing bullets\n";
			bullets.erase(bullets.begin() + i);
		}
	}

}

void Hero::draw(sf::RenderTarget *target) {
	target->draw(sprite);
	for (size_t i = 0; i < bullets.size(); i++) {
		this->bullets[i].draw(target);
	}
	

}

int Hero::loadFiles() {
	int i = 0;
	while (imgPath[i] != '@')fr = fr + imgPath[i++];
	i++;
	if (!fr_.loadFromFile(fr))printf("unable to form texturtes");
	while (imgPath[i] != '@')fl = fl + imgPath[i++];
	i++;
	if (!fl_.loadFromFile(fl))printf("unable to form texturtes");
	while (imgPath[i] != '@')br = br + imgPath[i++];
	i++;
	if (!br_.loadFromFile(br))printf("unable to form texturtes");
	while (imgPath[i] != '@')bl = bl + imgPath[i++];
	i++;
	if (!bl_.loadFromFile(bl))printf("unable to form texturtes");
	while (imgPath[i] != '@')rr = rr + imgPath[i++];
	i++;
	if (!rr_.loadFromFile(rr))printf("unable to form texturtes");
	while (imgPath[i] != '@')rl = rl + imgPath[i++];
	i++;
	if (!rl_.loadFromFile(rl))printf("unable to form texturtes");
	while (imgPath[i] != '@')rm = rm + imgPath[i++];
	i++;
	if (!rm_.loadFromFile(rm))printf("unable to form texturtes");
	while (imgPath[i] != '@')lr = lr + imgPath[i++];
	i++;
	if (!lr_.loadFromFile(lr))printf("unable to form texturtes");
	while (imgPath[i] != '@')ll = ll + imgPath[i++];
	i++;
	if (!ll_.loadFromFile(ll))printf("unable to form texturtes");
	while (imgPath[i] != '@')lm = lm + imgPath[i++];
	i++;
	if (!lm_.loadFromFile(lm))printf("unable to form texturtes");

	/* Function to load the textures and sounds*/
	if (!bulletTexture.loadFromFile(bulletPath)) {
		std::cout << "Bullet texture not loaded" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "loaded bullet texture" << std::endl;

	if (!gunBuffer.loadFromFile("sounds_f/bullet.wav")) {
		return EXIT_FAILURE;
		std::cout << "Error loading the gun sound files for hero" << std::endl;
	}
	std::cout << "loaded gunsounds\n";
	gunSound.setBuffer(gunBuffer);
	return 0;
}
Hero::~Hero() {
		
}