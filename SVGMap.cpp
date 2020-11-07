// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "SVGReader.h"

// using namespace tinyxml2;

int main()
{
    //Cargar info de path
    SVGReader * reader = new SVGReader();
    reader->read("world.svg");
    return 0;
}
