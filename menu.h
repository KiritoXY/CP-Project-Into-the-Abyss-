#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "sounds.h"
class menu
{
private:
	int selected;
	sf::Texture mainMenu; // menu image
	sf::Sprite mainMenuSprite;
	sf::Font font;//storing fonts
	sf::SoundBuffer buffer;//storing sound
	sf:: Text text_on_screen[4];//storing texty
	sf::Sound sound;
	sounds *thesound;
	int start_sound;
public:
	menu(float width ,float height);//constructor
	~menu(void);
	void draw(sf::RenderWindow &window);//drawing the window of class
	void moveUP();//moving menu up
	void moveDOWN();//moving menu down
	int getselected();
	void byebye();//exiting function
	void assoicatesound(sounds *);
	void startsound();
	void stopsound();
	void displayBackground(sf::RenderWindow &window);
};

