#include "Utilities.h"

Utilities::Utilities()
{

}

std::vector<std::string> Utilities::split(const char* pChar, char pDelimiter)
{
    std::vector<std::string> result;

    do
    {
        const char* begin = pChar;

        while (*pChar != pDelimiter && *pChar)
            pChar++;

        result.push_back(std::string(begin, pChar));
    } while (0 != *pChar++);

    return result;
}

std::vector<std::string> Utilities::split2(const char* pChar)
{
    std::vector<std::string> result;

    bool valueFound;

    do
    {
        const char* begin = pChar;
        const char* comma = NULL;

        while (isdigit(*pChar) || *pChar == '.' || *pChar == '-' || *pChar == ','){
        	if (*pChar == ',')
        		comma = pChar;
            pChar++;
            valueFound = true;
        }
        if (valueFound){
        	float firstValue = atof(std::string(begin,comma).c_str());
        	float secondValue = atof(std::string(comma,pChar).c_str());
        	std::tuple<float, float>(firstValue, secondValue);
			result.push_back(std::string(begin, pChar));
			valueFound = false;
        }

    } while (0 != *pChar++);

    return result;
}

std::tuple<float, float> getTupleFloatValue(const char* pToken) {
	vector<string> tokens = Utilities::split(pToken, ',');
	float firstValue = atof(tokens[0].c_str());
	float secondValue = atof(tokens[1].c_str());
	return std::tuple<float, float>(firstValue, secondValue);
}
