// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Map.h"
#include <cctype>
#include <iostream>

int main()
{
    bool painterThread = true;
    bool* pt = &painterThread;
    Map* map = new Map(pt);
    map->paint();
    while (painterThread) {
        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}