#include "BackTracking.h"

void BackTracking::execute(vector<Country*> pCountries, vector<string> pColorPallete)
{
	std::vector<Country*>::iterator firstVectorElement = pCountries.begin();
	bruteForce(pCountries, NULL, firstVectorElement);
}

void BackTracking::bruteForce(vector<Country*> pVector,Country * pTriggerBackTracking, std::vector<Country*>::iterator pFirstCountry) {
	if (pVector.begin() != pVector.end()) {
		for (const auto& color : colorPallete) {
			bruteForce(vector here to end);//Tiene que pintar
		}
		if (pVector.begin() == pFirstCountry && pTriggerBackTracking != NULL) {
			pVector.erase(std::remove(pVector.begin(), pVector.end(), pTriggerBackTracking));
			pTriggerBackTracking = NULL;
			bruteForce(pVector,pTriggerBackTracking,pFirstCountry);
		}
	}
}

//Me devuelvo cuando no hay posibilidades de color
//Vuelvo y cambio el color del anterior
//Avanzo e intento de nuevo
//me devuelvo, si no sirve cambiarle el color al anterior entonces vuelvo nuevamente
//Si llegando al inicio no es posible el cambio 