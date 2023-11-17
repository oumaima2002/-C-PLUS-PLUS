#ifndef FORME3D_H
#define FORME3D_H

#include "Forme.h"

class Forme3D : public Forme
{
private:
    // pas d'attribut
public:
    // implementation des methodes virtuelles pures
    virtual double Volume() const = 0;
};

#endif