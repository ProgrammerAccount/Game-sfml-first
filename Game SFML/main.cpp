#include <SFML/Graphics.hpp>
#include "Player.cpp"
#include <windows.h>
#include "arrow.cpp"


sf::Vector2f position;
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Player player;
	arrow *objekt[5];

	int x = 0;
	objekt[0] = new arrow(50);
	objekt[1] = new arrow(250);
	objekt[2] = new arrow(420);
	objekt[3] = new arrow(550);
	objekt[4] = new arrow(680);


	window.setFramerateLimit(65);
	while (window.isOpen())
	{
		//int y=objekt[0]->sprite.getPosition().y+146;
		//if(y==500)
		if (x == 300)
		{
			objekt[0] = new arrow(50);
			objekt[1] = new arrow(250);
			objekt[2] = new arrow(420);
			objekt[3] = new arrow(550);
			objekt[4] = new arrow(680);


			x = 0;
		}
		x++;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		
		}

		player.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.moveRight();
		}
		

		window.clear(); 
		for (int i = 0; i <= 4; i++)
		{
			objekt[i]->arrowMoving();
			if(player.kolizja(objekt[i] ->sprite))
			if (MessageBoxA(NULL, "Do u want play again?", "U are lost", MB_OK) == IDOK)
				{
			objekt[0] = new arrow(50);
			objekt[1] = new arrow(250);
			objekt[2] = new arrow(420);
			objekt[3] = new arrow(550);
			objekt[4] = new arrow(680);
			x = 0;
				}
			window.draw(objekt[i]->sprite);	
		}

		
		window.draw(player.sprite);
		window.display();
		
	}

	return 0;
}