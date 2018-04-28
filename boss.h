#pragma once
#include "enemy_base.h"
#include "string"
class boss:public enemy_base
{
	int dieds;
	int index;
	bool checker;
	bool checker_2;
public:
	boss(string);
	~boss(void);
	void teleport(sf::RenderWindow&);
	void entrace(sf::RenderWindow &);
	void attack(sf::RenderWindow &, int);
	void died(sf::RenderWindow &, int);
	void draw_the_entity(sf::RenderWindow &);
};

