#pragma once

#include "Includes.h"
#include "Painter.h"
#include "Parser.h"
#include "Strategy.h"
#include "Observer.h"

class Map : Observer{
private:
	XMLDocument* worldFile;
	CoordinateSystem* coordinateSystem;
	int colorAmount;
	vector<string> pallete = { "#FA9278","#fcba03","#000000","#237d7a","#877548"};
	Strategy * currentStrategy;
	MemoryPainter* memoryPainter;
	Painter* painter;
	int alreadyPainted;
public:
	Map(bool* pt);
	Map(string pStrategy, int pColorAmount);

	void setStrategy(string pStrategy);
	void setColorAmount(int pColorAmount);
	void rotatePallete();
	vector<Country *> prepareToPaint();//Esto se corre antes del metodo paint que usa el strategy
	void paint();
};

//Poner al painter como un observable
//Lo necesita el Strategy para que con el conteo que lleva