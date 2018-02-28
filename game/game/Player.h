#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "GunBullet.h"
/* enemy class and hero class will inherit from this class and 
   will implement the movement ,update and draw methods*/
class Player {
	
	public:
		Player(std::string,sf::Vector2f position,int health,std::string);
		virtual ~Player();
		virtual int loadFiles() = 0;
		virtual void movement()=0 ;
		virtual void update(sf::Vector2u)=0;
		virtual void draw(sf::RenderTarget *)=0 ;
		virtual int initialize() = 0;
		sf::Sprite sprite;
		sf::Texture tex;
		sf::Texture bulletTexture;

	protected:
		
		std::string imgPath,bulletPath;
		sf::SoundBuffer gunBuffer;
		sf::Sound gunSound;
		sf::RectangleShape hitbox;
		int hp;  // current Health
		int maxhp; // max health
		sf::Vector2f initialPos;
		sf::Vector2f currentPos;
		sf::Vector2f nextPos;
		int level;
		int damage;

};