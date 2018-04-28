#include "sounds.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

sounds::sounds(void)
{
 // default constructor
}

sounds::sounds(string back_filename,string level_filename)
{
	if(!menu_sound.openFromFile(back_filename))
	{
		//handle error
	}
	menu_sound.setLoop(true);
	if(!level.openFromFile(level_filename))
	{
		//handle error
	}
	if(!dialogue.openFromFile("Castlevania SotN (Playstation) What is a man.wav"))
	{
	   //handle error
	}
	level.setLoop(true);
}

void sounds::menuplay()
{
	menu_sound.play();
}

void sounds::menustop()
{
	menu_sound.stop();
}

void sounds::level_soundplay()
{
	level.play();
}

void sounds::level_soundstop()
{
	level.stop();
}

sounds::~sounds(void)
{
}


void sounds::dialogue_soundplay()
{
	 dialogue.play();
}
void sounds::dialogue_soundstop()
{
	dialogue.stop();
}

int sounds::return_narration()
{
	return (dialogue.getDuration()).asSeconds();
}