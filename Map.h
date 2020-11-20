#pragma once

#include "Includes.h"
#include "Parser.h"
#include "Painter.h"
#include "Strategy.h"
#include "Divide.h"

class Map {

private:
	XMLDocument* worldFile;
	CoordinateSystem* coordinateSystem;
	int colorAmount;
	string pallete[11] = { "FF4533","47FF33","F6FF33","#33FFE4","#0851CF",
						   "#D100E0","#D100E0","#097D2F","#75493B","#4300C9",
						   "#E394CC"};
	Painter* painter;
	Strategy* currentStrategy;
public:
	Map() {
		this->worldFile = new XMLDocument();
		this->coordinateSystem = new CoordinateSystem();
		Parser::loadCountries("world.svg", coordinateSystem, worldFile);
		this->painter = new Painter(worldFile);
		// this->coordinateSystem->printCountryData();
		// this->coordinateSystem->printSquareData();
	}

	//void setStrategy(string pStrategy);
	void setColorAmount(int pColorAmount);
	void rotatePallete();
	vector<Country *> prepareToPaint();//Esto se corre antes del metodo paint que usa el strategy
	void paint();
	void start();
};