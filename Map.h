#pragma once

#include "Includes.h"
#include "Parser.h"
#include "Strategy.h"
#include "Painter.h"
#include "Observer.h"

class Map : Observer{
private:
	XMLDocument* worldFile;
	CoordinateSystem* coordinateSystem;
	int colorAmount;
	vector<string> pallete = { "#FA9278","#F22222","#000000","#237d7a"};
	Strategy * currentStrategy;
	int alreadyPainted;
public:
	Map();
	Map(string pStrategy, int pColorAmount);

	void setStrategy(string pStrategy);
	void setColorAmount(int pColorAmount);
	void rotatePallete();
	vector<Country *> prepareToPaint();//Esto se corre antes del metodo paint que usa el strategy
	void paint();
	void update();
};

//Poner al painter como un observable
//Lo necesita el Strategy para que con el conteo que lleva