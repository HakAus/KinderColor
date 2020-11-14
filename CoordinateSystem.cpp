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

bool connectionsComparator(Country* pFirstCountry, Country* pSecondCountry) {
    return pFirstCountry->getConections() < pSecondCountry->getConections();
}//No estoy seguro de donde deberia ir esta funcion

bool squareComparator(string pFirstSquare, string pSecondSquare)
{
    // La implementacion de esto se puede mejorar 
    float x1 = 0.0;
    float y1 = 0.0;
    float x2 = 0.0;
    float y2 = 0.0;
    string buffer;
    for (char character : pFirstSquare)
    {
        if (character == ','){
            // cout << buffer << endl;
            x1 = stof(buffer);
            buffer = "";
        }
        if (isdigit(character) || character == '-' || character == '-'){
            buffer += character;
        }
    }
    // cout << buffer << endl;
    y1 = stof(buffer);
    buffer = "";

    for (char character : pSecondSquare)
    {
        if (character == ','){
            // cout << buffer << endl;
            x2 = stof(buffer);
            buffer = "";
        }
        if (isdigit(character) || character == '-' || character == '-'){
            buffer += character;
        }
    }
    // cout << buffer << endl;
    y2 = stof(buffer);

    if (x1 < x2)
        return true;
    else if (x1 == x2)
        return y1 <= y2;
    else
        return false;
}
void CoordinateSystem::addCountry(Country * pCountry)
{
    countryHash[pCountry->getId()] = pCountry;
}

vector<string> CoordinateSystem::prepareToPaint()//Se iba a calcular un ponderado, pero se usara nada mas su numero de conexiones
{//Empiezo a creer que no es necesario un hash para indexar pues se ira pintando secuencialmente,Basta con el hash dentro de los paises,Se puede transformar el hash de sistema de coordenadas a un vector para evitar este paso
    vector<string> countries;//Ordenado por numero de conexiones
    for (auto pair : squareHash)
    {
        countries.push_back(pair.first);
    }
    sort(countries.begin(), countries.end(), &squareComparator);

    cout << "Coordenadas ordenadas" << endl;
    for (auto str : countries)
    {
        cout << str << endl;
    }
    return countries;
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
    int squareCount = 0;
    for (auto pair : squareHash)
    {
        squareCount++;
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
    cout << "Total squares: " << squareCount << endl;
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

void CoordinateSystem::printCountryColor()
{
    for (auto pair : countryHash)
    {
        pair.second->getColor();
    }
}

