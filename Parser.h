#pragma once
#include "Includes.h"
#include "coordinatesystem.h"

class Parser
{
public:
	Parser();

	static void loadCountries(const char* pFileName,CoordinateSystem * pCoordinateSystem);
	static char * copyChar(const char * pChar);
	static char * splitChar(char* pChar, char pDelimiter, char* pContext);
};

