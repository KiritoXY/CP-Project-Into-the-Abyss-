#include <iostream>
#include <SFML/Graphics.hpp>//sfml graphics library
#include <SFML/Audio.hpp>//sfml audio library
#include <SFML/Window.hpp>//sfml window library
#include <Windows.h>
#include <stdlib.h>
#include "Collision.h"
using namespace std;

Collision::Collision(void)
{
	if(!font.loadFromFile("Fighting Spirit 2 ital.ttf"))//loading font to font
	{
		//error printing
	}
	end_screen.setFont(font);//play text
	end_screen.setFillColor(sf::Color::Red);
	end_screen.setString("You Died"); 
	col_narration=0;bossdie=0;
}

void Collision::setassoication(Player *playerobj ,enemy_base *enemyobj,Level *levelobj,sounds *thesoundobj,boss *bossobj)
{
	this->playerobj=playerobj;
	this->Bulletobj=playerobj->returnbull();
	this->enemyobj=enemyobj;
	this->levelobj=levelobj;
	this->thesoundobj=thesoundobj;
	this->enemyboss=bossobj;
}

void Collision::checkcollision(sf:: RenderWindow& window)
{
	//cout<<Bulletobj->returnsprite().getPosition().x<<endl;
	//cout<<playerobj->get_pSprite().getPosition().x<<endl;
	//(enemyobj->returnsprite().getPosition().x <= Bulletobj->returnsprite().getPosition().x)
	if((enemyobj->returnsprite().getPosition().x <= Bulletobj->returnsprite().getPosition().x))
	{
	   if(enemyobj->gethealth() !=0)
	   {
		 enemyobj->hit();
	   }
	   else
	   {
		   window.clear();
		   for(int i=0; i<=5; i++){   //Enemy died
				levelobj->drawSimpleLevel(window);
				playerobj->DrawPlayer(window);
				enemyobj->died(window, i);
				window.display();
				Sleep(150);

			}
			enemyobj->enemy_base::died(window,1);
	   }
	}
	
	if((playerobj->get_pSprite().getGlobalBounds().intersects(enemyobj->returnsprite().getGlobalBounds())))
	{
	     window.clear();
	     for(int i=0; i<=4; i++){   //player died.
			levelobj->drawSimpleLevel(window);
			playerobj->DrawPlayer(window);
			enemyobj->attack(window, i);  
			window.display();
			Sleep(150);
		}
		coll_player_died(window);  
	}
	//if(playerobj->get_pSprite().getPosition()
	if(playerobj->get_pSprite().getPosition().x <= 20){
	   playerobj->setsprite(20,(600/2)+100);
	}
	if(playerobj->get_pSprite().getPosition().x >= 915 && levelobj->getScene() == 1){
		if(col_narration == 0)
		{
			thesoundobj->dialogue_soundplay();
			col_narration=1;
			levelobj->setcol(1);
		}
	}
	if(playerobj->get_pSprite().getGlobalBounds().intersects(enemyboss->returnsprite().getGlobalBounds()) && playerobj->getValues("ca") == 1)
	{
		enemyboss->hit();
	}
	if((enemyboss->gethealth() == 0)&& bossdie==0)
	{
		thesoundobj->dialogue_soundstop();
		for(int i=0;i<4;i++)
		{
			enemyboss->died(window,i);
			playerobj->DrawPlayer(window);
		}
		bossdie=1;
		end_screen.setString("You have cleared the level");
		coll_player_died(window);
	}
	reset();
}

void Collision::coll_player_died(sf::RenderWindow &window){
	end_screen.setPosition(((playerobj->getPosition()).x) ,(playerobj->getPosition()).y/2);
	window.draw(end_screen);
	window.display();
	window.setFramerateLimit(0);
	Sleep(10000);
	exit(1);
}


void Collision::reset()
{
	playerobj->setValues("ca",0);
	playerobj->setValues("cd",0);
	Bulletobj->setposition();
}

Collision::~Collision()
{
}
