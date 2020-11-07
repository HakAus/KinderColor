#pragma once
#include "Includes.h"
#include "Country.h"

class Parser
{
public:
	Parser();
	static std::vector<Country> loadCountries(const char* pFileName);
};

