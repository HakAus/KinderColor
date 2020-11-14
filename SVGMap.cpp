// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Parser.h"
#include <cctype>
#include <iostream>

int main()
{
    //Esto pertenece al maapa
    CoordinateSystem* coordinateSystem = new CoordinateSystem();
    Parser::loadCountries("world.svg",coordinateSystem);

    return 0;
}