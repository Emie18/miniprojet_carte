#ifndef ROUTE_H
#define ROUTE_H
#include "Carte.h"
class Route{
    private:
        int i_deb;
        int i_fin;
        int distance;
    public:
        Route(){}
        ~Route(){}
        int getIDeb()const{return i_deb;}
        int getIfin()const{return i_fin;}
        int getDistance()const{return distance;}
        std::string getInfos()const{
            std::string a = std::to_string(i_deb);
            std::string b = std::to_string(i_fin);
            std::string c = std::to_string(distance);
            return "debut:"+a+" fin:"+b+" distance:"+c;
        }
        void affiche()const{
            std::cout<< this->getInfos()<<"\n";
        }

};
#endif