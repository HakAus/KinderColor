#pragma once
#include <unordered_map>
#include <string>
#include <set>
#include <iostream>
#include "Square.h"
#include "WorldData.h"

class CoordinateSystem
{
private:
	float interval;
	float width;
	float height;
	std::unordered_multimap<const char*,const char*> SquareHash;

public:
	CoordinateSystem(float pInterval, WorldData * pWorldData);
	void updateSquares(std::vector<Country*> pCountries);
	void setFrame(float pWidth, float pHeight);
	void setInterval(float pInterval);

};