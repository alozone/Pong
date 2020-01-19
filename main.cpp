#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ball.h"
#include "player.h"
#include <iostream>

bool doesIntersect(Player& a, Ball& b) 
{ //checking that points will intersect
	return a.right() >= b.left() && a.left() <= b.right() 
		&& a.bottom() >= b.top() && a.top() <= b.bottom();
}

bool test(Player& player,Ball& ball) //test
{
	if (!doesIntersect(player, ball)){ 
		return false;
	}
	ball.moveUp();
	if (ball.getPosition().x < player.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > player.getPosition().x)
	{
		ball.moveRight();
	}
		//player.reset();
}

int main()
{

	Ball ball(400, 300);
	Player player(400, 570);

	sf::RenderWindow window(sf::VideoMode(800, 600), "FirstGame");
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
		window.display();
		test(player, ball);
	}
	

	return 0;
}