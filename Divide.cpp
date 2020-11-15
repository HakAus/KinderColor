#include "Divide.h"

void Divide::execute(vector<Country*> pCountries,string pColorPallete[])//Se puede mejorar crearndo buckets
{
	int palleteSize = pColorPallete->size();
	//Si se quisiera trabajar con el mapa los buckets pueden tener los rangos y lo que cambiaria es el metodo findBucket ahora buscando por su putno de origen en x
	for (int index = 0; index < palleteSize; index++)
	{//Colores por definir en Painter o en Map de acceso global constantes y se pueden ordenar diferente para cada corrida del algoritmo 
		buckets.push_back(new ColorBucket(pColorPallete[index]));
	}
	//Asignar un color a los paises(Agotando las opciones)
	for (const auto& country : pCountries) {//Cada k paises se puede meter la marca para pintar el mapa svg(Lazyness)
		findBucket(country);
	}
}

bool Divide::findBucket(Country* pCountry)//Se puede cambiar a pasar todos los posibles por el primer bucket y recorrer 3 veces el vector de paises
{
	for (const auto& bucket : buckets) {//Para el Dynamic, por aca deberia ir el reordenamiento de los paises y recalculo de conexiones
		if (bucket->tryBucket(pCountry))
			break;
	}
}
