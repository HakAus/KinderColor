#pragma once

#include "Includes.h"
#include "Parser.h"
#include "Painter.h"

class Map {

private:
	XMLDocument* worldFile;
	CoordinateSystem* coordinateSystem;
	int colorAmount;
	string pallete[3] = { "FF4533","47FF33","F6FF33" };
	Painter* painter;
	//Strategy currentStrategy;
public:
	Map() {
		this->worldFile = new XMLDocument();
		this->coordinateSystem = new CoordinateSystem();
		Parser::loadCountries("world.svg", coordinateSystem, worldFile);
		this->painter = new Painter(worldFile);
		prepareToPaint();
		// this->coordinateSystem->printCountryData();
		// this->coordinateSystem->printSquareData();
	}

	//void setStrategy(string pStrategy);
	void setColorAmount(int pColorAmount);
	void rotatePallete();
	vector<tuple<string,set<Country*>>> prepareToPaint();//Esto se corre antes del metodo paint que usa el strategy
	void paint();
	void start();
};