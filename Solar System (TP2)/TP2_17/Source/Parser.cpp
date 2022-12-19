#include "../Header/Parser.h"

std::pair<const char*,std::vector<float>> Parser::parsePlanet(const char* fileName)
{
    std::fstream arquivo;
    std::string linha;
    std::string temp;
    float found;
    std::stringstream ss;
    std::vector<float> values;
    std::string str;
    
    arquivo.open(fileName,std::fstream::in);

    //std::cout << fileName << std::endl;


    if(!arquivo.is_open())
    {
        printf("deu ruim\n");
    }
    else
    {
        getline(arquivo,linha);
        str = linha.substr(linha.find(":") + 2); // pega nome da textura
        //std::cout << str << " ";

        while(getline(arquivo,linha))
        {

            ss.clear(); ss.str("");
            ss << linha;

            while(!ss.eof())
            {
                ss >> temp;

                if(std::stringstream(temp) >> found){
                    values.push_back(found);
                    //std::cout << values.back() << std::endl;
                }
                                
                temp = "";
            }
        }
    }

    arquivo.close();

    // for(size_t i=0; i<values.size(); i++)
    //     std::cout << values[i] << " ";
// 
    // std::cout << std::endl;

    int t = str.length() + 1;
    char* arr = (char *)malloc(t * sizeof(char));

    for(int i=0; i<t; i++)
        arr[i] = str[i];


    // std::cout << arr << " ";
    // for(float i: values)
    //     std::cout << i << " ";
    // std::cout << std::endl;
// 
    // std::cout << std::endl;

        return make_pair(arr,values);
}