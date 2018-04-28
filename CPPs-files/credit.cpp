#include "credit.h"
#include <iostream>
using namespace std;

credit::credit(string Image)
{
	if(!bTexture.loadFromFile(Image))//loading image
	{
		cerr<<"Error in loading image";
	}
	bSprite.setTexture(bTexture);
}


void credit::draw(sf::RenderWindow &window)
{
	window.draw(bSprite);
	window.display();
}

credit::~credit(void)
{
}
