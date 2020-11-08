#include <unordered_map>
#include "Country.h"
#include "Square.h"

using namespace std; 

class CoordinateSystem
{
private:
	float interval;
	float width;
	float height;
	unordered_map<Square*,string> SquareHash;

public:
	CoordinateSystem();
	void updateSquares(Country * pCountry);
	void setFrame(float pWidth, float pHeight);
	void setInterval(float pInterval);

};