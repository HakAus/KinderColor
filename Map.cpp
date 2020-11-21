#include "Map.h"
#include "Divide.h"
#include "Dynamic.h"
#include "BackTracking.h"
Map::Map(bool* pt)//Ejemplo de como se inicia ya con el thread
{
	worldFile = new XMLDocument();
	coordinateSystem = new CoordinateSystem();
	Parser::loadCountries("world.svg", coordinateSystem, worldFile);
	coordinateSystem->printCountryData();
	coordinateSystem->prepareToPaint();
	colorAmount = 3;
	alreadyPainted = 0;
	memoryPainter = new MemoryPainter();
	currentStrategy = new Dynamic(this,memoryPainter);
	painter = new Painter(currentStrategy->getFileName(), coordinateSystem, memoryPainter,pt);
}

Map::Map(string pStrategy, int pColorAmount)
{
	setColorAmount(pColorAmount);
	setStrategy(pStrategy);
	worldFile = new XMLDocument();
	coordinateSystem = new CoordinateSystem();
	Parser::loadCountries("world.svg", coordinateSystem, worldFile);
	coordinateSystem->prepareToPaint();
	alreadyPainted = 0;
}

void Map::setStrategy(string pStrategy)
{
	//currentStrategy = new Divide();
}

void Map::setColorAmount(int pColorAmount)
{
	this->colorAmount = pColorAmount;
}

void Map::rotatePallete()
{
	string last = pallete[2];
	for (int index = 0; index < 3; index++)
	{
		if (index != pallete.size() - 1)
			pallete[index] = pallete[index + 1];
		else
			pallete[0] = last;
	}
}

vector<Country *> Map::prepareToPaint()//Decidir si el vector sera un atributo de mapa o solo se pasara de un metodo al otro
{
	return coordinateSystem->prepareToPaint();
}

void Map::paint()
{
	painter->startThread();
	currentStrategy->execute(prepareToPaint(),pallete);
}


