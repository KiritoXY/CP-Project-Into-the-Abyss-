#include "thebird.h"
#include <Windows.h>


thebird::thebird(string imgname):enemy_base(imgname)
	{
		   entityspirte.setTextureRect(sf::IntRect(0,0,47,44));
		   dieds=0;
	}


thebird::~thebird(void)
	{
	}
void thebird::draw_the_entity(sf::RenderWindow &window)
{
     if(dieds == 0)
	{
	    if(x == 0)
	{
		clocks.restart();
		x=1;
	}
	times=clocks.getElapsedTime();
	//cout<<int(times.asMilliseconds())<<endl;
	if(int(times.asMilliseconds()) >= 350)
	{
		entityspirte.move(speed*direction,0);
		entityspirte.setTextureRect(sf::IntRect(y*47,0,47,44));
		if(y == 0)
		{
			cycling=true;
		}
		else
		{
			if (y == 4)
			{
				cycling=false;
			}
		}
		if(cycling==true)
		{
			y++;
		}
		else
		{
			y--;
		}
		//cout<<entityspirte.getPosition().x<<endl;
		if(entityspirte.getPosition().x <= 350)
		{
			direction=1;
			posx=2;
		}
		if(entityspirte.getPosition().x >= 500)
		{
			direction=-1;
			posx=1;
		}
		clocks.restart();
	}
	window.draw(entityspirte);
     }
	
//	window.display();

    //  window.draw(entityspirte);
}

void thebird::died(sf::RenderWindow &window, int i)
{
//	int i;
//	dieds=1;
//	 for(i=0;i<=4;i++)
//	 {
		entityspirte.setTextureRect(sf::IntRect(47*i,44*2,47,44));
		window.draw(entityspirte);

//	}
//	enemy_base::died(window, i);
}

void thebird::attack(sf::RenderWindow &window, int i)
{
	 
		entityspirte.setTextureRect(sf::IntRect(47*i,44,47,44));
		window.draw(entityspirte);
}
