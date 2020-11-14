#include "Country.h"

Country::Country(string pId, string pName) 
{
	this->id = pId;
	this->name = pName;
}

void Country::addNeighbor(Country * pNeighbor)
{
	this->neighbors[pNeighbor->getId()] = pNeighbor;
	pNeighbor->addNeighborAux(this);
}

void Country::addNeighborAux(Country * pNeighbor)
{
	this->neighbors[pNeighbor->getId()] = pNeighbor;
}

void Country::setColor(string pColor)
{
	this->color = pColor;
}

string Country::getColor()
{
	return this->color;
}

unordered_map<string, Country*> Country::getNeighbors()
{
	return this->neighbors;
}

string Country::getId()
{
	return id;
}
