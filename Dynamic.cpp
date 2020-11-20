#include "Dynamic.h"

Dynamic::Dynamic(Observer* pObserver)
{
	this->fileName = "WorldDynamic.svg";
	this->observer = pObserver;
}

void Dynamic::execute(vector<Country*> pCountries, vector<string> pColorPallete)
{
	cout << "Trying to execute" << endl;
	int palleteSize = pColorPallete.size();
	cout << pColorPallete.size();
	for (int index = 0; index < palleteSize; index++)
	{
		cout << "Creating buckets" << pColorPallete[index] << endl;
		buckets.push_back(new ColorBucket(pColorPallete[index]));
	}
	for (const auto& country : pCountries) 
	{
		findBucket(country);
	}
	for (const auto& bucket : buckets) 
	{
		bucket->showBucket();
	}
	notify();
	cout << "Sin pintar: " <<  unpaintedCountries(pCountries.size());
}

void Dynamic::findBucket(Country* pCountry)
{
	if (buckets[currentBucket]->tryBucket(pCountry))//Se agrega este segmento de codigo para dar oportunidad a todos los colores de aparecer en el mapa
		nextColor();//Esta agregado en el codigo hace que el argumento sea menos eficiente para pocos colores puesto que prioriza el variar colores que la cantidad de pintados
	else {
		for (const auto& bucket : buckets) 
		{
			if (bucket->tryBucket(pCountry))
			{
				if (paintedCountries % 10 == 0)
					notify();
				paintedCountries++;
				break;
			}
		}
	}
}

int Dynamic::unpaintedCountries(int pVectorSize)
{
	return pVectorSize - paintedCountries;
}

void Dynamic::nextColor()
{
	if (currentBucket != buckets.size() - 1)
		currentBucket++;
	else
		currentBucket = 0;
}
