#include "BackTracking.h"

void BackTracking::execute(vector<Country*> pCountries, vector<string> pColorPallete)
{
	colorPallete = pColorPallete;
	std::vector<Country*>::iterator firstVectorElement = pCountries.begin();
	bruteForce(pCountries, NULL, firstVectorElement);
}

void BackTracking::bruteForce(vector<Country*> pVector,Country * pTriggerBackTracking, std::vector<Country*>::iterator pFirstCountry) {
	std::vector<Country*>::iterator currentIterator = pVector.begin();
	if (currentIterator != pVector.end())
	{
		Country* currentCountry = *currentIterator;
		for (const auto& color : colorPallete) 
		{
			tryToPaint(currentCountry, color);//Aca tengo un problema de recursion
			bruteForce(vector<Country*>(next(currentIterator),pVector.end()),pTriggerBackTracking,pFirstCountry);
		}
		cout << "Uno";
		if (!currentCountry->isColored()) {
			cout << "Lmao";
			pTriggerBackTracking = currentCountry;
		}
		cout << "Dos";
		if (pVector.begin() == pFirstCountry && pTriggerBackTracking != NULL) {
			cout << "Tres";
			pVector.erase(std::remove(pVector.begin(), pVector.end(), pTriggerBackTracking));
			pTriggerBackTracking = NULL;													
			bruteForce(pVector,pTriggerBackTracking,pFirstCountry);
		}
		cout << "Cuatro";
	}
}

void BackTracking::tryToPaint(Country* pCountry, string color)//Podia ser un metodo que tuviera el country, pero solo va a ser usado aca
{
	bool paint = true;
	cout << pCountry->getId()<<color<<endl;
	for (auto pair : pCountry->getNeighbors()) {
		if (pair.second->getColor() == color) {
			paint = false;
			break;
		}
	}
	if (paint)
		pCountry->setColor(color);
}
