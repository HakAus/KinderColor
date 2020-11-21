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
	alreadyPainted = 0;
	// currentStrategy = new Dynamic(this);
}

Map::Map(string pStrategy, int pColorAmount)
{
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
	string option;
	while (option != "s")
	{
		cout << "\nIngrese el numero de colores: ";
		cin >> option;
		if (option == "s")
			break;
		int colorAmount = stoi(option);
		vector<string>::iterator it = pallete.begin();
		advance(it,colorAmount);
		vector<string> userPallete(pallete.begin(), it);
		if (colorAmount >= 3 && colorAmount <= 11)
		{
			string strategy;
			cout << "\nSeleccione la estrategia de pintado" << endl;
			cout << "(1) Backtracking" << endl;
			cout << "(2) Divide y venceras" << endl;
			cout << "(3) Programacion dinamica" << endl;
			cin >> strategy;
			int chosenStrategy = stoi(strategy);

			switch (chosenStrategy) {
				case 1:{
					currentStrategy = new BackTracking(this);
					break;
				}
				case 2:{
					currentStrategy = new Divide(this);
					break;
				}
				case 3:{
					currentStrategy = new Dynamic(this);
					break;
				}
				default:{
					break;
				}
			}
			currentStrategy->execute(prepareToPaint(), userPallete);
			cout << "Finished!" << endl;
		}
		else 
			cout << "Debe ingresar una cantidad de 3 a 11" << endl;
	}
	cout << "Adios!" << endl;
}

void Map::update()
{
	coordinateSystem->paintProgress(currentStrategy->getFileName().c_str());
}

