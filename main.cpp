#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ball.h"
#include "player.h"
#include <string>
#include <iostream>

void text(Player& a, sf::RenderWindow& window)
{
	//how to draw a text from a class to the window
	sf::Font font;
	if(!font.loadFromFile("arial.ttf"))
		std::cout<<"Cant load the file"<<std::endl;
	std::string str = std::to_string(a.score);
	sf::Text text("Score: " + str, font);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	text.setPosition(10,10);

	window.draw(text);
}
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
		text(player, window);
		window.display();
		test(player, ball, window);
	}
	

	return 0;
}
