#pragma once
#include <vector>
#include <tuple>
#include <cstring>
#include <cctype>
#include <string>
#include <iostream>

class Country
{	

private:
	
	const char* id;
	const char* name;
	std::vector<std::tuple<float, float>> mapPoints;

public:
	Country(const char* pId, const char* pName);

	void setMapPoints(const char* pSvgPath);
	std::vector<std::tuple<float, float>> getMapPoints();
	const char* getId();

	std::tuple<float, float> getTupleFloatValue(char* pToken);//Todo: No se si estos metodos deberian ir en esta clase, podria ser mejor metodos estaticos en una clase de herramaientas
	std::tuple<float, float> tuppleAddition(std::tuple<float, float> pFirstSum, std::tuple<float, float> pSecondSum);

	void showMapPoints();
};
