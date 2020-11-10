#include "Country.h"

Country::Country(const char* pId, const char* pName) 
{
	this->id = pId;
	this->name = pName;
}
/*void Country::showMapPoints()
{
	std::cout << name << " Points: " << std::endl;
	for (int i = 0; i < mapPoints.size();i++) {
		std::tuple<float, float> currentTuple = mapPoints[i];
		std::cout << "Point: (" << std::get<0>(currentTuple) << "," << std::get<1>(currentTuple) << ")" << std::endl;
	}
}*/
