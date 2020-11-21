#pragma once
#include "Includes.h"
#include "Strategy.h"
#include "ColorBucket.h"

class Dynamic : public Strategy 
{
private:
	vector<ColorBucket*> buckets;
	int currentBucket = 0;
	int paintedCountries = 0;
	int totalCountries;
public:
	Dynamic(Observer* pObserver,MemoryPainter * memPainter);
	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	int unpaintedCountries(int pVectorSize);
	void nextColor();
};
