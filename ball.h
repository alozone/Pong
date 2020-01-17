#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Ball : 
public sf::Drawable
{
	public:
		Ball(float X, float Y);
		void update(); //deklaracja
		float top(), bottom(), left(), right(); //deklaracja osi okna odbijania sie pilki
		float moveUp(), moveRight(), moveDown(), moveLeft();
		sf::Vector2f getPosition();
		short r=10;
		float setPosition(float, float);
	private:
		sf::CircleShape circle; //Pileczka
		const float circleRadius{ 10.0 }; //radius - 10
		const float ballSpeed{ 5.0f }; 
		sf::Vector2f Movement{ ballSpeed,ballSpeed };
		void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //override it's like virtual, takes a parents parameters
		int ix,iy;

};