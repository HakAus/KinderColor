#pragma once
#include "Includes.h"
#include "Country.h"
#include "Observable.h"

class Strategy : public Observable {
protected:
	string fileName;
	public:
		virtual void execute(vector<Country*> pCountries, vector<string> pColorPallete);
		string getFileName();
};