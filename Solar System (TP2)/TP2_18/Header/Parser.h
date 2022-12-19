#ifndef _PARSER_H
#define _PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

class Parser
{
    public:
        static std::pair<const char*,std::vector<float>> parsePlanet(const char* fileName, int creationType);

};

#endif