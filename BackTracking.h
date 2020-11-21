#pragma once
#include "Strategy.h"

class BackTracking : public Strategy {

private:
	int index;
	vector<string> colorPallete;
	Country* triggeredBackTracking;
	bool endOfAlgorithm = false;
	int currentColor = 0;

	void bruteForce(vector<Country*> pVector, std::vector<Country*>::iterator pFirstCountry);
	void tryToPaint(Country* pCountry, string color);

public:
	BackTracking(Observer* pObserver, MemoryPainter* pMemoryPainter);
	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	void nextColor();
};