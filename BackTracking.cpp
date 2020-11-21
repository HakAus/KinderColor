#include "BackTracking.h"

BackTracking::BackTracking(Observer* pObserver, MemoryPainter* pMemoryPainter)
{
	this->memoryPainter = pMemoryPainter;
	this->fileName = "WorldBackTracking.svg";
	this->observer = pObserver;
}

void BackTracking::execute(vector<Country*> pCountries, vector<string> pColorPallete)
{
	colorPallete = pColorPallete;
	for (const auto& country : pCountries) {//Esto lo puede hacer cuando se crean los paises
		country->setAvailableColors(colorPallete);
	}
	std::vector<Country*>::iterator firstVectorElement = pCountries.begin();
	bruteForce(pCountries, firstVectorElement);
	memoryPainter->finish();
	notify();
}

void BackTracking::bruteForce(vector<Country*> pVector, std::vector<Country*>::iterator pFirstCountry) {
	std::vector<Country*>::iterator currentIterator = pVector.begin();
	if (currentIterator != pVector.end())
	{
		if (!endOfAlgorithm) {
			Country* currentCountry = *currentIterator;
			for (const auto& color : colorPallete)
			{
				if (currentCountry->isAvailableColor() && !currentCountry->isBtColored()) {
					tryToPaint(currentCountry, color);
					if (currentCountry->isBtColored())
					{
						bruteForce(vector<Country*>(next(currentIterator), pVector.end()), pFirstCountry);
					}
				}
				else
					bruteForce(vector<Country*>(next(currentIterator), pVector.end()), pFirstCountry);
			}
		}
	}
	else
		endOfAlgorithm = true;
}

void BackTracking::tryToPaint(Country* pCountry, string color)//Podia ser un metodo que tuviera el country, pero solo va a ser usado aca
{
	if (pCountry->canUseColor(colorPallete[currentColor]))
	{
		bool paint = true;
		for (auto pair : pCountry->getNeighborsHash()) {
			if (pair.second->getBtColor() == colorPallete[currentColor]) {
				paint = false;
				break;
			}
		}
		if (paint) {
			pCountry->setBtColor(colorPallete[currentColor]);
			memoryPainter->push_back(pair<string, Country*>(colorPallete[currentColor], pCountry));
		}
		else
			pCountry->removeAvailableColor(colorPallete[currentColor]);
		nextColor();
	}
	else if (pCountry->canUseColor(color)) 
	{
		bool paint = true;
		for (auto pair : pCountry->getNeighborsHash()) {
			if (pair.second->getBtColor() == color) {
				paint = false;
				break;
			}
		}
		if (paint) {
			pCountry->setBtColor(color);
			memoryPainter->push_back(pair<string, Country*>(color, pCountry));
		}
		else
			pCountry->removeAvailableColor(color);
	}
}
void BackTracking::nextColor()
{
	if (currentColor != colorPallete.size() - 1)
		currentColor++;
	else
		currentColor = 0;
}
