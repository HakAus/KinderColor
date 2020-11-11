#include "CoordinateSystem.h"

CoordinateSystem::CoordinateSystem()
{
	interval = 0;
	width = 0;
	height = 0;
	
}

void CoordinateSystem::setCountries(std::vector<Country*> pCountries)
{
	//countries = pCountries;
}

//Para cada punto crear un set
void CoordinateSystem::setCountryInSquares(const char* pSvgPath, const char * pId) {
	std::tuple<float, float> currentPoint;
	char* path = _strdup(pSvgPath);//Copia el string para que no sea const
	char* nextToken = NULL;
	const char* delimiter = " ";
	char* token = strtok_s(path, delimiter, &nextToken);//Separa en tokens por espacio en blanco
	int counter = 0;
	while (token) {
		if (counter == 1)
		{
			currentPoint = getTupleFloatValue(token);
			addToSquareHash(currentPoint,pId);
		}
		else {
			if (*token != 'z' && *token != 'm') {
				addToSquareHash(tuppleAddition(currentPoint, getTupleFloatValue(token)), pId);//Aca se hace el calculo del x y y de la matriz imaginaria
			}
		}
		token = strtok_s(NULL, " ", &nextToken);
		counter++;
	}
}

void CoordinateSystem::addToSquareHash(std::tuple<int, int>, const char * pId) {
	//Se agrega el key al hash creando un set para el valor entrante,si ya existe el key entonces mete el id al set
}

std::tuple<float, float> CoordinateSystem::getTupleFloatValue(char* pToken) {
	char* nextToken = NULL;
	char* token = strtok_s(pToken, ",", &nextToken);
	float firstValue = atof(token);
	float secondValue = atof(nextToken);
	return std::tuple<float, float>(firstValue, secondValue);
}

std::tuple<float, float> CoordinateSystem::tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum) {
	return std::tuple<float, float>(std::get<0>(pFirstSum) + std::get<0>(pSecondSum), std::get<1>(pFirstSum) + std::get<1>(pSecondSum));
}