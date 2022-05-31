#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <iostream>
#include <string>
#include <vector>

class Waypoint{
    protected:
        std::string nom;
        float lat;
        float lon;

    public:
        Waypoint(std::string nom1="",float la=0,  float lo=0): nom(nom1),lat(la),lon(lo){};
        std::string getNom(){return nom;}
        float getLon(){return lon;}
        float getLat(){return lat;}
        virtual bool isVille() const {return false;};
        std::string getInfo(){return (nom+"longitude"+std::to_string(lon)+"latitude:"+std::to_string(lat)+"\n");        }
        void affiche(){
            std::cout << this->getInfo();
        }
};

#endif