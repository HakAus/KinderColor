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
	//Si encuentra una m el siguiente token es el current point las demas, sera las sumas al current point, ignora las z
	while (token) {
		if (*token == 'm')
			std::cout << "true";
		token = strtok_s(NULL," ", &nextToken);
	}
}
