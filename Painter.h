#pragma once
#include "Includes.h"

class Painter 
{
private:
	XMLDocument * worldFile;

public:

	Painter(XMLDocument * pWorldFile);

	void paintCountry(string pCountryId, string pColor);
};