#pragma once
#include "Includes.h"

class Utilities {

public:
	Utilities();
	static std::vector<std::string> split(const char* pChar, char pDelimiter);
	static std::vector<std::string> split2(const char* pChar);
};