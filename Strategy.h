#pragma once
#include "Includes.h"
#include "Country.h"
#include "Painter.h"

class Strategy {	
	
public:
	Painter * painter;
	string pallete[11] = { "#FF4533","#47FF33","#F6FF33","#33FFE4","#0851CF",
						   "#D100E0","#D100E0","#097D2F","#75493B","#4300C9",
						   "#E394CC"};

	virtual void execute(vector<Country*> pCountries, int pColorAmount);
	virtual void setPainter(Painter* pPainter);

};