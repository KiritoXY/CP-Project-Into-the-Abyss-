#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
using namespace std;
class sounds
{
private:
	sf::Music menu_sound;
	sf::Music level;
	sf:: Music dialogue;

public:
	sounds(void);
	sounds(string ,string);
	void menuplay();
	void menustop();
	void level_soundplay();
	void level_soundstop();
	void dialogue_soundplay();
	void dialogue_soundstop();
	int return_narration();
	~sounds(void);
};

