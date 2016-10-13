#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;


class Player

{
public:
sf::Sprite sprite;
int  speed;
bool crash=false;
string color;
int obwod;

sf::Vector2f position;
sf::Texture texture;
Player()
{
	if (!texture.loadFromFile("football-147854_1280.png"))
	{	
		std::cout << "Textures not found! ERROR";
		return;
	}
	sprite.setTexture(texture);
	sprite.setPosition(350,500);
}
sf::FloatRect GetBulidsBox()
{
	return this->sprite.getGlobalBounds();
}
void getPosition()
{
	this->position = this->sprite.getPosition();

}
void moveLeft()
{
	if ((this->position.x != 0) && (this->crash == false))
	{
		sprite.move(-5, 0);
	}
	

}
void moveRight()
{
	if ((this->position.x != 720)&&(this->crash == false))
	sprite.move(5, 0);
}
bool kolizja(sf::Sprite box2)
{
	
	sf::FloatRect box2globalBonus = box2.getGlobalBounds();
	sf::FloatRect box1 =this->sprite.getGlobalBounds();
	//int y =box2.getPosition().y + 146;
	if ((box1.intersects(box2globalBonus))&&(box2.getPosition().y+140==this->sprite.getPosition().y))
	{
		std::cout << this->sprite.getPosition().y<<"  Pozycja Gracza"<<std::endl;
		

		
		return true;

		
	}
	else return false;

}

void restart()
{

}
}
;