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
	cout << "End";
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
				if (currentCountry->isAvailableColor() && !currentCountry->isColored()) {
					tryToPaint(currentCountry, color);
					if (currentCountry->isColored())
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
	if (pCountry->canUseColor(color)) {
		bool paint = true;
		for (auto pair : pCountry->getNeighborsHash()) {
			if (pair.second->getColor() == color) {
				paint = false;
				break;
			}
		}
		if (paint)
			memoryPainter->push_back(pair<string, Country*>(color, pCountry));
		else
			pCountry->removeAvailableColor(color);
	}
}
//No hay una buena distribucion de colores
//El algoritmo dura demasiado o falla con 4 colores, seguramente al aumento de pruebas del ciclo
//Puede que se necesite una poda mas significativa