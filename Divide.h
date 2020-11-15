#pragma once
#include "Includes.h"
#include "Strategy.h"
#include "ColorBucket.h"

class Divide:public Strategy {
	vector<ColorBucket*> buckets;
public:
	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	void findBucket(Country * pCountry);
	int paintedCountries();
};