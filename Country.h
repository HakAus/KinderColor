#pragma once
#include "Includes.h"

class Country
{
	
	const char* id;
	const char* name;
	std::vector<std::tuple<float, float>> mapPoints;
public:
	Country(const char* pId, const char* pName);

	void setMapPoints(const char* pSvgPath);
};

