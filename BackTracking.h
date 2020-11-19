#pragma once
#include "Strategy.h"

class BackTracking:public Strategy {

	int index;
	vector<string> colorPallete;

	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	void bruteForce(vector<Country*> pVector, Country* pTriggerBackTracking, std::vector<Country*>::iterator pFirstCountry);
	void tryToPaint(Country* pCountry,string color);
};