#pragma once
#include "Includes.h"
#include "WorldData.h"

class Parser
{
public:
	Parser();
	WorldData* loadCountries(const char* pFileName);
};

