#pragma once
#include "Strategy.h"

class BackTracking:public Strategy {

	int index;
	vector<string> colorPallete;
	Country* triggeredBackTracking;// = null
	bool endOfAlgorithm = false;

	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	void bruteForce(vector<Country*> pVector, std::vector<Country*>::iterator pFirstCountry);
	void tryToPaint(Country* pCountry,string color);
};