#include <string>
#include <vector>
#include <utility>

using namespace std;
class Country
{
private:
	string Id;
	vector<pair<float,float>> Path;

public:
	Country();
	void setPath(string pPath);
	void addCoordinate(pair<float,float> pCoordinate);
	void setId(string pId);
	void log();
};