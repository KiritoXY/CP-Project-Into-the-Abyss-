#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
class enemy_base
{
protected:
	sf::Texture loadingspirte;
	sf:: Sprite entityspirte;
	int speed,direction;//speed
	int x,y,posx;//cycling animation
	sf::Clock clocks;
	sf::Time times;
	bool cycling;
	int health;
public:
	enemy_base();
	enemy_base(string);
	sf::Sprite returnsprite();
	int gethealth();
	void hit();
	virtual void draw_the_entity(sf::RenderWindow &)=0;
	virtual void died(sf::RenderWindow &, int)=0;
	//virtual void entrace(int ,sf::RenderWindow &);
	//virtual void getattacked()=0;
	virtual void attack(sf::RenderWindow &, int)=0;
	~enemy_base(void);
};

