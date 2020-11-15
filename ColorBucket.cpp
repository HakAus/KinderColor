#include "ColorBucket.h"

bool ColorBucket::tryBucket(Country* pCountry)
{
	if (bucketRestrictions.find(pCountry->getId()) == bucketRestrictions.end()) {
		addToBucketCountries(pCountry); //La llave no existe ,entra al bucket
		return true;
	}
	return false;//La llave existe, no puede entrar
}

void ColorBucket::addToBucketRestrictions(unordered_map<string, Country*> pRestrictions)
{
	bucketRestrictions.insert(pRestrictions.begin(), pRestrictions.end());
}

void ColorBucket::addToBucketCountries(Country* pCountry)
{
	bucketCountries.push_back(pCountry);
	pCountry->setColor(bucketColor);
	addToBucketRestrictions(pCountry->getNeighbors());
}
