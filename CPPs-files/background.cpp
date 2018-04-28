#include "background.h"
#include<iostream>
using namespace std;
background::background(void)
{
	if(!bTexture.loadFromFile("background.png")){
		cerr<<"error";
	}
	bSprite.setTexture(bTexture);
}
void background::viewBackground(sf::RenderWindow &window){
	window.draw(bSprite);
}

background::~background(void)
{
}
