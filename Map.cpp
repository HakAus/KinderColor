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

set<Country> Map::prepareToPaint()//Decidir si el vector sera un atributo de mapa o solo se pasara de un metodo al otro
{
	return coordinateSystem->prepareToPaint();
	for (paises:HashPaises) {
		asignarPeso();
		meterAlVector();
	}
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