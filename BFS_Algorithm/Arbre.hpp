#ifndef  Arbre_hpp
#define Arbre_hpp Arbre_hpp
#include "noeud.cpp"

template <class general>

class Arbre{
// attributs privées
private:
noeud<general> *racine;
int longueur;
//Methodes prive
void inser_val(noeud<general>*,general val);
void supprimer(noeud<general>*);
void afficher_2d(noeud<general>*,int );

public:
Arbre();
bool Rechercher_BFS(general val);
void afficher();
void inserer(general val);
noeud<general>*get_racine();
void set_racine(noeud<general>*);


};
#endif