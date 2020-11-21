// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Map.h"
#include <cctype>
#include <iostream>

int main()
{
    bool painterThreadActive = true;
    bool* pt = &painterThreadActive;
    Map* map = new Map(pt);
    map->paint();
    return 0;
}