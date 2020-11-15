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