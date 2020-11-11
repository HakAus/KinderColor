// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Parser.h"
#include "CoordinateSystem.h"


int main()
{
	Parser * parser = new Parser();
    WorldData* worldData = parser->loadCountries("world.svg");
    CoordinateSystem * coordinateSystem = new CoordinateSystem(10, worldData);
    return 0;
}