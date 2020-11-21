#include "Country.h"

Country::Country(string pId, string pName) 
{
	this->id = pId;
	this->name = pName;
	this->color = "#f2f2f2";//Se puede hacer un hash de colores para manejarlos por key (Tipo diccionario)
	this->btColor = "#f2f2f2";
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

bool Country::isColored()
{
	return color != "#f2f2f2";
}

void Country::unPaint()
{
	setColor("#f2f2f2");
}

void Country::setAvailableColors(vector<string> pColors)
{
	availableColors = pColors;
}

bool Country::isAvailableColor()
{
	return !availableColors.empty();
}

void Country::removeAvailableColor(string color)
{
	availableColors.erase(std::remove(availableColors.begin(), availableColors.end(), color));
}

bool Country::canUseColor(string pColor)
{
	return (std::find(availableColors.begin(), availableColors.end(), pColor) != availableColors.end());
}

void Country::setBtColor(string pColor)
{
	btColor = pColor;
}

string Country::getBtColor()
{
	return btColor;
}

bool Country::isBtColored()
{
	return btColor != "#f2f2f2";
}

string Country::getId()
{
	return id;
}
