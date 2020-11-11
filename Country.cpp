#include "Country.h"

Country::Country(const char* pId, const char* pName) 
{
	this->id = pId;
	this->name = pName;
}

void Country::setMapPoints(const char* pSvgPath)
{
	std::tuple<float, float> currentPoint;
	char* path = strdup(pSvgPath);
	rsize_t strmax = sizeof path;
	const char* delimiter = " ";
	char* nextToken;
	char* token = strtok(path,delimiter);
	currentPoint = {0.0, 0.0};
	while (token) {
		if (!isalpha(*token)){
			currentPoint = tuppleAddition(currentPoint, getTupleFloatValue(token));
			int column = (int) std::get<0>(point)/interval;
			int row = (int) std::get<1>(point)/interval;
			std::string coordinates = "(" +std::to_string(column) + "," + std::to_string(row) + ")";
			std::pair<const char*,const char*> countryInSquare (coordinates.c_str(),country->getId());
			std::cout << countryInSquare.first << ", " << countryInSquare.second << std::endl;
			SquareHash.insert(countryInSquare);
			//this->mapPoints.push_back(currentPoint);	//Guarda el valor de la tupla del token + el valor actual
		}
		token = strtok(NULL,delimiter);
	}
}

std::tuple<float, float> Country::getTupleFloatValue(char* pToken) {
	std::string token = pToken;
	size_t comma = token.find_first_of(",");	// Distancia desde el inicio hasta la primera coma.
	std::string firstString = token.substr(0, comma);
	std::string secondString = token.substr(comma+1);	// Se pone mas uno para saltar la coma.
	float firstValue = stof(firstString);
	float secondValue = stof(secondString);
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
		std::cout << "Point: (" << std::get<0>(currentTuple) << "," << std::get<1>(currentTuple) << ") ";
	}
	std::cout << std::endl;
}

std::vector<std::tuple<float, float>> Country::getMapPoints()
{
	return this->mapPoints;
}
const char* Country::getId()
{
	return this->id;
}
