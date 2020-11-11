#include "Parser.h"


Parser::Parser()
{
}


//Envia los datos de las dimensiones y setea la lista de paises al sistema de coordenadas
void Parser::loadCountries(const char* pFileName, CoordinateSystem* pCoordinateSystem)
{
    std::vector<Country*>  countries;
    XMLDocument worldFile;
    worldFile.LoadFile(pFileName);
    XMLElement* svg = worldFile.FirstChildElement();
    int width = stoi(svg->Attribute("width"));
    int height = stoi(svg->Attribute("height"));
    std::cout << "w: " << width << " h: " << height << std::endl;
    XMLElement* path = svg->FirstChildElement("path");

    CoordinateSystem * cs = new CoordinateSystem();
    while (path != NULL) {
        counter++;
        const char * id = path->Attribute("id");
        Country* country = new Country(id,path->Attribute("data-name"));
        pCoordinateSystem->setCountryInSquares(path->Attribute("d"),id);
        path = path->NextSiblingElement();
    }
   // pCoordinateSystem->setCountries(countries);
    
}

char* Parser::copyChar(const char* pChar)
{
    char* copy = NULL;
    int index = 0;
    while (pChar[index]) {
        copy[index] = pChar[index];
        index++;
    }
    return copy;
}

char * Parser::splitChar(char* pChar, char pDelimiter, char* pContext)
{
    char* charCopy = pChar;
    char* workChar = NULL;
    int index = 0;
    while (charCopy[index]) {
        if (charCopy[index] != pDelimiter) 
        {
            workChar[index] = charCopy[index];
        }
        else 
        {
            workChar[index] = NULL;
            pContext = &charCopy[index + 1];
        }
        index++;
    }
    return workChar;
}
