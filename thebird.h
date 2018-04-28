#pragma once
#include "enemy_base.h"
#include <iostream>
#include <string>
using namespace std;
class thebird: public enemy_base
	{
	int dieds;
	public:
		thebird(string);
		void draw_the_entity(sf::RenderWindow &);
		void attack(sf::RenderWindow &, int);
		void died(sf::RenderWindow &, int);
		~thebird(void);
	};