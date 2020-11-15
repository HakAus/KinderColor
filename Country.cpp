#include "Country.h"

Country::Country(string pId, string pName) 
{
	this->id = pId;
	this->name = pName;
	this->color = "#f2f2f2";//Se puede hacer un hash de colores para manejarlos por key (Tipo diccionario)
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
