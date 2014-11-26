#include "stdafx.h"
#include "Math.h"

float Math::getDistance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	distance = sqrt(((pos2.x-pos1.x)*(pos2.x-pos1.x))+((pos2.y-pos1.y)*(pos2.y-pos1.y)));

	return distance;
}
