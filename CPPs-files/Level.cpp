#include "Level.h"
#include<iostream>
#include<windows.h>

using namespace std;
//constructor
Level::Level(string levelImg, string playerImg, string enemyImg, sf::RenderWindow &window,string img): Player1(playerImg, window),theboss(img){
     scene=0;
     bulletRange=425;
     enemy=new thebird(enemyImg); 
     if(!levelTexture.loadFromFile(levelImg)){ //loading level
          cerr<<"error";
     }
     levelSprite.setTexture(levelTexture);
     if(!scene2T.loadFromFile("scene2.png")){ //loading level
          cerr<<"error";
     }
     scene2S.setTexture(scene2T);

     //View initial values.
     levelView.reset(sf::FloatRect(0, 0, unsigned int(window.getSize().x),unsigned int (window.getSize().y)));
     levelView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
     start=0;
     //Font of the txt that will apear on the screne when entring scene 2.
     if(!font.loadFromFile("Fighting Spirit 2.ttf"))//loading font to font
     {
          cerr<<"error loding scene 2!";
     }
     //Text of scene 2.
     text_on_screen.setFont(font);
     text_on_screen.setFillColor(sf::Color::Red);
     text_on_screen.setString("Falling Into The Abyss!!!");
     text_on_screen.setPosition(1605,window.getSize().y/2-100);
}
void Level::drawSimpleLevel(sf::RenderWindow & window){
	window.draw(levelSprite);
} 


int Level::getScene(){
     return scene;
}

void Level::delenemy()
{
     //->died();
}

void Level::setCamraView(sf::RenderWindow&window){
     position.x=((Player1.getPosition()).x+100)-(window.getSize().x/2);
     if(position.x<0)
          position.x=0;
     if(position.y<0)
          position.y=0;
     window.setView(levelView);
     levelView.reset(sf::FloatRect(position.x, position.y, window.getSize().x, window.getSize().y));

}
void Level::drawLevel(int scene, sf::RenderWindow &window){
     if(scene==0){
				//theboss.entrace(1,window);
				Player1.DrawPlayer(window);
				enemy->draw_the_entity(window);
				window.draw(levelSprite);
				//Sleep(5000);
     }
     else if(scene==1){
			if(col == 1)
			{
				theboss.entrace(window);
			}
				window.draw(scene2S);
				Player1.DrawPlayer(window);
     }
}
void Level::drawChangedLevel(string act, char direction,  sf::RenderWindow &window){
     //cout<<"Player x="<<Player1.getPosition().x<<endl;
     if(scene==1){
     }
     else if(Player1.getPosition().x>=1705 ){
          
          window.draw(text_on_screen);
          window.display();
          Sleep(2000);
          levelView.reset(sf::FloatRect(0, 0, unsigned int(window.getSize().x),unsigned int (window.getSize().y)));
          levelView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
          Player1.set_pSprite(0, 0, 99, 128, window.getSize().x-(window.getSize().x-150), (window.getSize().y/2)+100);
          scene=1;
          }
     
     switch(scene){
          case 0 :
               setCamraView(window); //view
               drawLevel(0, window);
               if(act=="move"){
                    Player1.MovePlayer(direction, window);
               }
               else if(act=="attack"){
                         for(int i=0; i<=7; i++){
                              drawLevel(0, window);
                              Player1.Atteck(window, i);
                         }
                    }
                    else if(act=="dagger"){
						theboss.teleport(window);
                         if(Player1.getValues("d")==0){
                              for(int i=0; i<5; i++){
                                   drawLevel(scene, window);
                                   Player1.throwDager(window, i);
                              }
                              Player1.setBullet(Player1.getPosition().x,Player1.getPosition().y);
                              for(int i=0; i<bulletRange; i++){
                                   drawLevel(scene, window);
                                   Player1.fireBullet(window, Player1.getValues("d"));
                                   
                              }
							  theboss.draw_the_entity(window);
                         }
                         else if(Player1.getValues("d")==1){
							 theboss.teleport(window);
                              for(int i=0; i<5; i++){
                                   drawLevel(scene, window);
                                   Player1.throwDager(window, i);
                              }
                              Player1.setBullet(Player1.getPosition().x-100,Player1.getPosition().y);
                              for(int i=0; i<bulletRange; i++){

                                   drawLevel(scene, window);
                                   Player1.fireBullet(window, Player1.getValues("d"));
                                   
                              }
							  theboss.draw_the_entity(window);
                         }

                    }
               break;

          case 1:
               setCamraView(window); //view
               drawLevel(1, window);
               if(act=="move"){
                    Player1.MovePlayer(direction, window);
               }
               else if(act=="attack"){
                         for(int i=0; i<=7; i++){
                              drawLevel(1, window);
                              Player1.Atteck(window, i);
                         }
                    }
                    else if(act=="dagger"){
                         if(Player1.getValues("d")==0){
							 theboss.teleport(window);
                              for(int i=0; i<5; i++){
                                   drawLevel(scene, window);
                                   Player1.throwDager(window, i);
                              }
                              Player1.setBullet(Player1.getPosition().x,Player1.getPosition().y);
                              for(int i=0; i<bulletRange; i++){
                                   drawLevel(scene, window);
                                   Player1.fireBullet(window, Player1.getValues("d"));
                                   
                              }
							  theboss.draw_the_entity(window);
                         }
                         else if(Player1.getValues("d")==1){
							 theboss.teleport(window);
                              for(int i=0; i<5; i++){
                                   drawLevel(scene, window);
                                   Player1.throwDager(window, i);
                              }
                              Player1.setBullet(Player1.getPosition().x-100,Player1.getPosition().y);
                              for(int i=0; i<bulletRange; i++){
                                   drawLevel(scene, window);
                                   Player1.fireBullet(window, Player1.getValues("d"));
                                   
                              }
							  theboss.draw_the_entity(window);
                         }
                    }
     }
     
}

void Level::assoicatesound(sounds * thesound)
{
     this->thesound=thesound;
}

void Level::startsound()
{
     if(start == 0)
     {
          thesound->level_soundplay();
          start=1;
     }
}
void Level::stopsound()
{
     if(start ==1)
     {
          thesound->level_soundstop();
          start=0;
     }
}
Level::~Level(void){
     delete enemy;
}

Player * Level::returnplayer()
{
     return &Player1;
}

enemy_base *Level::returnenemy()
{
     return enemy;
}

boss *Level::returnboss()
{
     return &theboss;
}

void Level::setcol(int col)
{
	this->col=col;
}
