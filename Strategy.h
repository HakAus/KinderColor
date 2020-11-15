#pragma once
#include "Includes.h"
#include "Country.h"

class Strategy {
	public:
		virtual void execute(vector<Country*> pCountries, vector<string> pColorPallete);
};