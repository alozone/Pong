#include "ball.h"


Ball::Ball(float X, float Y) {
	circle.setPosition(X, Y);
	ix=X; iy=Y;
	circle.setRadius(this->circleRadius);
	circle.setFillColor(sf::Color::White);
	circle.setOrigin(this->circleRadius, this->circleRadius);
	}
void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const //<- Oddanie naszego narysowanego obiektu dla okna
{
	target.draw(circle, state);
}

void Ball::update() {
	circle.move(Movement);
	if (left() < 0)
	{
		Movement.x = ballSpeed;
	}
	else if (right() > 800)
	{
		Movement.x = -ballSpeed;
	}
	else if (top() <= 0)
	{
		Movement.y = ballSpeed;
	}
	/*else if (bottom() > 600) //jezeli wartosc pilki jest wieksza od 800 jej wektor si� zmienia
	{
		Movement.y = -ballSpeed;
	}*/
}

float Ball::left(){				
	return circle.getPosition().x - circle.getRadius();
}

float Ball::right() {
	return circle.getPosition().x - circle.getRadius();
}

float Ball::top() {
	return circle.getPosition().y - circle.getRadius();
}

float Ball::bottom() {
	return circle.getPosition().y - circle.getRadius();
}

float Ball::moveUp() {
	return Movement.y = -ballSpeed;
}

float Ball::moveLeft() {
	return this->Movement.x = -ballSpeed;
}
float Ball::moveDown() {
	return this->Movement.y = ballSpeed;
}

float Ball::moveRight() {
	return this->Movement.x = ballSpeed;
}

sf::Vector2f Ball::getPosition() {
	return circle.getPosition();
}