#include "menu.h"
#include <iostream>


Menu::Menu(sf::RenderWindow * window) {
	menuWindow = window;
	Menuwidth = menuWindow->getSize().x;
	MenuHeight = menuWindow->getSize().y;
	menuSelected = 0;
}

int Menu::loadMenu() { 
	/* Method to load the image, font , sound files for creating the menu*/
	
	if (!fontStyle.loadFromFile("CHILLER.TTF")) {
		std::cout << "Error loading the font " << std::endl;
		return EXIT_FAILURE;
	}
	if (!menuTexture.loadFromFile("images_f/menuImage.jpg")) {
		std::cout << " Error loading the menuImage" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Loaded menuImage" << std::endl;
	menuImage.setTexture(menuTexture);
	for (int i =0; i <NumMenuItems; i++) {
		switch (i) {
		case 0:
			menuText[i].setString("Play");
			menuText[i].setFont(fontStyle);
			menuText[i].setCharacterSize(100);
			menuText[i].setFillColor(sf::Color::Magenta);
			menuText[i].setPosition(sf::Vector2f(Menuwidth / 2, MenuHeight / (NumMenuItems + 1) *(i + 1)));
			std::cout << "loaded text" << std::endl;
			break;
		case 1:
			menuText[i].setString("Options");
			menuText[i].setFont(fontStyle);
			menuText[i].setCharacterSize(70);
			menuText[i].setFillColor(sf::Color::Cyan);
			menuText[i].setPosition(sf::Vector2f(Menuwidth / 2, MenuHeight / (NumMenuItems + 1) *(i + 1)));
			std::cout << "loaded text" << std::endl;
			break;
		case 2:
			menuText[i].setString("Exit");
			menuText[i].setFont(fontStyle);
			menuText[i].setCharacterSize(70);
			menuText[i].setFillColor(sf::Color::Cyan);
			menuText[i].setPosition(sf::Vector2f(Menuwidth / 2, MenuHeight / (NumMenuItems + 1) *(i + 1)));
			std::cout << "loaded text" << std::endl;
			break;
		}

	}
	return 0;
}

int Menu::displayMenu() {
/* Method to display the menu . The menu is displayed in a different thread so that event can be handled
	in the main game loop
*/
	menuWindow->setActive(true);  // To change the opengl context
	menuWindow->draw(menuImage);  // For drawing the menu image
	for (int i = 0; i < NumMenuItems; i++) {
		menuWindow->draw(menuText[i]);   // For drawing the text 
	}
	menuWindow->display();
	menuWindow->setActive(false);  
	return 1;
}

void Menu::moveUp() {
	menuWindow->clear(sf::Color::Black);
	if (menuSelected>=1) {
		menuText[menuSelected].setFillColor(sf::Color::Cyan);
		menuSelected--;
		menuText[menuSelected].setFillColor(sf::Color::Magenta);
		menuWindow->draw(menuImage);
		menuWindow->draw(menuText[1]);
		menuWindow->draw(menuText[2]);
		menuWindow->draw(menuText[0]);

		menuWindow->display();

	}

	//return 0;
}
void Menu::moveDown() {
	menuWindow->clear(sf::Color::Black);

	if (menuSelected+1 < NumMenuItems) {
		menuText[menuSelected].setFillColor(sf::Color::Cyan);
		menuSelected++;
		menuText[menuSelected].setFillColor(sf::Color::Magenta);
		menuWindow->draw(menuImage);
		menuWindow->draw(menuText[0]);
		menuWindow->draw(menuText[1]);
		menuWindow->draw(menuText[2]);


		menuWindow->display();

	}
	//return 0;
}
