#include "boss.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <Windows.h>
boss::boss(string img):enemy_base(img)
{
	entityspirte.setTextureRect(sf::IntRect(0,129,99,129));
	entityspirte.setPosition(695,(600/2)+100);
	index=5;
	clocks.restart();
	dieds=0;
	checker=0;
	checker_2=0;
	health=10;
}


boss::~boss(void)
{
}


void boss::entrace(sf::RenderWindow &window)
{
	times=clocks.getElapsedTime();
	//cout<<int(times.asMilliseconds())<<endl;
	if(int(times.asMilliseconds() >= 250))
	{
		if(checker == 0)
		{
			clocks.restart();
			index--;
			if(index < 0)
			{
				index=0;
				checker=1;
			}
		}
	}
	entityspirte.setTextureRect(sf::IntRect(index*99,129,100,129));
	window.draw(entityspirte);
}

void boss::attack(sf::RenderWindow &, int){}
void boss::died(sf::RenderWindow &window, int x)
{
	//cout<<"die you monster"<<endl;
			entityspirte.setTextureRect(sf::IntRect(x*99,0,100,129));
			window.draw(entityspirte);
			window.display();
			Sleep(500);
			if(x == 3)
			{
				enemy_base::died(window,1);
			}

}
void boss::draw_the_entity(sf::RenderWindow &window)
{
	entityspirte.setTextureRect(sf::IntRect(6*99,129,100,129));
	entityspirte.setPosition(695,(600/2)+100);
	if(checker ==1)
	{
		//cout<<"yes"<<endl;
		for(int i=5;i>0;i--)
		{
			entityspirte.setTextureRect(sf::IntRect(i*99,129,100,129));
			window.draw(entityspirte);
			window.display();
			Sleep(250);
		}
	}
	
}

void boss::teleport(sf::RenderWindow &window)
{
	if(checker == 1)
	{
		//cout<<"yes"<<endl;
		for(int i=0;i<6;i++)
		{
			entityspirte.setTextureRect(sf::IntRect(i*99,129,100,129));
			window.draw(entityspirte);
			window.display();
			Sleep(250);
		}
	}
	enemy_base::died(window,1);
	window.display();
}