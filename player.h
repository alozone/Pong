#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Player : 
public sf::Drawable
{
	public:
		Player(float, float);
		void update();
		void reset();
		float length=80;
		float left(),right(),top(),bottom();
		int score = 0;
		sf::Vector2f getPosition(); 
		sf::Window window;
	private:
		sf::RectangleShape ply;
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		float width=20;
		float speed{5};
		int ix,iy;
		sf::Vector2f plyMovement{speed,0.0f};

};
