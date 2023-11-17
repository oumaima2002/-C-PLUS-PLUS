#ifndef voiture_h
#define voiture_h
#include "Chose.h"

class voiture : public Chose
{
public:
    int roues;
    voiture() : roues(4) {};
    void Affichage() const override
    {
        cout << "C'est une voiture" << endl;
    };
};

#endif
