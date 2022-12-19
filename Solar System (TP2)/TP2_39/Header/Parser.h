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
        const char* modelo;
        float size;
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
        float alteravel, d,m,e;

        static Parser parsePlanet(const char* fileName, int creationType);
        static Parser parseSun(const char* fileName);
        static Parser parseMoon(const char* fileName);
        static std::vector<std::pair<const char*,int>> parseSolarSystem(const char* fileName);
        static Parser parseModel(const char* fileName);
};

#endif