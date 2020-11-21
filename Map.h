#pragma once

#include "Includes.h"
#include "Painter.h"
#include "Parser.h"
#include "Strategy.h"
#include "Observer.h"

class Map : Observer {

private:
	XMLDocument* worldFile;
	CoordinateSystem* coordinateSystem;
	vector<string> pallete = {"FF4533","47FF33","F6FF33","#33FFE4","#0851CF",
						   "#D100E0","#FFBB00","#097D2F","#75493B","#4300C9",
						   "#E394CC"};
	int colorAmount;
	Strategy * currentStrategy;
	MemoryPainter* memoryPainter;
	Painter* painter;
	int alreadyPainted;

public:
	Map(bool* pt);
	Map(string pStrategy, int pColorAmount);

	void setStrategy(string pStrategy);
	void rotatePallete();
	vector<Country *> prepareToPaint();//Esto se corre antes del metodo paint que usa el strategy
	void paint();
};

//Poner al painter como un observable
//Lo necesita el Strategy para que con el conteo que lleva
