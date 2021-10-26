#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ball.h"
#include "player.h"
#include <iostream>


bool intersect(Player& a,Ball& b) //test
{
	if (b.getPosition().x >= a.left() && b.getPosition().x <= a.right() && b.getPosition().y >= a.getPosition().y){
		return true;
	}
	return false;
}

void test(Player& a, Ball& b, sf::RenderWindow& window)
{
	
	if(intersect(a,b)){
		b.moveUp();
	  a.score+=1;
		std::cout<<"score: "<<a.score<<std::endl;
		}

	else if(b.getPosition().y > a.getPosition().y)
		window.close();
	
}

int main()
{

	Ball ball(400, 300);
	Player player(400, 570);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
		window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		ball.update();
		player.update();	
		window.draw(ball);
		window.draw(player);
		player.scoretext(window);
		window.display();
		test(player, ball, window);
	}
	

	return 0;
}
