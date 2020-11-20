#include "Painter.h"

Painter::Painter(XMLDocument * pWorldFile)
{
	worldFile = pWorldFile;	
}

void Painter::paintCountry(string pCountryId, string pColor)
{
	XMLElement * svgRoot = this->worldFile->FirstChildElement();
	XMLElement * ptrPaths = svgRoot->FirstChildElement("path");
	vector<string> countryIds;
	while (ptrPaths != nullptr)
	{
		string value;
		const char * AttributeText = nullptr;
		AttributeText = ptrPaths->Attribute("id");
		if (AttributeText != nullptr)
		{
			value = AttributeText;
			if (value == pCountryId){
				pColor = "fill:" + pColor + ";fill-rule:evenodd";
				ptrPaths->SetAttribute("style",pColor.c_str());
			}
			ptrPaths = ptrPaths->NextSiblingElement("path");
			countryIds.push_back(value);
		}
		else {
			cout << "ERROR en lectura de SVG" << endl;
		}
	}
	worldFile->SaveFile("world.svg");
}

void Painter::paintCountries(vector<Country *> pCountries)
{
	cout << "Entro" << endl;
	XMLElement * svgRoot = this->worldFile->FirstChildElement();
	XMLElement * ptrPaths = svgRoot->FirstChildElement("path");
	cout << "Aqui" << endl;
	while (ptrPaths != nullptr)
	{
		string value;
		const char * idAttribute = nullptr;
		idAttribute = ptrPaths->Attribute("id");
		if (idAttribute != nullptr)
		{	
			string id = string(idAttribute);
			for (const auto& country : pCountries)
			{
				if (country->getId() == id)
				{
					string color = "fill:" + country->getColor() + ";fill-rule:evenodd";
					ptrPaths->SetAttribute("style",color.c_str());
					break;
				}
			}			
			ptrPaths = ptrPaths->NextSiblingElement("path");
		}
		else {
			cout << "ERROR en lectura de SVG" << endl;
		}
	}
	worldFile->SaveFile("world.svg");
}