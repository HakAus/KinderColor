#include "country.h"

class CoordinateSystem
{
private:
	float Interval;
	float Start;
	float Finish;
	unordered_map<float[4],string> SquareHash;

public:
	void updateSquares(Country * pCountry);

}