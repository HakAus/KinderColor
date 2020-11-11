#include "CoordinateSystem.h"

CoordinateSystem::CoordinateSystem(float pInterval, WorldData * pWorldData)
{
	interval = pInterval;
	width = pWorldData->width;
	height = pWorldData->height ;
	updateSquares(pWorldData->countries);
}

void CoordinateSystem::setInterval(float pInterval)
{
	interval = pInterval;
}

void CoordinateSystem::setFrame(float pWidth, float pHeight)
{
	width = pWidth;
	height = pHeight;
}

void CoordinateSystem::updateSquares(std::vector<Country*> pCountries)
{
	for (Country* country : pCountries)
	{
		for (auto point : country->getMapPoints())
		{
			int column = (int) std::get<0>(point)/interval;
			int row = (int) std::get<1>(point)/interval;
			std::string coordinates = "(" +std::to_string(column) + "," + std::to_string(row) + ")";
			std::pair<const char*,const char*> countryInSquare (coordinates.c_str(),country->getId());
			std::cout << countryInSquare.first << ", " << countryInSquare.second << std::endl;
			SquareHash.insert(countryInSquare);
		}
	}

	std::string tmp1;
	std::string tmp2;
	for (std::pair<const char*, const char*> countryInSquare : SquareHash)
	{
		std::cout << "key: " << countryInSquare.first << ", value: " << countryInSquare.second << std::endl;
		// if (tmp1.empty()){
		// 	tmp1 = countryInSquare.first;
		// 	tmp2 = "= [";
		// }
		// else if (tmp1 == countryInSquare.first){
		// 	tmp2 += countryInSquare.second;
		// 	tmp2 += " ";
		// }

		// else {
		// 	std::cout << tmp1 << tmp2 << std::endl;
		// 	tmp1 = "";
		// 	tmp2 = "";
		// }
	}
	
}