#include "CoordinateSystem.h"

CoordinateSystem::CoordinateSystem()
{
	interval = 0;
	width = 0;
	height = 0;
	
}

void CoordinateSystem::setInterval(float pInterval)
{
	interval = pInterval;
}

void CoordinateSystem::setFrame(float pWidth, float pHeight)
{
	width = pWidth;
	height = pHeight;
}

void CoordinateSystem::updateSquares(Country * pCountry)
{
	
}