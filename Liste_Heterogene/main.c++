#include <iostream>
#include "Liste_Chaine.h"
#include "voiture.h"
#include "rectangle.h"
using namespace std;

int main(void)
{
    voiture v1;
    rectangle R;
    Liste_Chaine Liste;
    Liste.Inserer_noeud(&v1);
    Liste.Inserer_noeud(&R);
    Liste.AfficherListe();
    return 0;
}
