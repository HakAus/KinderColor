#include <unordered_map>
#include "Country.h"
#include "Includes.h"

using namespace std; 

class CoordinateSystem
{
private:

	float interval;
	float width;
	float height;
	unordered_map<string,set<string>> squareHash;
	unordered_map<string, Country*> countryHash;
	vector<Country*> countries;

public:
	CoordinateSystem();
	void setCountries(std::vector<Country* > pCountries);
	void setCountryInSquares(const char* pSvgPath, Country * pCountry, int pInterval);
	void addToSquareHash(std::string, Country * pCountry);
	std::tuple<float, float> getTupleFloatValue(const char * pBegin, const char* pComma, const char* pEnd);
	std::tuple<float, float> tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum);
	std::string getSquare(std::tuple<float, float> pCurrentPoint, int pInterval);
	void printSquareData();
	void printCountryData();
	void printCountryColor();
	void addCountry(Country * pCountry);
};