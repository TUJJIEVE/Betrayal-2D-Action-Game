#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
/* enemy class and hero class will inherit from this class and 
   will implement the movement ,update and draw methods*/
class Player {
	
	public:
		Player(std::string,int);
		virtual ~Player();
		virtual void movement()=0 ;
		virtual void update()=0;
		virtual void draw()=0 ;
	protected:
		std::string imgPath;
		sf::Sprite *sprite;
		sf::Texture * tex;
		sf::RectangleShape hitbox;
		inline int setTexture() {
			if (!tex->loadFromFile(this->imgPath)) {
				return -1;
			}
			sprite->setTexture(*tex);
		
		}
		int hp;  // current Health
		int maxhp; // max health
		int currentPos;
		int nextPos;
		int level;
		int damage;

};