#pragma once
#include "Includes.h"
#include "Country.h"
#include "Observer.h"
#include <thread>
#include "MemoryPainter.h"
#include "coordinatesystem.h"

class Painter //XML PAINTER
{
private:
	string fileName;
	XMLDocument * worldFile;
	CoordinateSystem* coordinateSystem;
	MemoryPainter* memorryPainter;
	bool* started;
public:

	Painter(XMLDocument * pWorldFile);
	Painter(string pfilename,CoordinateSystem * pCoordinateSystem,MemoryPainter * pMemoryPainter,bool* pt);
	void startThread();//Cuando lo detengo?
	void paintCountry(string pCountryId, string pColor);
	void paintWorld();
	void run();
};