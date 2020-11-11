#include "Parser.h"


Parser::Parser()
{
}

WorldData * Parser::loadCountries(const char * pFileName)
{
    std::unordered_map<Country*> countries;
    XMLDocument worldFile;
    worldFile.LoadFile(pFileName);
    XMLElement* svg = worldFile.FirstChildElement();
    int width = stoi(svg->Attribute("width"));
    int height = stoi(svg->Attribute("height"));
    std::cout << "w: " << width << " h: " << height << std::endl;
    XMLElement* path = svg->FirstChildElement("path");

    CoordinateSystem * cs = new CoordinateSystem();
    while (path != NULL) {
        Country* country = new Country(path->Attribute("id"),path->Attribute("data-name"));
        cs->setMapPoints(path->Attribute("d"));
        // country->showMapPoints();

        countries.push_back(country);
        path = path->NextSiblingElement();
    }
    return new WorldData (width,height,countries);
}