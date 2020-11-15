#pragma once
#include "Includes.h"
#include <unordered_map>
#include "Country.h"

class ColorBucket {

	string bucketColor;
	unordered_map<string, Country*> bucketRestrictions;
	vector<Country *> bucketCountries;

public:
	ColorBucket(std:: string pColor);
	void showBucket();
	bool tryBucket(Country* pCountry);
	void addToBucketRestrictions(unordered_map<string, Country*> pRestrictions);
	void addToBucketCountries(Country * pCountry);
	int getBucketSize();
};