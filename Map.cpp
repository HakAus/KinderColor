#include "Map.h"
#include "Divide.h"
#include "Dynamic.h"
#include "BackTracking.h"

Map::Map()
{
	worldFile = new XMLDocument();
	coordinateSystem = new CoordinateSystem();
	Parser::loadCountries("world.svg", coordinateSystem, worldFile);
	coordinateSystem->printCountryData();
	coordinateSystem->prepareToPaint();
	colorAmount = 3;
	alreadyPainted = 0;
	currentStrategy = new BackTracking();
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
	currentStrategy->execute(prepareToPaint(),pallete);
	coordinateSystem->metodoFeoPaint();
}

//Se crea un vector de paises(X)
//Se pintaran los paises con mas ponderado(X)
//No se pueden colorear con el mismo color paises vecinos()
//Para divide y venceras se dividira el mapa por sectores de color y se haran despintes y rotaciones()
	//{Mi N serian el numero de colores en el ques e dividira el mapa}
//Para el prog dinamica se hara lo mismo pero en cada despinte se recalculara el ponderado por numero de conexiones disponibles
//Para el backtracking simplemente se pintara en orden y se haran diferentes conmbinaciones de seleccion del primero pais para encontrar el mejor resultado