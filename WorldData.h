#pragma once
#include "Country.h"

class WorldData 
{

public:
	int width;
	int height;
	std::vector<Country*> countries;

	WorldData(int pWidth, int pHeight, std::vector<Country*> pCountries);
};