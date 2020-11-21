#include "Divide.h"


Divide::Divide(Observer * pObserver)
{
	this->fileName = "WorldDivide&Conquer.svg";
	this->observer = pObserver;
}

void Divide::execute (vector<Country*> pCountries, vector<string> pColorPallete)
{
	srand(time(NULL));	// Para tener variedad de colores.
	prepareColors(pCountries, pColorPallete);
	divide(pCountries, pCountries.begin(), pCountries.end(), pColorPallete.size());
}

void Divide::prepareColors(vector<Country*> pCountries, vector<string> pColorPallete)
{
	/*unordered_set<string> colors;
	for (int colorIndex = 0; colorIndex < pColorAmount; colorIndex++){
		colors.insert(pColorPallete[colorIndex]);
	}*/

	for (const auto& country : pCountries) // TODO: Porbar creacion con iteradores
		countryColors[country->getId()] = unordered_set<string>(pColorPallete.begin(), pColorPallete.end());	
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
}

void Divide::conquer(vector<Country*> pCountries, int pColorAmount)
{
	for (auto country : pCountries)
	{
		if (!country->isPainted() && !countryColors[country->getId()].empty())
		{
			int pos = rand() % countryColors[country->getId()].size();
			unordered_set<string>::iterator it = countryColors[country->getId()].begin();
			advance(it,pos);
			string color = *it;
			country->setColor(color);
			countryColors[country->getId()].erase(it);
			unordered_set<string> copy(countryColors[country->getId()]);
			updateRestrictions(country->getNeighborsSet(), color);
		}
		else {
			country->setColor("#FFFFFF");
		}
	}
}

void Divide::updateRestrictions(set<Country*> pNeighbors, string pColor)
{
	for (auto country : pNeighbors){
		if (!country->isPainted()){
			countryColors[country->getId()].erase(pColor);
		}
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
