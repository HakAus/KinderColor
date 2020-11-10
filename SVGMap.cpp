// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Parser.h"

int main()
{
    //Esto pertenece al maapa
    CoordinateSystem* cs = new CoordinateSystem();
    Parser::loadCountries("world.svg",cs);
    return 0;
}
