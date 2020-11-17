#include "Divide.h"

void Divide::execute(vector<Country*> pCountries, vector<string> pColorPallete)//Se puede mejorar crearndo buckets
{
	cout << "Trying to execute" << endl;
	int palleteSize = pColorPallete.size();
	cout << pColorPallete.size();
	//Si se quisiera trabajar con el mapa los buckets pueden tener los rangos y lo que cambiaria es el metodo findBucket ahora buscando por su putno de origen en x
	for (int index = 0; index < palleteSize; index++)
	{//Colores por definir en Painter o en Map de acceso global constantes y se pueden ordenar diferente para cada corrida del algoritmo 
		cout << "Creating buckets"<< pColorPallete[index]<<endl;
		buckets.push_back(new ColorBucket(pColorPallete[index]));
	}
	//Asignar un color a los paises(Agotando las opciones)
		for (const auto& country : pCountries) {//Cada k paises se puede meter la marca para pintar el mapa svg(Lazyness)
			cout << "Finding buckets" << endl;
			findBucket(country);
		}
	for (const auto& bucket : buckets) {//Cada k paises se puede meter la marca para pintar el mapa svg(Lazyness)
		bucket->showBucket();
	}
	cout << "Sin pintar: " << pCountries.size() - paintedCountries();
}

void Divide::findBucket(Country* pCountry)//Se puede cambiar a pasar todos los posibles por el primer bucket y recorrer 3 veces el vector de paises
{//TODO:Discutir esto
	if (buckets[currentBucket]->tryBucket(pCountry))//Se agrega este segmento de codigo para dar oportunidad a todos los colores de aparecer en el mapa
		nextColor();//Esta agregado en el codigo hace que el argumento sea menos eficiente para pocos colores puesto que prioriza el variar colores que la cantidad de pintados
}

int Divide::paintedCountries()
{
	int sum = 0;
	for (const auto& bucket : buckets) {
		sum += bucket->getBucketSize();
	}
	return sum;
}

void Divide::nextColor()
{
	if (currentBucket != buckets.size() - 1)
		currentBucket++;
	else
		currentBucket = 0;
}
