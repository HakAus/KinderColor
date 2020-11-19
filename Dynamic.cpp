#include "Dynamic.h"

void Dynamic::execute(vector<Country*> pCountries, vector<string> pColorPallete)
{
	cout << "Trying to execute Dynamic" << endl;
	int palleteSize = pColorPallete.size();
	cout << pColorPallete.size();
	for (int index = 0; index < palleteSize; index++)
	{
		cout << "Creating buckets" << pColorPallete[index] << endl;
		buckets.push_back(new ColorBucket(pColorPallete[index]));
	}
	for (const auto& country : pCountries) {//Cada k paises se puede meter la marca para pintar el mapa svg(Lazyness)
		cout << "Finding buckets" << endl;
		findBucket(country);
	}
	for (const auto& bucket : buckets) {//Cada k paises se puede meter la marca para pintar el mapa svg(Lazyness)
		bucket->showBucket();
	}
	cout << "Sin pintar: " << pCountries.size() - paintedCountries();
}

void Dynamic::findBucket(Country* pCountry)
{
	ColorBucket* optimalBucket = findOptimalBucket();
	optimalBucket->tryBucket(pCountry);
	for (const auto& bucket : buckets) {
		if (bucket->tryBucket(pCountry))
			break;
	}
}

int Dynamic::paintedCountries()
{
	int sum = 0;
	for (const auto& bucket : buckets) {
		sum += bucket->getBucketSize();
	}
	return sum;
}

ColorBucket* Dynamic::findOptimalBucket()
{
	ColorBucket* lowestBucket = NULL;
	for (const auto& bucket : buckets)
	{
		if (lowestBucket == NULL || lowestBucket->getBucketWeight() <= bucket->getBucketWeight())
		{
			lowestBucket = bucket;
		}
	}
	return lowestBucket;
}



