#include "Map.h"

void Map::setColorAmount(int pColorAmount)
{
	this->colorAmount = pColorAmount;
}

void Map::rotatePallete()
{
	string last = pallete[3];
	for (int index = 0; index < 3; index++)
	{
		if (index != pallete->size() - 1)
			pallete[index] = pallete[index + 1];
		else
			pallete[0] = last;
	}
}

vector<tuple<string,set<Country*>>> Map::prepareToPaint()//Decidir si el vector sera un atributo de mapa o solo se pasara de un metodo al otro
{
	return coordinateSystem->prepareToPaint();
	// for (auto paises : HashPaises) {
	// 	asignarPeso();
	// 	meterAlVector();
	// }
}

void Map::start() // TODO: Validacion de input
{
	string option;
	while (option != "s")
	{
		cout << "\nIngrese el numero de colores: ";
		cin >> option;
		if (option == "s")
			break;
		int colorAmount = stoi(option);
		if (colorAmount >= 3 && colorAmount <= 11)
		{
			string strategy;
			while (strategy != "s")
			{
				cout << "\nSeleccione la estrategia de pintado" << endl;
				cout << "(1) Backtracking" << endl;
				cout << "(2) Divide y venceras" << endl;
				cout << "(3) Programacion dinamica" << endl;
				cin >> strategy;
				
				cout << "WORK IN PROGRESS" << endl;
				strategy = "s";
			}
			option = "s";	// borrar luego
		}
		else 
			cout << "Debe ingresar una cantidad de 3 a 11" << endl;
	}
	cout << "Adios!" << endl;
}

void Map::paint()
{
	//currentStrategy.paint();
}

//Se crea un vector de paises
//Se pintaran los paises con mas ponderado
//No se pueden colorear con el mismo color paises vecinos
//Para divide y venceras se dividira el mapa por sectores de color y se haran despintes y rotaciones
//Para el prog dinamica se hara lo mismo pero en cada despinte se recalculara el ponderado por numero de conexiones disponibles
//Para el backtracking simplemente se pintara en orden y se haran diferentes conmbinaciones de seleccion del primero pais para encontrar el mejor resultado