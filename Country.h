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
	int conections;//Se puede agregar un campo conexiones que se modifica mientras avanza el algoritmo lo que hace que se reoordenen los ponderados
	
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
	unordered_map<string, Country*> getNeighbors();
};
