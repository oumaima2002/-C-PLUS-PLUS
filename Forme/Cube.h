#ifndef Cube_H
#define Cube_H
#include <iostream>
#include "Form3D.h"

class Cube : public Forme3D
{
private:
  int cote;

public:
  // Constructeur parametre
  Cube(int largeur)
  {
    this->cote = largeur;
  };

  void Afficher() override
  {
    std::cout << "Il s'agit d'un cube ";
  };

  double Surface() const override
  {
    return 6 * cote * cote;
  };

  double Volume() const override
  {
    return cote * cote * cote;
  };
};

#endif