#ifndef _SPACE_H
#define _SPACE_H

#include "Planet.h"
#include "Sol.h"
#include "Light.h"
#include "MusicManager.h"
#include "Camera.h"
#include "Model.h"
#include <vector>
#include <memory>
#include <glm/glm.hpp>

class Space
{
    private:
        std::shared_ptr<Sol> sol;
        std::shared_ptr<Planet> estrelas;
        std::vector<std::shared_ptr<Planet>> planets;
        std::shared_ptr<MusicManager> musicManager;
        std::shared_ptr<Camera> camera;
        std::vector<Model> objects;

    public:
        Space();    

        void drawPlanets();
        void initializePlanets();

        std::shared_ptr<Sol> getSol(){return this->sol;}

        std::shared_ptr<Planet> getEstrelas(){return this->estrelas;}

        std::shared_ptr<Planet> getPlanet(int i){return planets[i];}
        std::shared_ptr<MusicManager> getMusicManager(){return this->musicManager;}

        std::shared_ptr<Camera> getCamera(){return this->camera;}
        void atualizaPropriedadesLuz();

        void display();
        static double distanceBetweenPlanets(glm::vec3 a, glm::vec3 b);
        void onOffSun();
        void drawSaturnRing();
        void cameraColision();
        void cameraMoving();
        void drawSatelite();
        void initializeObjects();

};

#endif