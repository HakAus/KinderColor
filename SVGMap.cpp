// SVGMap.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Parser.h"
#include "CoordinateSystem.h"



char* xd(char* pChar, char pDelimiter, char* pContext)
{
    char* charCopy = pChar;
    char* workChar = new char;
    int index = 0;
    while (charCopy[index]) {
        if (charCopy[index] != pDelimiter)
        {
            workChar[index] = charCopy[index];
        }
        else
        {
            workChar[index] = '\0';
            pContext = &charCopy[index + 1];
            std::cout << pContext;
        }
        index++;
    }
    return workChar;
}
char* xd2(const char* pChar)
{
    char* copy = new char;
    int index = 0;
    while (pChar[index]) {
        copy[index] = pChar[index];
        index++;
    }
    copy[index] = '\0';
    return copy;
}

int main()
{
    char* nextToken = NULL;
    const char* parsed = "Que Buena Nota";
    char* test = xd2(parsed);
    std::cout << test;
    char* token = xd(test,' ', nextToken);
    while (token) {
        std::cout << token << std::endl;
        token = xd(NULL, ' ', nextToken);
    }
    //Esto pertenece al maapa
    /*CoordinateSystem* cs = new CoordinateSystem();
    Parser::loadCountries("world.svg",cs);*/
    return 0;
}