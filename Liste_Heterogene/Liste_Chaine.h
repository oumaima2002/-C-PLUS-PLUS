#ifndef Liste_Chaine_h
#define Liste_Chaine_h
#include "Chose.h"

// Structure du nœud définie pour notre liste
struct noeud
{
    Chose* valeur;
    struct noeud* suivant;
};

// Liste chaînée
class Liste_Chaine
{
public:
    noeud* cellule;
    int compteur;

    // Constructeur par défaut
    Liste_Chaine() : cellule(nullptr), compteur(0) {};

    noeud* Creer_noeud(Chose* val);
    void Inserer_noeud(Chose* val);
    void AfficherListe();
  
};


noeud* Liste_Chaine::Creer_noeud(Chose* val)
{
    // Allocation de la mémoire
    noeud* nouveau = new noeud();
    nouveau->valeur = val;
    nouveau->suivant = nullptr;
    return nouveau;
}

void Liste_Chaine::Inserer_noeud(Chose* val)
{
    noeud* nouveau = Creer_noeud(val);
    nouveau->suivant = cellule;
    cellule = nouveau;
    compteur++;
}
void Liste_Chaine::AfficherListe()
{
    noeud* courant = cellule;

    while (courant != nullptr)
    {
        courant->valeur->Affichage();
        courant = courant->suivant;
    }
}

#endif
