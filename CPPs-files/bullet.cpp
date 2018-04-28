#include "bullet.h"
#include<iostream>
using namespace std;
bullet::bullet(void){
	bulletSpeed=2;
	if(!bullTexture.loadFromFile("dagger.png")){
		cerr<<"Error in loading dagger.png";
	}
	bullSprite.setTexture(bullTexture);
	bullSprite.setTextureRect(sf::IntRect(0, 0, 58.56, 51.84));
}

void bullet::setBulletPosition(int x, int y){
	x+=60;
	y+=10;
	bullSprite.setPosition(x, y);
}

void bullet::fire(sf::RenderWindow &window, int direction){

	if(direction==0){


		bullSprite.setTextureRect(sf::IntRect(0, 0, 58.56, 51.84));
		window.draw(bullSprite);
		bullSprite.move(bulletSpeed, 0);
		window.display();
	}
	else if(direction==1){
		bullSprite.setTextureRect(sf::IntRect(58.56, 0, 58.56, 51.84));
		window.draw(bullSprite);
		bullSprite.move(-bulletSpeed, 0);
		window.display();

	}
}
bullet::~bullet(void)
{
}


sf::Sprite bullet::returnsprite()
{
      return bullSprite;
}

void bullet::setposition()
{
   bullSprite.setPosition(0,0);  
}