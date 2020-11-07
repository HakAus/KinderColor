#include "Parser.h"

Parser::Parser()
{
}

std::vector<Country*> Parser::loadCountries(const char * pFileName)
{
    std::vector<Country*> countries;
    XMLDocument worldFile;
    worldFile.LoadFile(pFileName);
    XMLElement* svg = worldFile.FirstChildElement();
    XMLElement* path = svg->FirstChildElement("path");
    while (path != NULL) {
        Country* country = new Country(path->Attribute("id"),path->Attribute("data-name"));
        country->setMapPoints(path->Attribute("d"));
        countries.push_back(country);
        path = path->NextSiblingElement();
    }
    return countries;
}