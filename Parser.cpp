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
    XMLElement* path = svg->FirstChildElement("path");
    int counter = 0;
    while (path != NULL) {
        counter++;
        const char * id = path->Attribute("id");
        Country* country = new Country(id,path->Attribute("data-name"));
        pCoordinateSystem->setCountryInSquares(path->Attribute("d"),id);
        path = path->NextSiblingElement();
    }
    pCoordinateSystem->setCountries(countries);
    
}