#include "Divide.h"

void Divide::execute (vector<Country*> pCountries, int pColorAmount)
{
	divide(pCountries, pCountries.begin(), pCountries.end(), pColorAmount);
}

void Divide::divide(vector<Country*> pCountries, countryItr pStart, countryItr pEnd, int pColorAmount)
{

	//211 / 3 = 70
	int blockSize = distance(pStart,pEnd) / pColorAmount;
	blockSize += distance(pStart,pEnd) % pColorAmount;

	countryItr countryIterator;
	countryIterator = pCountries.begin();

	int blockCount = 0;

	if (blockSize <= pColorAmount)
		conquer(pCountries, pStart, pEnd, pColorAmount);
		return;
	while (blockCount < pColorAmount)
	{
		int distanceToEnd = distance(countryIterator, pCountries.end());
		cout << "Distance to end: " << distanceToEnd << endl;

		countryItr begin = countryIterator;
		if (distanceToEnd >= blockSize)
			advance(countryIterator,blockSize);
		else
			advance(countryIterator,distanceToEnd);
		sectionStack.push(make_pair(begin, countryIterator));
		divide(pCountries, begin, countryIterator, pColorAmount);

		blockCount++;
	}
	/* PRINT
	for (const auto& section : sections)
	{
		countryItr begin = section.first;
		countryItr end = section.second;
		countryItr step = begin;
		cout << "[";
		for (; step != end; step++)
		{
			cout << (*step)->getId() << " ";
		}
		// cout << (*step)->getId();
		cout << "]" << distance(begin,end) << endl;
	}*/

}

void Divide::conquer(vector<Country*> pCountries, countryItr pStart, countryItr pEnd, int pColorAmount)
{
	for (countryItr step = pStart; step != pEnd; step++)
	{
		tryColor((*pStart), pColorAmount);
	}
}

void Divide::tryColor(Country* pCountry, int pColorAmount)
{
	for (int colorIndex = 0; colorIndex < pColorAmount; colorIndex++)
	{
		vector<string>::iterator first = pCountry->getRestrictedColors().begin();
		vector<string>::iterator last = pCountry->getRestrictedColors().end();
		if (find(first,last, pallete[colorIndex]) == last)
		{
			unordered_map<string, Country*> neighbors = pCountry->getNeighbors();
			for (auto neighbor : neighbors)
			{
				neighbor.second->addColorRestriction(pallete[colorIndex]);
			}
			break;
		}
	}
}

vector<Country*> Divide::merge(vector<Country*> pCountries1, vector<Country*> pCountries2)
{
	cout << "Ready for merge" << endl;
	for (const auto& country : pCountries2)
		pCountries1.push_back(country);
	return pCountries1;
}
// Divide y venceras
// Llegar a divisiones de k paises donde en cada uno voy agregando un color
// avisando a los paises vecinos de la nueva restriccion
// luego en el proceso de combinacion se identifican los paises colindantes y se 
// ve si hay conflicto antes de unirlos o si hay que repintar paises

// Programacion dinamica
// Es basicamente la misma idea de ir avisando a los paises vecinos
// del pais actual de la nueva restriccion de color pero guardando
// cada restriccion en un hash donde la llave es el pais y el contenido
// una lista de los colores que tiene restringidos.
