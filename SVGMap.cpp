// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Parser.h"

int main()
{
    std::vector<Country*> a = Parser::loadCountries("world.svg");
    vector::iterator i;
    for (i = a.begin(); i < a.end(); i++)
    {
    	cout << (*i).id << endl;
    }
    return 0;
}