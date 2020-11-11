#include "Utilities.h"

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
