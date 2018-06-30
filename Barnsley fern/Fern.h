#pragma once
#include <SFML/Graphics.hpp>

class Fern
{
public:
	Fern(int width, int height);

	///Map the value from cartesian to to window coordinates
	sf::Vector2i mapValue(float x, float y);
	sf::Vector2i mapValue(sf::Vector2f pos);

	///Set the next value
	void nextValue();
	///Returns current position of cursor
	sf::Vector2f getPos();

private:
	sf::Vector2f currentPos{0.f, 0.f};

	//Window width and height
	int windowWidth;
	int windowHeight;

	//Visible part of the coordinate system
	const sf::Vector2f width{ -2.75f , 2.75f };
	const sf::Vector2f height{ 0.f, 10.f};
};

