#ifndef _OBJECT_H
#define _OBJECT_H

#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "Light.h"
#include "Material.h"

class Object
{
    protected:
        GLuint texture;
        double rotationPeriod;
        double translationPeriod;
        double conversionConst;
        glm::vec3 midPoint;
        double rotationRadius; // radio do movimento de rotação

        double angle; // angulo do movimento de rotação
        double translationAngularSpeed; // velocidade angular do movimento de rotação ao redor do sol (movimento de translação)
        double rotationAngularSpeed; // velocidade angular de rotação no proprio eixo ( movimento de rotação )
        double dependsOnLight;
        GLenum glLightConst;
        Light* light;
        Material* material;
        int hasLight;
        GLuint displayListId;

    public:
        Object(){}

        GLuint getTexture(){return this->texture;}
        void setTexture(GLuint texture){this->texture = texture;}

        // double getCoreRadius(){return this->coreRadius;}
        // void setCoreRadius(double coreRadius){this->coreRadius = coreRadius;}

        // double getRotationRadius(){return this->rotationRadius;}
        // void setRotationRadius(double rotationRadius){this->rotationRadius = rotationRadius;}

        double getRotationPeriod(){return this->rotationPeriod;}
        void setRotationPeriod(double rotationPeriod){this->rotationPeriod = rotationPeriod;}

        double getTranslationPeriod(){return this->translationPeriod;}
        void setTranslationPeriod(double translationPeriod){this->translationPeriod = translationPeriod;}

        double getConversionConst(){return this->conversionConst;}
        void setConversionConst(double conversionConst){this->conversionConst = conversionConst;}

        double getAngle(){return this->angle;}
        void setAngle(double angle){this->angle = angle;}

        double getTranslationAngularSpeed(){return this->translationAngularSpeed;}
        void setTranslationAngularSpeed(double translationAngularSpeed){this->translationAngularSpeed = translationAngularSpeed;}

        double getRotationAngularSpeed(){return this->rotationAngularSpeed;}
        void setRotationAngularSpeed(double rotationAngularSpeed){this->rotationAngularSpeed = rotationAngularSpeed;}

        bool doesDependsOnLight(){return this->dependsOnLight;}
        void setDependsOnLight(bool dependsOnLight){this->dependsOnLight = dependsOnLight;}

        double getRotationRadius(){return this->rotationRadius;}
        void setRotationRadius(double rotationRadius){this->rotationRadius = rotationRadius;}

        glm::vec3 getMidPoint(){return this->midPoint;}
        void setMidPoint(double x, double y, double z){
            this->midPoint.x = x;
            this->midPoint.y = y;
            this->midPoint.z = z;
        }

        GLenum getGlLightConst(){return this->glLightConst;}

        Light* getLight(){return this->light;}

        int getHasLight(){return this->hasLight;}

        Material* getMaterial(){return this->material;}

        GLuint getDisplayListId(){return this->displayListId;}
};

#endif