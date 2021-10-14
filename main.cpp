#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ball.h"
#include "player.h"
#include <iostream>

/*bool doesIntersect(Player& a, Ball& b) 
{ //checking that points will intersect
	return a.right() >= b.left() && a.left() <= b.right() 
		&& a.bottom() >= b.top() && a.top() <= b.bottom();
}*/

bool intersect(Player& a,Ball& b) //test
{
	if (a.left() >= b.right() && a.right() <= b.right() && a.top() <= b.bottom()){
		return true;
	}
	else {
		return false;
	}
}

void test(Player& a, Ball& b)
{
	if(!intersect(a,b))
		a.reset();
	if(intersect(a,b))
		b.moveUp();
}

void testY(Player& player, Ball& ball)
{
	if(ball.getPosition().y == player.getPosition().y){
		std::cout<<"Player x: "<<player.getPosition().x<<std::endl;
		std::cout<<"Ball x: "<<ball.getPosition().x<<std::endl;
	}
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
		testY(player, ball);
	}
	

	return 0;
}