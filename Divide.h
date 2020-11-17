#pragma once
#include "Includes.h"
#include "Strategy.h"
#include "ColorBucket.h"

class Divide:public Strategy {
	vector<ColorBucket*> buckets;
	int currentBucket = 0;
public:
	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	void findBucket(Country * pCountry);
	int paintedCountries();
	void nextColor();
};