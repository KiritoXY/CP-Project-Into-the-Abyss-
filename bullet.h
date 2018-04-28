#pragma once
#include <SFML/Graphics.hpp>
class bullet{
private:
	int bulletSpeed;
	sf::Texture bullTexture;
	sf::Sprite bullSprite;
public:

	bullet(void);
	void setBulletPosition(int, int);
	void fire(sf::RenderWindow &, int);
	sf::Sprite returnsprite();
	void setposition();
	~bullet(void);
};

