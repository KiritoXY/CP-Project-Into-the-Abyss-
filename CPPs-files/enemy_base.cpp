#include "enemy_base.h"
#include <iomanip>
#include <stdlib.h>

enemy_base::enemy_base(){
	//default const.
}
enemy_base::enemy_base(string enemyImg)
{
	if(!loadingspirte.loadFromFile(enemyImg))
	{
		//handle error
	}
	entityspirte.setTexture(loadingspirte);
	entityspirte.setPosition(1100,600/2+100);
	entityspirte.setTextureRect(sf::IntRect(0,80,80,75));
	speed=15;y=0;x=0;
	clocks.restart();
	direction=-1;
	cycling=true;
	posx=1;
	health=2;
}

int enemy_base::gethealth()
{
	return health;
}

void enemy_base::hit()
{
	health--;
}
sf::Sprite enemy_base::returnsprite()
{
	return entityspirte;
}

enemy_base::~enemy_base(void)
{
}

void enemy_base::died(sf::RenderWindow &window, int x)
{
	entityspirte.setPosition(x+48398432904,x+4893204);
}
