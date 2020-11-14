#pragma once

#include "Includes.h"
#include "Parser.h"

class Map {
private:
	XMLDocument* worldFile;
	CoordinateSystem* coordinateSystem;
	int colorAmount;
	string pallete[3] = { "FF4533","47FF33","F6FF33" };
	//Painter* painter;
	//Strategy currentStrategy;
public:
	Map() {
		this->worldFile = new XMLDocument();
		this->coordinateSystem = new CoordinateSystem();
		Parser::loadCountries("world.svg", coordinateSystem, worldFile);
		this->coordinateSystem->printCountryData();
	}

	//void setStrategy(string pStrategy);
	void setColorAmount(int pColorAmount);
	void prepareToPaint();//Esto se corre antes del metodo paint que usa el strategy

};