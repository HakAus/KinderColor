#include "Parser.h"

Parser::Parser()
{
}

std::vector<Country> Parser::loadCountries(const char * pFileName)
{
    std::vector<Country> countries;
    XMLDocument worldFile;
    worldFile.LoadFile(pFileName);
    XMLElement* svg = worldFile.FirstChildElement();
    XMLElement* path = svg->FirstChildElement("path");
    int counter = 0;
    while (path != NULL) {
        counter++;
        //std::cout << path->Attribute("id") << std::endl;
        Country* country = new Country(path->Attribute("id"),path->Attribute("data-name"));
        country->setMapPoints(path->Attribute("d"));
        country->showMapPoints();
        path = path->NextSiblingElement();
    }
    return countries;
}