#ifndef Carre_H
#define Carre_H

#include <iostream>
#include "Forme2D.h"


class Carre : public Forme2D{
private:
double cote;
public:
//Constructeur Parametre
Carre(double largeur)
{
    this->cote=largeur;
}

//redefinition des fonctions
  void Afficher()  override
  {
     std::cout  << " Il s'agit d'un carre ";
  };
  double Surface() const override {
    return cote * cote;
 };
 double   Perimetre() const override{
    return 4 * cote;
 };
};

#endif