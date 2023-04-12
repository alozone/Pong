#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Enemy :
public sf::Drawable
{
	public:
		Player(float, float);
		void update();
		float length=80;
		float left(),right(),top(),bottom();
		int score=0;
		sf::Vector2f getPosition();
		sf::Window window;
	private:
		sf::RectangleShape enm;
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		float width=50;
		float speed{5};
		int ix,iy;
		sf::Vector2f plyMovement{speed,0.0f};
};

