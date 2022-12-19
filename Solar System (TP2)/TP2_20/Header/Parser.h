#ifndef _PARSER_H
#define _PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <GL/freeglut.h>

class Parser
{
    public:
        const char* texture;
        float dependsOnLight;
        float numberOfMooons;
        float coreRadius;
        float rotationRadius;
        float translationPeriod;
        float rotationPeriod;
        GLenum glLightConst;
        float matAmbient[4];
        float matDifuse[4];
        float matEspec[4];
        float matShininess;

        //static std::pair<const char*,std::vector<float>> parsePlanet(const char* fileName, int creationType);
        static Parser parsePlanet(const char* fileName, int creationType);
        static std::pair<const char*,std::vector<float>> parseSun(const char* fileName);
        static Parser parseMoon(const char* fileName);


};

#endif