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
	vector<string> restrictedColors;
	set<Country*> neighbors;
	int conections;//Se puede agregar un campo conexiones que se modifica mientras avanza el algoritmo lo que hace que se reoordenen los ponderados
	
public:
	Country(string pId, string pName);
	void addNeighbor(Country* pNeighbor);
	void addNeighborAux(Country* pNeighbor);
	void setColor(string pColor);
	int getConections();
	void setConections();
	void setConections(int pConections);
	vector<string> getRestrictedColors();
	void addColorRestriction(string pColorCode);
	string getColor();
	string getId();
	string getName();
	bool isPainted();
	set<Country*> getNeighbors();
};
