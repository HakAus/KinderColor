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
<<<<<<< HEAD
	/* std::tuple<float, float> currentPoint;
	char* path = _strdup(pSvgPath);//Copia el string para que no sea const
	char* nextToken = NULL;
=======
	std::tuple<float, float> currentPoint;
>>>>>>> origin/Fernando
	const char* delimiter = " ";
	vector<string>tokens = Utilities::split(pSvgPath, ' ');
	int counter = 0;
	std::cout <<pId<<endl<< tokens.size()<<endl;
	while (counter < tokens.size()) {
		std::cout << counter;
		string token = tokens[counter];
		if (counter == 1)
		{
			currentPoint = getTupleFloatValue(token);
			addToSquareHash(currentPoint,pId);
		}
		else {
			if (token != "z" && token != "m") {
				addToSquareHash(tuppleAddition(currentPoint, getTupleFloatValue(token)), pId);//Aca se hace el calculo del x y y de la matriz imaginaria
			}
		}
		counter++;
	}
	*/
}

void CoordinateSystem::addToSquareHash(std::tuple<int, int>, const char * pId) {
	//Se agrega el key al hash creando un set para el valor entrante,si ya existe el key entonces mete el id al set
}

<<<<<<< HEAD
/*std::tuple<float, float> CoordinateSystem::getTupleFloatValue(char* pToken) {
	char* nextToken = NULL;
	char* token = strtok_s(pToken, ",", &nextToken);
	float firstValue = atof(token);
	float secondValue = atof(nextToken);
=======
std::tuple<float, float> CoordinateSystem::getTupleFloatValue(std::string pToken) {
	vector<string> tokens = Utilities::split(pToken.c_str(), ',');
	float firstValue = atof(tokens[0].c_str());
	float secondValue = atof(tokens[1].c_str());
>>>>>>> origin/Fernando
	return std::tuple<float, float>(firstValue, secondValue);
}
*/

std::tuple<float, float> CoordinateSystem::tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum) {
	return std::tuple<float, float>(std::get<0>(pFirstSum) + std::get<0>(pSecondSum), std::get<1>(pFirstSum) + std::get<1>(pSecondSum));
}