#include "CoordinateSystem.h"
#include "Utilities.h"

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
	const char* delimiter = " ";
	vector<string>tokens = Utilities::split(pSvgPath, ' ');
	int counter = 0;
	std::cout << pId << endl;
	while (counter < tokens.size()) {
		string token = tokens[counter];
		if (counter == 1)
		{
			currentPoint = getTupleFloatValue(token);
			addToSquareHash(currentPoint,pId);
		}
		else {
			if (isdigit(token.c_str()[0])) {
				addToSquareHash(tuppleAddition(currentPoint, getTupleFloatValue(token)), pId);//Aca se hace el calculo del x y y de la matriz imaginaria
			}
		}
		counter++;
	}
}

void CoordinateSystem::addToSquareHash(std::tuple<int, int>, const char * pId) {
	//Se agrega el key al hash creando un set para el valor entrante,si ya existe el key entonces mete el id al set
}

std::tuple<float, float> CoordinateSystem::getTupleFloatValue(std::string pToken) {
	std::cout << pToken<<endl;
	vector<string> tokens = Utilities::split(pToken.c_str(), ',');
	std::cout << tokens.size()<<endl;
	float firstValue = atof(tokens[0].c_str());
	float secondValue = atof(tokens[1].c_str());
	return std::tuple<float, float>(firstValue, secondValue);
}

std::tuple<float, float> CoordinateSystem::tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum) {
	return std::tuple<float, float>(std::get<0>(pFirstSum) + std::get<0>(pSecondSum), std::get<1>(pFirstSum) + std::get<1>(pSecondSum));
}