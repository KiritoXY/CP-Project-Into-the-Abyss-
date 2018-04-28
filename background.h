#pragma once
#include <SFML/Graphics.hpp>
class background{
private:
	sf:: Texture bTexture;
	sf::Sprite bSprite;

public:
	background(void);
	void viewBackground(sf::RenderWindow&);
	~background(void);
};

