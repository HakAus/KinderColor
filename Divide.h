#pragma once
#include "Includes.h"
#include "Strategy.h"

class Divide : public Strategy 
{
	// vector<vector<Country*>> countryBlocks;
	typedef vector<Country *>::iterator countryItr;
	stack<pair<countryItr, countryItr>> sectionStack;
	
public:
	void execute(vector<Country*>pCountries, int pColorAmount);

	void divide(vector<Country*> pCountries, countryItr pStart, countryItr pEnd, int pColorAmount);
	void conquer(vector<Country*> pCountries, countryItr pStart, countryItr pEnd, int pColorAmount);
	vector<Country*> merge(vector<Country*> pCountries1, vector<Country*> pCountries2);

	void tryColor(Country* pCountry, int pColorAmount);

};