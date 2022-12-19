#include "../Header/Parser.h"

char* stringToArray(std::string str)
{
    int t = str.length() + 1;
    char* arr = (char *)malloc(t * sizeof(char));

    for(int i=0; i<t; i++)
        arr[i] = str[i];

    return arr;
}

Parser Parser::parsePlanet(const char* fileName, int creationType)
{
    Parser returnParser;

    std::fstream arquivo;
    std::string linha;
    std::string temp;
    float found;
    std::stringstream ss;
    std::vector<float> values;
    std::vector<const char*> strings;
    std::string texture;
    
    arquivo.open(fileName,std::fstream::in);

    if(arquivo.is_open())
    {
        getline(arquivo,linha);
        texture = linha.substr(linha.find(":") + 2); // pega nome da textura

        while(getline(arquivo,linha))
        {
            ss.clear(); ss.str("");
            ss << linha;

            while(!ss.eof())
            {
                ss >> temp;

                if(std::stringstream(temp) >> found)
                    values.push_back(found);
                                
                temp = "";
            }
        }
    }

    arquivo.close();

    char* arr = stringToArray(texture);
    returnParser.texture = arr;
    returnParser.dependsOnLight = values[0];
    returnParser.numberOfMooons = values[1];
    returnParser.coreRadius = values[2];
    returnParser.rotationRadius = values[3];
    returnParser.translationPeriod = values[4];
    returnParser.rotationPeriod = values[5];
    returnParser.glLightConst = values[6];
    
    for(int i=0; i<4; i++)
    {
        returnParser.matAmbient[i] = values[7 + i];
        returnParser.matDifuse[i] = values[11 + i];
        returnParser.matEspec[i] = values[15 + i];
    }

    returnParser.matShininess = values[19];

    return returnParser;
}

Parser Parser::parseMoon(const char* fileName)
{
    std::fstream arquivo;
    std::string linha;
    std::string temp;
    float found;
    std::stringstream ss;
    std::vector<float> values;
    
    arquivo.open(fileName,std::fstream::in);

    if(arquivo.is_open())
    {
        while(getline(arquivo,linha))
        {
            ss.clear(); ss.str("");
            ss << linha;

            while(!ss.eof())
            {
                ss >> temp;

                if(std::stringstream(temp) >> found)
                    values.push_back(found);
                                
                temp = "";
            }
        }
    }

    arquivo.close();

    Parser returnParser;
    returnParser.coreRadius = values[0];
    returnParser.translationPeriod = values[1];
    returnParser.rotationPeriod = values[3];

    for(int i=0; i<4; i++)
    {
        returnParser.matAmbient[i] = values[4 + i];
        returnParser.matDifuse[i] = values[8 + i];
        returnParser.matEspec[i] = values[10 + i];
    }

    return returnParser;
}

std::pair<const char*,std::vector<float>> Parser::parseSun(const char* fileName)
{
    std::fstream arquivo;
    std::string linha;
    std::string temp;
    float found;
    std::stringstream ss;
    std::vector<float> values;
    std::vector<const char*> strings;
    std::string texture;
    
    arquivo.open(fileName,std::fstream::in);

    if(arquivo.is_open())
    {
        getline(arquivo,linha);
        texture = linha.substr(linha.find(":") + 2); // pega nome da textura

        while(getline(arquivo,linha))
        {
            ss.clear(); ss.str("");
            ss << linha;

            while(!ss.eof())
            {
                ss >> temp;

                if(std::stringstream(temp) >> found)
                    values.push_back(found);
                                
                temp = "";
            }
        }
    }

    arquivo.close();

    char* arr = stringToArray(texture);

    return make_pair(arr,values);
}