#pragma once
#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
class credit
{
private:
	sf::Texture bTexture;
	sf::Sprite bSprite;

public:
	credit(string);//constructor
	void draw(sf::RenderWindow &);//drawing window
	~credit(void);//destructor
};

