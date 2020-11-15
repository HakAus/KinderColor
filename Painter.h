#pragma once
#include "Includes.h"
#include "Country.h"

class Painter 
{
private:
	XMLDocument * worldFile;

public:

	Painter(XMLDocument * pWorldFile);

	void paintCountry(string pCountryId, string pColor);
	static void paintWorld(unordered_map<string, Country*> pWorld);
};