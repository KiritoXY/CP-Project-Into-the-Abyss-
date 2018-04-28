#include "Player.h"
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>//sfml graphics library
#include <SFML/Audio.hpp>//sfml audio library
#include <SFML/Window.hpp>//sfml window library
using namespace std;

Player::Player(){
	//default const.
}
Player::Player(std::string imgDirectory, sf::RenderWindow &window){
	counter=0;
	direction=0;
	animationSpeed=25; //framing changing seed.
	walkingspeed=10;	//player moving speed.
	walkloop=1;
	if(!pTexture.loadFromFile(imgDirectory))
		cerr<<"Error in loading file";
	pSprite.setTexture(pTexture);
	pSprite.setPosition(window.getSize().x-(window.getSize().x-150), (window.getSize().y/2)+100);
	pSprite.setTextureRect(sf::IntRect(0, 0, 99, 128));
	checkattack=0;
	checkdaggar=0;
	health=50;
}

void Player::hit()
{
	health--;
}


Player::Player(const Player & a, sf::RenderWindow& window)
{
	this->counter=a.counter;
	this->direction=a.direction;
	this->animationSpeed=a.animationSpeed; //framing changing seed.
	this->walkingspeed=a.walkingspeed;	//player moving speed.
	this->walkloop=a.walkloop;
	if(!this->pTexture.loadFromFile("player-sprite.png"))
		cerr<<"Error in loading file";
	this->pSprite.setTexture(pTexture);
	this->pSprite.setPosition(window.getSize().x-(window.getSize().x-150), (window.getSize().y/2)+100);
	this->pSprite.setTextureRect(sf::IntRect(0, 0, 99, 128));
}

int Player::getValues(string name){
	if(name=="c"){
		return counter;
	}
	else if(name=="d"){
			return direction;
		}
		else if(name=="a"){
				return animationSpeed;
			}
			else if(name=="w"){
				return walkingspeed;
				}
				else if(name=="wa"){
					return walkloop;
				}
				else if(name == "ca")
				{
					return checkattack;
				}
				else if(name == "cd")
				{
					return checkdaggar;
				}
				else if(name =="h")
				{
					return health;
				}
}
sf::Sprite Player::get_pSprite(){
	return pSprite;
}
void Player::set_pSprite(int a,int b, int c,int d, int e, int f){
	pSprite.setTextureRect(sf::IntRect(a, b, c, d));
	pSprite.setPosition(e ,f);
		
}

void Player::setsprite(int x,int y)
{
     pSprite.setPosition(x ,y);
}

void Player::setValues(string name, int x){
	if(name=="c"){
		counter=x;
	}
	else if(name=="d"){
			direction=x;
		}
		else if(name=="a"){
				animationSpeed=x; //framing changing seed.
			}
			else if(name=="w"){
					walkingspeed=x;	//player moving speed.
				}
				else if(name=="wa"){
						walkloop=x;
					}
				else if(name == "ca")
				{
					checkattack=x;
				}
				else if(name == "cd")
				{
					checkdaggar=0;
				}
}	
void Player::inc_dec(string name, string type, int x){
	if(type=="i"){
		if(name=="c"){
			counter+=x;
		}
	}
	else if(type=="de"){
			counter-=x;
		}

}

void Player::DrawPlayer(sf::RenderWindow &window){ 
	window.draw(pSprite);
}
void Player::MovePlayer(char Direction, sf::RenderWindow &window){
	
//	for(int i=0; i<15; i++){
		switch(walkloop){ //checks if half step of walking is complete then goes to other case and loop reverse animation to complete the step.
			case 1:   //half step.
				if(Direction=='R'){
					pSprite.setTextureRect(sf::IntRect(counter*99, 0, 99, 128));
					pSprite.move(5,0);
					direction=0;
				}
				if(Direction=='L'){
					pSprite.setTextureRect(sf::IntRect(counter*99, 128*1, 99, 128));
					pSprite.move(-5,0);
						direction=1;
				}
				counter+=1;
				if(counter==8){
					walkloop=2;
					counter=7;
				}
				break;
			
			case 2: //other half step (reverse animation).
				counter-=1;
				if(Direction=='R'){
					pSprite.setTextureRect(sf::IntRect(counter*99, 0, 99, 128));
					pSprite.move(walkingspeed,0);
					direction=0;
					
				}
				if(Direction=='L'){
					pSprite.setTextureRect(sf::IntRect(counter*99, 128*1, 99, 128));
					pSprite.move(-walkingspeed,0);
					direction=1;
				}
				if(counter==0)
					walkloop=1;
				break;
		}
		window.draw(pSprite);
		window.display();
		Sleep(animationSpeed);
	
//	}	
}
void Player::Atteck(sf::RenderWindow &window, int i){
	checkattack=1;
	if(direction==1){ //back Atteck.
			pSprite.setTextureRect(sf::IntRect(i*99, 128*2, -99, 128));
			Sleep(animationSpeed+25);
			

			window.draw(pSprite);
			window.display();
			window.clear();
	}
	else{  // Normal front atteck.
			pSprite.setTextureRect(sf::IntRect(i*99, 128*2, 99, 128));
			Sleep(animationSpeed+25);

			window.draw(pSprite);
			window.display();
			window.clear();
	}
}
void Player::throwDager(sf::RenderWindow &window, int i){
	checkdaggar=1;
	if(direction==1){  //back atteck
			pSprite.setTextureRect(sf::IntRect(i*99, 128*3, -99, 128));
			Sleep(animationSpeed+30);

			window.draw(pSprite);
			window.display();
			window.clear();

	}
	else{  //normal front atteck.
			pSprite.setTextureRect(sf::IntRect(i*99, 128*3, 99, 128));
			Sleep(animationSpeed+30);

			window.draw(pSprite);
			window.display();
			window.clear();

	}
	
}
sf::Vector2f Player::getPosition(){
	return pSprite.getPosition();
}

void Player::setBullet(int x, int y){
	bullet1.setBulletPosition(x, y);
}
void Player::fireBullet(sf::RenderWindow &window, int d){
	bullet1.fire(window, d);
}

bullet *Player::returnbull()
{
       return& bullet1;
}