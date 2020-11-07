#include <forward_list>
#include <iostream>
#include "SVGReader.h"
#include "country.h"

SVGReader::SVGReader()
{
}

void SVGReader::read(const char* pFileName)
{
	// Read paths from SVG
	XMLDocument MapFile;
	MapFile.LoadFile(pFileName);
    XMLElement * svg = MapFile.FirstChildElement("svg");
    XMLElement * path = svg->FirstChildElement("path");

    // Store country data in list.
    forward_list<Country*> countries;
    while (path != NULL) {
    	Country * country = new Country();
    	country->setId(path->Attribute("id"));
    	country->setPath(path->Attribute("d"));
    	countries.push_front(country);
        path = path->NextSiblingElement();
    }
    cout << "Despues de creacion de lista" << endl;
    forward_list<Country*>::iterator iterator;
    for (iterator = countries.begin(); iterator != countries.end(); iterator++)
    {
    	(*iterator)->log();
    }

}
