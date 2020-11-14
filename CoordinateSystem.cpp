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
void CoordinateSystem::setCountryInSquares(const char* pSvgPath, Country* pCountry, int pInterval) {
	std::tuple<float, float> currentPoint = {0.0,0.0};
	std::tuple<float, float> newPoint = {0.0,0.0};
	std::string square;
	bool valueFound = false;
	do
    {
        const char* begin = pSvgPath;
        const char* comma = NULL;

        while (isdigit(*pSvgPath) || *pSvgPath == '.' || *pSvgPath == '-' || *pSvgPath == ','){
        	if (*pSvgPath == ',')
        		comma = pSvgPath;
            pSvgPath++;
            valueFound = true;
        }
        if (valueFound){
        	newPoint = getTupleFloatValue(begin,comma,pSvgPath);
        	currentPoint = tuppleAddition(currentPoint, newPoint);
        	square = getSquare(currentPoint, pInterval);
			addToSquareHash(square,pCountry);
			valueFound = false;
        }

    } while (0 != *pSvgPath++);
}

void CoordinateSystem::addCountry(Country * pCountry)
{
    countryHash[pCountry->getId()] = pCountry;
}

void CoordinateSystem::addToSquareHash(std::string pSquareKey, Country* pCountry) 
{   
	squareHash[pSquareKey].insert(pCountry->getId());
    if (squareHash[pSquareKey].size() > 1)
    {
        set<string>::iterator itr;
        for (itr = squareHash[pSquareKey].begin(); itr != squareHash[pSquareKey].end(); itr++)
        {
            if (*itr != pCountry->getId())
                countryHash[*itr]->addNeighbor(pCountry); // agrega en pareja 
        }
    }
}   

std::string CoordinateSystem::getSquare(std::tuple<float, float> pCurrentPoint, int pInterval)
{
    int x = std::get<0>(pCurrentPoint)/pInterval;
    int y = std::get<1>(pCurrentPoint)/pInterval;
    std::string squareKey = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    return squareKey;
}

std::tuple<float, float> CoordinateSystem::getTupleFloatValue(const char * pBegin, const char* pComma, const char* pEnd) {
	float firstValue = atof(std::string(pBegin,pComma).c_str());
    float secondValue = atof(std::string(++pComma,pEnd).c_str());
	return std::tuple<float, float>(firstValue, secondValue);
}

std::tuple<float, float> CoordinateSystem::tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum) {
	return std::tuple<float, float>(std::get<0>(pFirstSum) + std::get<0>(pSecondSum), std::get<1>(pFirstSum) + std::get<1>(pSecondSum));
}

void CoordinateSystem::printSquareData()
{
    for (auto pair : squareHash)
    {
        if ((pair.second).size() > 1)
        {
            std::cout << pair.first << "[";
            for (auto country : pair.second)
            {
                std::cout << country << " ";
            }
            std::cout << "]" << std::endl;
        } 
    }
}


void CoordinateSystem::printCountryData()
{
    for (auto pair : countryHash)
    {
        std::cout << pair.first << " [";
        for (auto country : pair.second->getNeighbors())
        {
            std::cout << country.first << " ";
        }
        std::cout << "]" << std::endl;
    }
}
