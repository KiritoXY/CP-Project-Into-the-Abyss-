#include <iostream>
#include <SFML/Graphics.hpp>//sfml graphics library
#include <SFML/Audio.hpp>//sfml audio library
#include <SFML/Window.hpp>//sfml window library
#include "menu.h"//menu header file
#include "Player.h"
#include "credit.h"//credit header file
#include "howToPlay.h"
#include "Level.h"
#include "sounds.h"
#include "enemy_base.h"
#include "Collision.h"
using namespace std;
int main(){


	bool cred=false, play=false, howToPlaySelect=false;
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Into The Abyss"); //window
	//__________________________ All Class Objects ____________________________________________ 
	menu win(float(window.getSize().x),float(window.getSize().y));//menu object
	credit credit_make("craditImg.png");//credit object
	Player player1("player-sprite.png", window);//player object.
	Level level("level.png", "player-sprite.png", "thebird.png", window,"bosscheck.png"); //Level class object
	sounds thesound("menuback.wav","project-igi-ingame-09.wav");//Sound class object
//	enemy_base orge("enemy1.png");  // Enemy object
	howToPlay HTP("player-sprite.png", window); //HowToPlay object
	Collision coll;
	//__________________________________Assoication & Aggreation_______________________________________________________
	level.assoicatesound(&thesound);
	win.assoicatesound(&thesound);
	HTP.setPlayer(player1, window);
	coll.setassoication(level.returnplayer(),level.returnenemy(),&level,&thesound,level.returnboss());
	//__________________________________Sound_______________________________________________________
	int menustate=0;
	int playingstate=0;
	//__________________________________Events_______________________________________________________
	while (window.isOpen())
    {
	    sf::Event event;
        while (window.pollEvent(event))//loops the window and checks for event
        {
            if (event.type == sf::Event::Closed)
                window.close();
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//checking if down key is pressed
				win.moveDOWN();
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//checking if up key is pressed
				win.moveUP();
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){//checking if up key enter is pressed
				if(win.getselected()==0){//checking if play is selected.
					play=true;
				}
				if(win.getselected()==1){//checking if play is selected.
					howToPlaySelect=true;
				}
				if(win.getselected() == 2){//checking if credit is selected
					cred=true;
				}
				else if(win.getselected() == 3)//checking if exit is selected
					{
						win.byebye();
					}
			}

		}
        
		if (!cred && !play && !howToPlaySelect){//drawing menu
			window.setView(window.getDefaultView());
			window.clear();
			win.displayBackground(window);
			win.draw(window);//menu draw function
			window.display();
			level.stopsound();
			win.startsound();
		}
		else if(cred && !play && !howToPlaySelect){ //credit.
				window.clear();
				credit_make.draw(window);
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
					cred=false;
					play=false;
					howToPlaySelect=false;
				}
			}
			else if(!cred && !play && howToPlaySelect){ // How to play
					HTP.clears(window);	
					int ch=HTP.full(window);
					if(ch==1){
						cred=false;
						play=false;
						howToPlaySelect=false;
					}

				} 
				else{  //Player
					window.clear();
					int scene=level.getScene();
					level.drawLevel(scene, window);
					level.startsound();
					window.display();
					win.stopsound();
					while (window.pollEvent(event)){    //loops the window and checks for event
						if (event.type == sf::Event::Closed)
						   window.close();
						if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//checking if down key is pressed
							level.drawChangedLevel("move", 'L', window);
						if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))//checking if up key is pressed
							level.drawChangedLevel("move", 'R', window);
						if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){//checking if up key is pressed
							cred=false;
							play=false;
							howToPlaySelect=false;
						}
						if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))//checking if up key is pressed
							level.drawChangedLevel("attack", 'O', window);
						if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))//checking if up key is pressed
							level.drawChangedLevel("dagger", 'O', window);
						coll.checkcollision(window);
					}
				}
			
	}
   return 0;
}