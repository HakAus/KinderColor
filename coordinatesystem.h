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
	//unordered_map<std::tuple<int,int>,std::set<const char*>> squareHash;
	std::vector<Country*> countries;

public:
	CoordinateSystem();
	void setCountries(std::vector<Country* > pCountries);
	void setCountryInSquares(const char* pSvgPath,const char * pId);
	void addToSquareHash(std::tuple<int, int>, const char* pId);
	std::tuple<float, float> getTupleFloatValue(char* pToken);
	std::tuple<float, float> tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum);
};