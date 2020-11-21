#include "Country.h"

Country::Country(string pId, string pName) 
{
	this->id = pId;
	this->name = pName;
	painted = false;
}

void Country::addNeighbor(Country * pNeighbor)
{
	this->neighbors.insert(pNeighbor);
	pNeighbor->addNeighborAux(this);
}

void Country::addNeighborAux(Country * pNeighbor)
{
	this->neighbors.insert(pNeighbor);
}

void Country::setColor(string pColor)
{
	this->color = pColor;
	this->painted = true;
}

bool Country::isPainted()
{
	return this->painted;
}

int Country::getConections()
{
	return conections;
}

void Country::setConections()
{
	this->conections = this->neighbors.size();
}

void Country::setConections(int pConections)
{
	this->conections = pConections;
}

vector<string> Country::getRestrictedColors()
{
	return this->restrictedColors;
}

void Country::addColorRestriction(string pColorCode)
{
	this->restrictedColors.push_back(pColorCode);
}

string Country::getColor()
{
	return this->color;
}

set<Country*> Country::getNeighbors()
{
	return this->neighbors;
}

string Country::getName()
{
	return this->name;
}

string Country::getId()
{
	return id;
}
