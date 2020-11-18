//1.Se guarda en un bucket eso hace que las conexionesd el pais decrementen en 1 sus conexiones.
//Se reordena el vector y se prosigue con el algoritmo
//2.(Se trabajara esto) El algoritmo comprobara cual es el espacio mas apto para guardarse(El bucket con menos conexiones)
#pragma once
#include "Includes.h"
#include "Strategy.h"
#include "ColorBucket.h"

class Dynamic :public Strategy {
	vector<ColorBucket*> buckets;
public:
	void execute(vector<Country*>pCountries, vector<string> pColorPallete);
	void findBucket(Country* pCountry);
	int paintedCountries();
	ColorBucket* findOptimalBucket();
};