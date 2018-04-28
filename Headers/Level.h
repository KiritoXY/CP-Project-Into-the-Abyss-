#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "sounds.h"
#include "Player.h"
#include "enemy_base.h"
#include "thebird.h"
#include "boss.h"
using namespace std;
class Level{
private:
	int bulletRange;
	sf::Font font;//storing fonts
	sf:: Text text_on_screen;//storing text
	sf:: Texture levelTexture;
	sf::Sprite levelSprite;
	sf:: Texture scene2T;
	sf::Sprite scene2S;
	sounds *thesound;
	Player Player1;
	enemy_base *enemy;
	boss theboss;
	sf::View levelView;
	sf::Vector2f position;
	int start;
	int scene;
	int check_bullet;
	int col;
public:
	Level(void);
	Level(string, string, string, sf::RenderWindow &,string);
	void drawLevel(int, sf::RenderWindow &);
	void drawChangedLevel(string, char, sf::RenderWindow &);
	void setCamraView(sf::RenderWindow&);
	void assoicatesound(sounds *);
	void startsound();
	void stopsound();
	int getScene();
	void drawSimpleLevel(sf::RenderWindow &); 
	Player *returnplayer();
	bullet &returnbullet();
	enemy_base *returnenemy();
	boss *returnboss();
	void delenemy();
	void setcol(int);
	~Level(void);
};

