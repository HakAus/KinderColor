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
	void paintCountries(vector<Country *> pCountriesWithColors);
};