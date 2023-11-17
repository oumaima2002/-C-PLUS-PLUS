#ifndef FORME2D_H
#define FORME2D_H

#include"Forme.h"


//heritage du classe mere
class Forme2D : public Forme
{
    private:
    //pas d'attribut
public :
//implementation des methodes virtuelles pures 
virtual double Perimetre() const =0;
};
#endif