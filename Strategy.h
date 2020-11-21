#pragma once
#include "Includes.h"
#include "Country.h"
#include "Observable.h"
#include <utility>
#include "MemoryPainter.h"

class Strategy : public Observable{
protected:
	string fileName;
	MemoryPainter* memoryPainter;
	public:
		virtual void execute(vector<Country*> pCountries, vector<string> pColorPallete);
		string getFileName();
};