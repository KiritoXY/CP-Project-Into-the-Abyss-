#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include"Player.h"
using namespace std;
class howToPlay{
private:
	Player *man;
	sf::Texture bTexture;
	sf::Sprite bSprite;
	sf::Event Event;
	sf::Font font;//storing fonts
	sf::Text text_on_screen[5];//storing text
public:
	howToPlay(string imageDirectory, sf::RenderWindow &window);
	~howToPlay(void);
	void setPlayer(Player&, sf::RenderWindow&); 
	void clears(sf::RenderWindow &);
	int full(sf::RenderWindow &);
	void movePlayer(char, sf::RenderWindow &);
	void Atteck(sf::RenderWindow &window);
	void throwDager(sf::RenderWindow &window);
};

