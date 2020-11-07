#include "Country.h"

Country::Country(const char* pId, const char* pName) 
{
	this->id = pId;
	this->name = pName;
}

void Country::setMapPoints(const char* pSvgPath)
{
	std::tuple<float, float> currentPoint;
	char* path = _strdup(pSvgPath);
	char* nextToken = NULL;
	const char* delimiter = " ";
	char* token = strtok_s(path,delimiter,&nextToken);
	int counter = 0;//Se puede cambiar por algo mas eficiente
	while (token) {//TODO:Revisar el orden de los ifs
		if (counter == 1)
		{
			currentPoint = getTupleFloatValue(token);	//Toma el punto despues de m y lo inserta en la tupla
			this->mapPoints.push_back(currentPoint);
		}
		else {
			if (*token != 'z' && *token != 'm') {
				this->mapPoints.push_back(tuppleAddition(currentPoint, getTupleFloatValue(token)));	//Guarda el valor de la tupla del token + el valor actual
			}
		}
		token = strtok_s(NULL," ", &nextToken);
		counter++;
	}
}

std::tuple<float, float> Country::getTupleFloatValue(char* pToken) {
	char* nextToken = NULL;
	char* token = strtok_s(pToken, ",", &nextToken);
	float firstValue = atof(token);
	float secondValue = atof(nextToken);
	return std::tuple<float, float>(firstValue, secondValue);
}

std::tuple<float, float> Country::tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum) {
	return std::tuple<float, float>(std::get<0>(pFirstSum) + std::get<0>(pSecondSum), std::get<1>(pFirstSum) + std::get<1>(pSecondSum));
}

void Country::showMapPoints()
{
	std::cout << name << " Points: " << std::endl;
	for (int i = 0; i < mapPoints.size();i++) {
		std::tuple<float, float> currentTuple = mapPoints[i];
		std::cout << "Point: (" << std::get<0>(currentTuple) << "," << std::get<1>(currentTuple) << ")" << std::endl;
	}
}
