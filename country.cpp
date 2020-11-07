#include <string>
#include <utility>
#include <iostream>
#include <cctype>

#include "country.h"

Country::Country(){}

void Country::setPath(string pPath)
{
	string XBuffer;
	string YBuffer;
	bool NewCoordinate = false;
	bool HalfReady = false;

	for (char symbol : pPath) 
	{
		if (!isalpha(symbol)) 
		{
			if (symbol == ' ') 
				NewCoordinate = !NewCoordinate;

			if (NewCoordinate) 
			{
				if (symbol == ',') 
					HalfReady = !HalfReady;
				else 
				{
					if (!HalfReady)
						XBuffer += symbol;
					else
						YBuffer += symbol;
				}
			}
			else 
			{
				float x = stof(XBuffer);
				float y = stof(YBuffer);
				// pair<float,float> Coordinates = make_pair(x,y);
				// cout << "coord(" << Coordinates.first << ", " << Coordinates.second << ")" << " ";
				// Path.push_back(Coordinates);
				XBuffer = YBuffer = "";
			}
		} 
	}
	cout << endl;
}

void Country::setId(string pId)
{
	Id = pId;
}

void Country::addCoordinate(pair<float,float> pCoordinate)
{

}

void Country::log()
{
	cout << Id << endl;
}