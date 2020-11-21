#pragma once
#include "Includes.h"
#include "Strategy.h"

class Divide : public Strategy 
{
	
	typedef vector<Country *>::iterator countryItr;
	unordered_map<string,unordered_set<string>> countryColors;
	
public:
	Divide(Observer * pObserver);

	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	
	void divide(vector<Country*> pCountries, countryItr pStart, countryItr pEnd, int pColorAmount);
	void conquer(vector<Country*> pCountries, int pColorAmount);
	vector<Country*> merge(vector<vector<Country*>> pCountrySections);
	void updateRestrictions(set<Country*> pNeighbors, string pColor);
	void prepareColors(vector<Country*> pCountries, vector<string> pColorPallete);

};