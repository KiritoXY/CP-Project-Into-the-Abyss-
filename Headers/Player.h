#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include<iostream>
#include<string>
//#include "howToPlay.h"
using namespace std;
class Player{
	protected:
		bullet bullet1; 
		int direction;
		int animationSpeed;
		float walkingspeed;
		int counter;//counts and get records of sprites used while walking.
		int walkloop; // Helps to take one full step.
		sf::Texture pTexture;
		sf::Sprite pSprite;
		int checkattack;
		int checkdaggar;
		int health;
	public:
		Player();
		void setBullet(int, int);
		void fireBullet(sf::RenderWindow &, int);
		Player(const Player &, sf::RenderWindow&);
		Player(std::string, sf::RenderWindow&);
		int getValues(string);
		sf::Sprite get_pSprite();
		void setValues(string , int);
		void set_pSprite(int, int,int,int,int,int);
		void inc_dec(string, string, int);
		void DrawPlayer(sf::RenderWindow &);
		void MovePlayer(char, sf::RenderWindow &window);
		void Atteck(sf::RenderWindow &, int);
		void throwDager(sf::RenderWindow &, int);
		void hit();
		sf::Vector2f getPosition();
		bullet* returnbull();
		void setsprite(int,int);
};
