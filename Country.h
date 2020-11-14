#pragma once
#include <vector>
#include <tuple>
#include <cstring>
#include <cctype>
#include <string>
#include <iostream>
#include <unordered_map>


using namespace std;

class Country
{
private:

	string id;
	string name;
	unordered_map<string, Country*> neighbors;
	string color;


public:
	Country(string pId, string pName);
	void addNeighbor(Country* pNeighbor);
	void addNeighborAux(Country* pNeighbor);
	void setColor(string pColor);
	string getId();
	unordered_map<string, Country*> getNeighbors();
};
