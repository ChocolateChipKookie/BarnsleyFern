// Barnsley fern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Fern.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Prozor");
	sf::Event event;
	sf::RectangleShape rect({ 1.f, 1.f });
	rect.setFillColor(sf::Color::Green);

	sf::RenderTexture texture;
	texture.create(1000, 1000);

	Fern fern(1000, 1000);

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		
		window.clear();

		//200 points get drawn between 2 frames
		for (int i{ 0 }; i < 200; i++) {
			sf::Vector2i pos{ fern.mapValue(fern.getPos()) };
			rect.setPosition(static_cast<float>(pos.x), static_cast<float>(pos.y));
			fern.nextValue();

			texture.draw(rect);
		}
		texture.display();
		sf::Sprite temp(texture.getTexture());
		window.draw(temp);
		window.display();
	}
    return 0;
}

