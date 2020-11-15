#pragma once
#include "Includes.h"

class Strategy {
	public:
		virtual void execute(vector<Country*> pCountries,string pColorPallete[]);
};