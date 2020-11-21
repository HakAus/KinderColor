#include "Dynamic.h"

Dynamic::Dynamic(Observer* pObserver)
{
	this->fileName = "WorldDynamic.svg";
	this->observer = pObserver;
}

void Dynamic::execute(vector<Country*> pCountries, vector<string> pColorPallete)
{
	totalCountries = pCountries.size();
	cout << "Trying to execute" << endl;
	int palleteSize = pColorPallete.size();
	cout << pColorPallete.size();
	vector<Country*> workingCountries = pCountries;
	for (int index = 0; index < palleteSize; index++)
	{
		cout << "Creating buckets" << pColorPallete[index] << endl;
		buckets.push_back(new ColorBucket(pColorPallete[index]));
	}
	for (const auto& bucket : buckets)
	{
		for (const auto& country : workingCountries)
		{
			if (buckets[currentBucket]->tryBucket(country))
			{
				pCountries.erase(std::remove(pCountries.begin(), pCountries.end(), country));
				nextColor();
				paintedCountries++;
			}
			else if (bucket->tryBucket(country))
			{
				pCountries.erase(std::remove(pCountries.begin(), pCountries.end(), country));
				paintedCountries++;
			}
		}
		workingCountries = pCountries;
	}
	notify();
	cout << "Sin pintar: " <<  unpaintedCountries(pCountries.size());
}

int Dynamic::unpaintedCountries(int pVectorSize)
{
	return totalCountries - paintedCountries;
}

void Dynamic::nextColor()
{
	if (currentBucket != buckets.size() - 1)
		currentBucket++;
	else
		currentBucket = 0;
}
