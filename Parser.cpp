#include "Parser.h"


Parser::Parser()
{
}


//Envia los datos de las dimensiones y setea la lista de paises al sistema de coordenadas
 void Parser::loadCountries(const char* pFileName, CoordinateSystem* pCoordinateSystem, XMLDocument * pWorldFile)
{
    std::vector<Country*>  countries;
    pWorldFile->LoadFile(pFileName);
    std::cout << "Cargo el SVG" << std::endl;
    XMLElement* svg = pWorldFile->FirstChildElement();
    int width = stoi(svg->Attribute("width"));
    int height = stoi(svg->Attribute("height"));
    std::cout << "w: " << width << " h: " << height << std::endl;
    XMLElement* path = svg->FirstChildElement("path");
    int counter = 0;
    while (path != NULL) {
        counter++;
        string id = std::string(path->Attribute("id"));
        string name = std::string(path->Attribute("data-name"));
        Country * country = new Country(id, name);
        pCoordinateSystem->addCountry(country);
        pCoordinateSystem->setCountryInSquares(path->Attribute("d"), country, 5);
        path = path->NextSiblingElement();
    }
}

