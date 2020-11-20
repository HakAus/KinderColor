#pragma once
#include "Includes.h"
#include "Strategy.h"
#include "ColorBucket.h"

class Dynamic :public Strategy {
	vector<ColorBucket*> buckets;
	int currentBucket = 0;
	int paintedCountries = 0;
public:
	Dynamic(Observer* pObserver);
	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	void findBucket(Country* pCountry);
	int unpaintedCountries(int pVectorSize);
	void nextColor();
};
