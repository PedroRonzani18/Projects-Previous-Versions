#include "../Header/Parser.h"

char* stringToArray(std::string str)
{
    int t = str.length() + 1;
    char* arr = (char *)malloc(t * sizeof(char));

    for(int i=0; i<t; i++)
        arr[i] = str[i];

    return arr;
}

std::pair<const char*,std::vector<float>> Parser::parsePlanet(const char* fileName, int creationType)
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