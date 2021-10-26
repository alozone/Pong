#include "player.h"
#include <iostream>
#include <string>

Player::Player(float x, float y)
{
	ply.setPosition(x,y);
	ix=x;
	iy=y;
	ply.setOrigin(length / 2, width / 2);
	ply.setFillColor(sf::Color::Green);
	ply.setSize({length, width});
	
}
void Player::draw(sf::RenderTarget& target, sf::RenderStates state) const //<- Letting our object to draw for window
{
	target.draw(this->ply, state);
}
sf::Vector2f Player::getPosition() {
	return ply.getPosition();
}
void Player::update()
{
	ply.move(plyMovement);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))) {
		plyMovement.x = -speed;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))) {
		plyMovement.x = speed;	
	}
	else if(left()<0 || right()>800)
		plyMovement.x*=-1;

}
void Player::reset()
{
	window.close();
}

float Player::left() 
{				
	return ply.getPosition().x - ply.getSize().x /2;
}

float Player::top()
{
	return ply.getPosition().y - ply.getSize().y / 2;
}

float Player::right() 
{
	return ply.getPosition().x + ply.getSize().x/2;
}

float Player::bottom()
{
	return ply.getPosition().x + ply.getSize().x/2;
}

void Player::scoretext(sf::RenderWindow& window)
{
	//how to draw a text from a class to the window
	sf::Font font;
	font.loadFromFile("arial.ttf");
	string str = to_string(score);
	sf::Text text(str, font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);

	window.draw(text);
}
