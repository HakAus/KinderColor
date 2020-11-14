#pragma once
#include "Includes.h"
#include "CoordinateSystem.h"

class Parser
{
public:
	Parser();

	static void loadCountries(const char* pFileName,CoordinateSystem * pCoordinateSystem, XMLDocument * pWorldFile);
};

