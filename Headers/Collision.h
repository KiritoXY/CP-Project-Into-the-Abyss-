#pragma once
#include <SFML/Graphics.hpp>//sfml graphics library
#include <SFML/Audio.hpp>//sfml audio library
#include <SFML/Window.hpp>//sfml window library
#include "Player.h"
#include "bullet.h"
#include "enemy_base.h"
#include "Level.h"
#include "bullet.h"
#include "sounds.h"
#include "boss.h"
class Collision
{
private:
	Player *playerobj;
	bullet *Bulletobj;
	enemy_base *enemyobj;
	boss *enemyboss;
	Level *levelobj;
	bullet *bullobj;
	sounds *thesoundobj;
	int col_narration,bossdie;
	sf::Text end_screen;
	sf::Font font;
public:
	Collision(void);
	void setassoication(Player *,enemy_base *,Level *,sounds *,boss *);
	void checkcollision(sf::RenderWindow &);
	void reset();
	void coll_player_died(sf::RenderWindow &);
	~Collision(void);
};

