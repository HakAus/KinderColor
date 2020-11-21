#pragma once
#include "Includes.h"
#include "Strategy.h"

class Divide : public Strategy 
{
	
	typedef vector<Country *>::iterator countryItr;
	unordered_map<string,unordered_set<string>> countryColors;
	
public:
	void execute(vector<Country*>pCountries, int pColorAmount);
	void setPainter(Painter* pPainter);

	void divide(vector<Country*> pCountries, countryItr pStart, countryItr pEnd, int pColorAmount);
	void conquer(vector<Country*> pCountries, int pColorAmount);
	vector<Country*> merge(vector<vector<Country*>> pCountrySections);
	void updateRestrictions(set<Country*> pNeighbors, string pColor);
	void prepareColors(vector<Country*> pCountries, int pColorAmount);

};