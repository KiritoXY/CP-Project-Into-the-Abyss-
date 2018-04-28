#include "menu.h"
#include <iostream>
#include <stdlib.h>
#include <SFML/Audio.hpp>
using namespace std;

menu::menu(float width , float height)
{
	mainMenu.loadFromFile("mainMenu.png");
	mainMenuSprite.setTexture(mainMenu);
	
	selected=0;
	
	if(!font.loadFromFile("Fighting Spirit 2 ital.ttf"))//loading font to font
	{
		//error printing
	}
	if(!buffer.loadFromFile("menu.wav"))//loading sound
	{
		//error dectection
	}
	start_sound=0;
	sound.setBuffer(buffer);
	sound.setVolume(13); //setting the volume of menu sound
	text_on_screen[0].setFont(font);//play text
	text_on_screen[0].setFillColor(sf::Color::Red);
	text_on_screen[0].setString("Play");
	text_on_screen[0].setPosition(sf::Vector2f((width/2)-50 , height/2+50));
	
	text_on_screen[1].setFont(font);//how-to-play text
	text_on_screen[1].setFillColor(sf::Color::White);
	text_on_screen[1].setString("How to Play");
	text_on_screen[1].setPosition(sf::Vector2f((width/2)-100 , (height/2)+120));

	text_on_screen[2].setFont(font);//credit text
	text_on_screen[2].setFillColor(sf::Color::White);
	text_on_screen[2].setString("Credits");
	text_on_screen[2].setPosition(sf::Vector2f((width/2)-80 , (height/2)+100+85));

	text_on_screen[3].setFont(font);//exit text
	text_on_screen[3].setFillColor(sf::Color::White);
	text_on_screen[3].setString("Exit");
	text_on_screen[3].setPosition(sf::Vector2f((700*width)/800,(700*height)/800));
	/*formula for pos in new window ((postion_in_original_window[700]
	*width_of_new_window[window.getsize().x])/original screen size used[800])*/

}

menu::~menu(void)
{
}

void menu::draw(sf::RenderWindow &window)
{
	for(int i=0;i<4;i++)
	{
		window.draw(text_on_screen[i]);
	}
}

void menu::moveDOWN()
{
	if(selected == 3 )
	{
		selected=0;
		text_on_screen[3].setFillColor(sf::Color::White);
		text_on_screen[0].setFillColor(sf::Color::Red);
		sound.play();

	}
	else
	{
		text_on_screen[selected].setFillColor(sf::Color::White);
		text_on_screen[selected+1].setFillColor(sf::Color::Red);
		selected++;
		sound.play();
	}
}

void menu::moveUP()
{
	if(selected == 0)
	{
		selected=3;
		text_on_screen[0].setFillColor(sf::Color::White);
		text_on_screen[3].setFillColor(sf::Color::Red);
		sound.play();
	}
	else
	{
		text_on_screen[selected].setFillColor(sf::Color::White);
		text_on_screen[selected-1].setFillColor(sf::Color::Red);
		selected--;
		sound.play();
	}
}

int menu::getselected()
{
	return selected;
}

void menu::byebye()
{
	exit(1);
}
void menu::displayBackground(sf::RenderWindow &window){
	window.draw(mainMenuSprite);
}

void menu::assoicatesound(sounds * thesound)
{
	this->thesound=thesound;
}

void menu::startsound()
{
	if(start_sound == 0)
	{
		thesound->menuplay();
		start_sound=1;
	}
}
void menu::stopsound()
{
	if(start_sound ==1)
	{
		thesound->menustop();
		start_sound=0;
	}
}