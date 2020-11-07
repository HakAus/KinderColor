#pragma once
#include "Includes.h"

class Country
{
	
	const char* id;
	const char* name;
	std::vector<std::tuple<float, float>> mapPoints;

public:
	Country(const char* pId, const char* pName);

	void setMapPoints(const char* pSvgPath);

	std::tuple<float, float> getTupleFloatValue(char* pToken);//Todo: No se si estos metodos deberian ir en esta clase, podria ser mejor metodos estaticos en una clase de herramaientas
	std::tuple<float, float> tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum);

	void showMapPoints();
};
