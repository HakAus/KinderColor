#pragma once
#include "Includes.h"
#include "Strategy.h"
#include "ColorBucket.h"

class Divide:public Strategy {
	vector<ColorBucket*> buckets;
public:
	void execute(vector<Country*>pCountries,string pColorPallete[]);
	bool findBucket(Country * pCountry);
};