#include "Divide.h"

void Divide::execute (vector<Country*> pCountries, int pColorAmount)
{
	divide(pCountries, pCountries.begin(), pCountries.end(), pColorAmount);

	for (auto country : pCountries)
	{
		cout << country->getName() << ": " << country->getColor() << endl;
	}
	painter->paintCountries(pCountries);
}

void Divide::setPainter(Painter* pPainter)
{
	painter = pPainter;
}
void Divide::divide(vector<Country*> pCountries, countryItr pStart, countryItr pEnd, int pColorAmount)
{
	//211 / 3 = 70
	if (pCountries.size() <= pColorAmount)
	{
		conquer(pCountries, pColorAmount);
	}
	else {
		int blockSize = distance(pStart,pEnd) / pColorAmount;
		blockSize += distance(pStart,pEnd) % pColorAmount;

		countryItr countryIterator;
		countryIterator = pCountries.begin();

		int blockCount = 0;

		vector<vector<Country*>> countries;
		while (blockCount < pColorAmount)
		{
			int distanceToEnd = distance(countryIterator, pCountries.end());
			// cout << "Distance to end: " << distanceToEnd << endl;

			countryItr begin = countryIterator;
			if (distanceToEnd >= blockSize)
				advance(countryIterator,blockSize);
			else
				advance(countryIterator,distanceToEnd);
			vector<Country*> countrySection(begin,countryIterator);
			countries.push_back(countrySection);
			blockCount++;
		}
		for (auto list : countries)
		{
			divide(list, list.begin(), list.end(),pColorAmount);
		}
	}
	
	// return merge(countries);

	
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

void Divide::conquer(vector<Country*> pCountries, int pColorAmount)
{
	for (auto country : pCountries)
	{
		tryColor(country, pColorAmount);
	}
}

void Divide::tryColor(Country* pCountry, int pColorAmount)
{
	bool colorAssigned = false;
	for (int colorIndex = 0; colorIndex < pColorAmount; colorIndex++)
	{
		vector<string>::iterator first = pCountry->getRestrictedColors().begin();
		vector<string>::iterator last = pCountry->getRestrictedColors().end();
		if (find(first,last, pallete[colorIndex]) == last)
		{	
			colorAssigned = true;
			pCountry->setColor(pallete[colorIndex]);
			// Significa que el color no esta en la lista de restricciones, entonces lo
			// asigna a si mismo y lo agrega como restriccion a sus vecinos
			unordered_map<string, Country*> neighbors = pCountry->getNeighbors();
			for (auto neighbor : neighbors)
			{
				neighbor.second->addColorRestriction(pallete[colorIndex]);
			}
			break;
		}
	}
	if (!colorAssigned)
	{
		pCountry->setColor("#FFFFFF");
		// cout << pCountry->getName() << ": Color = #FFFFFF" << endl;
	}

}

vector<Country*> Divide::merge(vector<vector<Country*>> pCountrySections)
{
	vector<Country*> countriesMerged;
	for (auto list: pCountrySections)
	{
		for (auto country : list)
		{
			countriesMerged.push_back(country);
		}	
	}
		
	return countriesMerged;
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
