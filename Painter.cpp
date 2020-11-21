#include "Painter.h"
#include "Utilities.h"
#include <iostream>

Painter::Painter(XMLDocument * pWorldFile)
{
	worldFile = pWorldFile;	
}

Painter::Painter(string pfilename, CoordinateSystem* pCoordinateSystem, MemoryPainter* pMemoryPainter,bool* pt)
{
	fileName = pfilename;
	coordinateSystem = pCoordinateSystem;
	memoryPainter = pMemoryPainter;
	started = pt;

}

void Painter::run()
{
	cout << "La variable esta " << *started << endl;
	while (*started)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (memoryPainter->hasFinished()){
			*started = false;
		}
		memoryPainter->paint();
		paintWorld();
	}
}

void Painter::startThread()
{
	cout << "Thread started" << endl;
	std::thread painterThread(&Painter::run,this);
	painterThread.detach();
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

void Painter::paintWorld()//Modo Chambon
{
	unordered_map<string, Country*> world = coordinateSystem->getHash();
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
			color = "fill:" + world.at(value)->getColor() + ";fill-rule:evenodd";
			ptrPaths->SetAttribute("style", color.c_str());
			ptrPaths = ptrPaths->NextSiblingElement("path");
		}
		else {
			cout << "ERROR en lectura de SVG" << endl;
		}
	}
	char* cFileName = &fileName[0];
	test->SaveFile(cFileName);
}
