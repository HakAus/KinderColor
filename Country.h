#pragma once
#include "Includes.h"

using namespace std;

class Country
{

private:
	string id;
	string name;
	bool painted;
	string color;
	set<Country*> neighborsSet;
	unordered_map<string, Country*> neighborsHash;
	int conections;
	vector<string> availableColors;
	string btColor;
	
public:
	Country(string pId, string pName);
	void addNeighbor(Country* pNeighbor);
	void addNeighborAux(Country* pNeighbor);
	void setColor(string pColor);
	int getConections();
	void setConections();
	void setConections(int pConections);
	string getColor();
	string getId();
	string getName();
	bool isPainted();
	set<Country*> getNeighborsSet();
	unordered_map<string, Country*> getNeighborsHash();
	bool isColored();
	void unPaint();
	void setAvailableColors(vector<string> pColors);
	bool isAvailableColor();
	void removeAvailableColor(string pColor);
	bool canUseColor(string pColor);
	void setBtColor(string pColor);
	string getBtColor();
	bool isBtColored();
};
