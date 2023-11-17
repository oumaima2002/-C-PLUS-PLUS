#ifndef rectangle_h
#define rectangle_h
#include "Chose.h"

class rectangle : public Chose
{
public:
    int cote;
    rectangle() : cote(0) {};
    void Affichage() const override
    {
        cout << "C'est un rectangle" << endl;
    };
};

#endif
