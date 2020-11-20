#include "Painter.h"
#include "Utilities.h"

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

void Painter::paintWorld(unordered_map<string,Country*> pWorld,string  pFileName)//Modo Chambon
{
	cout << "Pintando Archivo "<<pFileName <<endl;
	XMLDocument * test = new XMLDocument();
	test->LoadFile("worldTest.svg");
	XMLElement* svgRoot = test->FirstChildElement();
	XMLElement* ptrPaths = svgRoot->FirstChildElement("path");
	string color;
	while (ptrPaths != nullptr)
	{
		string value;
		const char* AttributeText = nullptr;
		AttributeText = ptrPaths->Attribute("id");
		if (AttributeText != nullptr)
		{
			value = AttributeText;
			color = "fill:" + pWorld.at(value)->getColor() + ";fill-rule:evenodd";
			ptrPaths->SetAttribute("style", color.c_str());
			ptrPaths = ptrPaths->NextSiblingElement("path");
		}
		else {
			cout << "ERROR en lectura de SVG" << endl;
		}
	}
	char* fileName = &pFileName[0];
	test->SaveFile(fileName);
}

