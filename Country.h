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

public:
	Country(const char* pId, const char* pName);
};
