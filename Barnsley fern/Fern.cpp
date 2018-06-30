#include "stdafx.h"
#include "Fern.h"


Fern::Fern(int x, int y):windowWidth(x), windowHeight(y)
{
}

sf::Vector2i Fern::mapValue(float x, float y)
{
	return {	static_cast<int>((x - width.x) / (width.y - width.x)*static_cast<float>(windowWidth)), 
				static_cast<int>(static_cast<float>(windowHeight) - (y - height.x) / (height.y - height.x)*static_cast<float>(windowHeight))};
}

sf::Vector2i Fern::mapValue(sf::Vector2f pos)
{
	return mapValue(pos.x, pos.y);
}

sf::Vector2f Fern::getPos()
{
	return currentPos;
}

void Fern::nextValue() {
	int i = rand() % 100;
	float nextX{ 0.f };
	float nextY{ 0.f };

	if (i < 85) {
		nextX =  0.85f * currentPos.x + 0.04f * currentPos.y;
		nextY = -0.04f * currentPos.x + 0.85f * currentPos.y + 1.6f;
	}
	else if (i < 92) {
		nextX = 0.20f * currentPos.x - 0.26f * currentPos.y;
		nextY = 0.23f * currentPos.x + 0.22f * currentPos.y + 1.6f;
	}
	else if (i < 99) {
		nextX = -0.15f * currentPos.x + 0.28f * currentPos.y;
		nextY =  0.26f * currentPos.x + 0.24f * currentPos.y + 0.44f;
	}
	else {
		nextX = 0.f;
		nextY = 0.16f * currentPos.y;
	}
	currentPos = { nextX, nextY };
}

