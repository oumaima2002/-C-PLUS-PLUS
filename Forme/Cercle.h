#ifndef Cercle_H
#define Cercle_H
#include <iostream>
#include "Forme2D.h"

typedef struct
{
    int abscice;
    int ordonne;
} centre;

class Cercle : public Forme2D
{

private:
    int rayon;
    centre C;

public:
    // constructeur  parametre de cercle
    Cercle(int x, int y, int r)
    {
        this->rayon = r;
        this->C.abscice = x;
        this->C.ordonne = y;
    };
    void Afficher() override
    {
        std::cout << "Il s'agit d'un cercle , du centre abscicce: " << this->C.abscice << "  ordonne: " << this->C.ordonne;
    };
    double Surface() const override
    {
        return 3.14 * rayon * rayon;
    };
    double Perimetre() const override
    {
        return 2 * 3.14 * rayon;
    };
};
#endif