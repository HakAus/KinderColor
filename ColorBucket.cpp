#include "ColorBucket.h"

ColorBucket::ColorBucket(std::string pColor)
{
	cout << pColor;
	bucketColor = pColor;
}

void ColorBucket::showBucket()
{
	cout << bucketColor << ":" << endl;
	cout << "{";
	for (const auto& country : bucketCountries) {//Cada k paises se puede meter la marca para pintar el mapa svg(Lazyness)
		cout<<country->getId()<<",";
	}
	cout << "}" << endl;
}

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

int ColorBucket::getBucketSize()
{
	return bucketCountries.size();
}
