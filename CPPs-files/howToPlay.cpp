#include "howToPlay.h"
//#include "Player.h"
#include "Windows.h"


howToPlay::howToPlay(string imageDirectory, sf::RenderWindow &window)
{
	if(!font.loadFromFile("Dosis-ExtraBold.ttf"))//loading font to font
	{
		cerr<<"Error loading font";
	}
		text_on_screen[0].setFont(font);//play text
		text_on_screen[0].setFillColor(sf::Color::Blue);
		text_on_screen[0].setString("Press -> to move RIGHT.");
		text_on_screen[0].setPosition(300 ,240);

		text_on_screen[1].setFont(font);//play text
		text_on_screen[1].setFillColor(sf::Color::Blue);
		text_on_screen[1].setString("Press <- to move LEFT.");
		text_on_screen[1].setPosition(300 ,240);

		text_on_screen[2].setFont(font);//play text
		text_on_screen[2].setFillColor(sf::Color::Blue);
		text_on_screen[2].setString("Press 'A' to Attack.");
		text_on_screen[2].setPosition(330 ,240);

		text_on_screen[3].setFont(font);//play text
		text_on_screen[3].setFillColor(sf::Color::Blue);
		text_on_screen[3].setString("Press 'S' for throwing DAGGER");
		text_on_screen[3].setPosition(250 ,240);

		text_on_screen[4].setFont(font);//play text
		text_on_screen[4].setFillColor(sf::Color::Red);
		text_on_screen[4].setString("Press -> to learn\n NEXT MOVE!");
		text_on_screen[4].setPosition(850 ,30);
		text_on_screen[4].setScale(0.5, 0.5);

		if(!bTexture.loadFromFile("white-Background.png"))
			cerr<<"Error in loading file";
		bSprite.setTexture(bTexture);
}
void howToPlay::setPlayer(Player &player, sf::RenderWindow &window){
	this->man=new Player(player, window);
}

void howToPlay::clears(sf::RenderWindow &window){
	window.clear();
	window.display();
}

void howToPlay::movePlayer(char Direction, sf::RenderWindow &window){
	for(int i=0; i<15; i++){
		switch(man->getValues("wa")){ //checks if half step of walking is complete then goes to other case and loop reverse animation to complete the step.
			case 1:   //half step.
				if(Direction=='R'){
					man->set_pSprite((man->getValues("c")*99), 0, 99, 128 ,400 ,300);
				}
				if(Direction=='L'){
					man->set_pSprite((man->getValues("c")*99), 128*1, 99, 128, 400,300);
				}
				window.draw(bSprite);
				if(Direction=='R'){
					window.draw(text_on_screen[0]);
				}
				else{
					window.draw(text_on_screen[1]);
				}
				window.draw(text_on_screen[4]);
				window.draw(man->get_pSprite());
				window.display();
				man->inc_dec("c", "i", 1);
				if(man->getValues("c")==8){
					man->setValues("wa", 2);
					man->setValues("c", 7);
				}
				break;
			
			case 2: //other half step (reverse animation).
				man->inc_dec("c", "de", 1);
				if(Direction=='R'){
					man->set_pSprite((man->getValues("c")*99), 0, 99, 128 ,400 ,300);

				}

				window.draw(bSprite);
				if(Direction=='L'){
					man->set_pSprite((man->getValues("c")*99), 128*1, 99, 128, 400,300);
				}
				if(Direction=='R'){
					window.draw(text_on_screen[0]);
				}
				else{
					window.draw(text_on_screen[1]);
				}
				window.draw(text_on_screen[4]);

				window.draw(man->get_pSprite());
				window.display();
				if(man->getValues("c")==0)
					man->setValues("wa", 1);
				break;
		}
		window.clear();
		Sleep(man->getValues("a"));
	}	
}


void howToPlay::Atteck(sf::RenderWindow &window){
 
	for(int i=0; i<=7; i++){  //whole process of Atteck animation done here including display.
		man->set_pSprite(i*99, 128*2, 99, 128,400 ,300);
		
		Sleep(man->getValues("a")+40);
		
		window.draw(bSprite);

		window.draw(text_on_screen[4]);
		window.draw(text_on_screen[2]);
		window.draw(man->get_pSprite());
		window.display();
		window.clear();
	}
}

void howToPlay::throwDager(sf::RenderWindow &window){
	for(int i=0; i<=4; i++){  //whole process of Atteck animation done here including display.
		man->set_pSprite(i*99, 128*3, 99, 128,400 ,300);
		Sleep(man->getValues("a")+40);

		window.draw(bSprite);
		window.draw(text_on_screen[4]);
		window.draw(text_on_screen[3]);
		window.draw(man->get_pSprite());
		window.display();
		window.clear();
	}
}

int howToPlay::full(sf::RenderWindow &window){
	while(window.pollEvent(Event)){
		if (Event.type == sf::Event::Closed)
                window.close();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			window.clear();
			window.display();
			return 1;
		}
		while(true){
			movePlayer('R', window);
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				while(true){
					movePlayer('L', window);
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
						while(true){
							Atteck(window);
							if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
								while(true){
									throwDager(window);
									Sleep(300);
									if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
										window.clear();
										window.display();
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}

	}
}



howToPlay::~howToPlay(void)
{
}
