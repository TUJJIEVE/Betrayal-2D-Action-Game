#include "Hero.h"
#include "Map.h"
enum controls
{
	UP=0,
	DOWN,
	LEFT,
	RIGHT,
	SHOOT,
	LAST
};
Hero::Hero(std::string path,std::string bullet,sf::Vector2f initialPosition, int hp,int dmgValue,int up,int down,int left,int right,int shoot,sf::Vector2u wb){
	isAlive = true;
	damage = dmgValue;
	damagemax = 50;
	currentLevel = 0;
	xp = 0;
	score = 0;
	speed = 5.5f;
	imgPath = path;
	bulletPath = bullet;
	maxhp = hp;
	initialPos = initialPosition;
	windowBounds = wb;
	currentHp = maxhp;
	acceleration = 0.5f;
	this->bullets.reserve(50);
	this->maxVelocity = 8.f;
	
	this->hControls[controls::UP] = up;
	this->hControls[controls::DOWN] = down;
	this->hControls[controls::LEFT] = left;
	this->hControls[controls::RIGHT] = right;
	this->hControls[controls::SHOOT] = shoot;

}
int Hero::moveHero(sf::Vector2f direction) {
	
	return 0;
}
void Hero::movement() {
	std::cout << "sfasdfsf " << enemies->size() << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::UP]))) {
/*		if (currentLevel!=1 && currentMap->check_collision_with_boundary('u', speed, sprite.getPosition())) {
			std::cout << "Collision occured with the boundary" << std::endl;
		}
*/
		std::cout << "Key pressed is" << hControls[controls::UP] << std::endl;
		if (currentLevel!=1) {
			if (is_right)sprite.setTexture(bl_);
			else sprite.setTexture(br_);
			is_right = !is_right;

		}
		if (currentLevel == 1) {
			this->direction = sf::Vector2f(0.f, -1.f);
			if (this->currentVelocity.y > -maxVelocity) {
				this->currentVelocity.y += this->direction.y * this->acceleration;
			}
		}
		else this->currentVelocity = sf::Vector2f(0.f, -speed);

		presentdirection = 'u';

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::DOWN]))) {
/*		if (currentLevel!=1 && currentMap->check_collision_with_boundary('d', speed, sprite.getPosition())) {
			std::cout << "Collision occured with the boundary" << std::endl;
		}
*/
		std::cout << "Key pressed is" << hControls[controls::DOWN]<<std::endl;

		if (currentLevel != 1) {
			if (is_right)sprite.setTexture(fl_);
			else sprite.setTexture(fr_);
			is_right = !is_right;

		}
		if (currentLevel == 1) {
			this->direction = sf::Vector2f(0.f, 1.f);
			if (this->currentVelocity.x < this->maxVelocity) {
				this->currentVelocity.x += this->direction.x * this->acceleration;
			}
			if (this->currentVelocity.y < maxVelocity) {
				this->currentVelocity.y += this->direction.y * this->acceleration;
			}
		}

		else this->currentVelocity = sf::Vector2f(0.f, speed);
		presentdirection = 'd';

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::LEFT]))) {
/*		if (currentLevel!=1 && currentMap->check_collision_with_boundary('l', speed, sprite.getPosition())) {
			std::cout << "Collision occured with the boundary" << std::endl;
		}
*/
		std::cout << "Key pressed is" << hControls[controls::LEFT]<<std::endl;
		if (currentLevel != 1) {
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
		}
		if (currentLevel == 1) {
			this->direction = sf::Vector2f(-1.f, 0.f);
			if (this->currentVelocity.x > -this->maxVelocity) {
				this->currentVelocity.x += this->direction.x * this->acceleration;
			}
		}

		else this->currentVelocity = sf::Vector2f(-speed, 0.f);
		presentdirection = 'l';
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::RIGHT]))) {
/*		if (currentLevel!=1 && currentMap->check_collision_with_boundary('r', speed, sprite.getPosition())) {
			std::cout << "Collision occured with the boundary" << std::endl;
		}
*/
		std::cout << "Key pressed is" << hControls[controls::RIGHT]<<std::endl;
		if (currentLevel != 1) {
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
		}
		if (currentLevel == 1) {
			this->direction = sf::Vector2f(1.f, 0.f);
			if (this->currentVelocity.x < this->maxVelocity) {
				this->currentVelocity.x += this->direction.x * this->acceleration;
			}
		}
		else this->currentVelocity = sf::Vector2f(0.f, speed);
		presentdirection = 'r';
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(hControls[controls::SHOOT]))) {
//		std::cout << "Present direction is" << " " << presentdirection << std::endl;
//		std::cout << "Key pressed is" << hControls[controls::SHOOT]<<std::endl;
		gunSound.play();
		std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
		if (currentLevel!=1) this->bullets.push_back(GunBullet(-1,0,bulletTexture,this->sprite.getPosition(),presentdirection));
		else this->bullets.push_back(GunBullet(-1,0,bulletTexture, this->sprite.getPosition(), 'r'));
	}
	sprite.move(this->currentVelocity);
	currentPos = sprite.getPosition();

}

int Hero::initialize() {
	// Used to initilaize the position of the player
	currentHp = 100;
	if (currentLevel == 0 || currentLevel == 2) {
		speed = 2.5f;
		sprite.setTexture(fr_);
	}
	else {
		gunSound.setBuffer(gunBuffer);
		sprite.setTexture(spaceTexture);
	}
	for (size_t i = 0; i < bullets.size(); i++) {
		bullets.erase(bullets.begin() + i);
	}
	sprite.setPosition(initialPos);

	return 0;

}

int Hero::update() {
	/* If collision occurs with the boundary then donot move else move*/
	this->movement();
	for (size_t i = 0; i < playerFollowText.size(); i++) {

		this->playerFollowText[i].setPosition(this->sprite.getPosition().x,this->sprite.getPosition().y-15.f);
		this->playerFollowText[i].setString("hp:"+ std::to_string(currentHp));
	}
//	std::cout << "Number of enemies in hero class are" << enemies->size()<<std::endl;
	bool bulletremoved = false;

	for (size_t i = 0; i < bullets.size(); i++) {
		this->bullets[i].update(sf::Vector2f(0,0));
		
		std::cout << enemies->size()<<std::endl;
		for (size_t j = 0; j < enemies->size(); j++) {
			sf::FloatRect bound = enemies->at(j).getGlobalBound();
			if (this->bullets[i].getGlobalBounds().intersects(bound)) {
//				std::cout << "Hit" << std::endl;
				enemies->at(j).takeDamage(this->getDamage());
				if (enemies->at(j).isDead()) enemies->erase(enemies->begin() + j);
				//	enemies->erase(enemies->begin() + j);
				//		enemies->at(j).takeDamage(damage);
				bullets.erase(bullets.begin() + i);
				std::cout << "Erasing bullets after hitting\n";
				bulletremoved = true;
				break;
			}
		}
		if (!bulletremoved && bullets[i].isOutOfBounds(windowBounds)){
			std::cout << "Erasing bullets\n";
			bullets.erase(bullets.begin() + i);
		}
		bulletremoved = false;
	}

	return 0;
}

void Hero::draw(sf::RenderTarget *target) {

	target->draw(sprite);
	for (size_t i = 0; i < playerFollowText.size(); i++) {
		target->draw(playerFollowText[i]);
	}
	for (size_t i = 0; i < bullets.size(); i++) {
		this->bullets[i].draw(*target);
	}
	

}

int Hero::loadFiles() {
	/* Function to load the textures and sounds*/

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
	while (imgPath[i] != '@') space = space + imgPath[i++];
	i++;
	if (!spaceTexture.loadFromFile(space)) {
		std::cout << "Space ship not loaded" << std::endl;
		return EXIT_FAILURE;
	}
	if (!bulletTexture.loadFromFile(bulletPath)) {
		std::cout << "Bullet texture not loaded" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "loaded bullet texture" << std::endl;

	if (!gunBuffer.loadFromFile("sounds_f/bullet.wav")) {
		return EXIT_FAILURE;
		std::cout << "Error loading the gun sound files for hero" << std::endl;
	}
	if (!gunBuffer2.loadFromFile("sounds_f/gun1.wav"));
	if (!gunBuffer1.loadFromFile("sounds_f/gun2.wav"));

	if (!fontStyle.loadFromFile("CHILLER.TTF")) {
		std::cout << "Error loading the font for hero" << std::endl;
		return EXIT_FAILURE;
	}
	sf::Text tempText;
	for (size_t i = 0; i < 1; i++) {
		tempText.setFont(fontStyle);
		tempText.setCharacterSize(15);
		tempText.setFillColor(sf::Color::White);
		tempText.setString("N/A");
		this->playerFollowText.push_back(tempText);

	}
	std::cout << "loaded gunsounds\n";
	gunSound.setBuffer(gunBuffer2);
	return 0;
}


int Hero::takeDamage(int damage) {
	this->currentHp -= damage;
	if (currentHp < 0) {
		currentHp = 0;
		isAlive = false;
	}
	return 0;
}
Hero::~Hero() {
		
}