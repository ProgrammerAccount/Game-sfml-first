#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream> 

class arrow
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	arrow(int y)
	{
		if (!texture.loadFromFile("strzala.png"))
		{
			std::cout << "Textures not found! ERROR";
			return;
		}
	
		
		
		this->sprite.setTexture(texture);
		this->sprite.setPosition(y, 0);

	}
	void setPostion()
	{
		srand(time(NULL));
		int x = rand() % 720 + 1;
		int a = 200;
		srand(time(NULL));
		int b = rand() % 2 + 1;
		if ((b == 2) || (x + a > 720))
			x = x - a;
		else if (b == 1)
			x = x + a;
		else if (x < 0)
			x = 0;
	}
	void arrowMoving()
	{
		sprite.move(0, 2);
		
	}
 
};