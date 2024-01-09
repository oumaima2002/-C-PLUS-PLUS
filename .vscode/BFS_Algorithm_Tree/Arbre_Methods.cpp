#ifndef Arbre_Methods_H
#define Arbre_Methods_H
#include<iostream>
#include <queue>
#include "Arbre.hpp"
using namespace std;

template<class general>
 Arbre<general>::Arbre()
{
    this->longueur=0;
    this->racine=nullptr;
}
template<class general>
noeud<general>* Arbre<general>::get_racine()
{
   return this->racine;
}
template<class general>
void Arbre<general>::set_racine(noeud<general>*val)
{
  this->racine=val;
}

template<class general>

void Arbre<general>::inserer(general val)
{
   if(!this->racine)
   {
    this->racine=new noeud(val);
   }
   else
   this->inser_val(this->racine,val);

this->longueur++;
}

template<class general>

void Arbre<general>::inser_val(noeud<general>*V,general val)
{
    if(val < V->get_val())
    {
       if(!V->get_fgauche())
         V->set_fgauche(new noeud(val));
       else
        this->inser_val(V->get_fgauche(),val);
    }else{
        
       if(!V->get_fdroit())
         V->set_fdroit(new noeud(val));
       else
        this->inser_val(V->get_fdroit(),val);
    
    }
}
template<class general>
void Arbre<general>::afficher_2d(noeud<general>* rac, int niveau)
{
    const int ESPACEMENT = 5;

    if (rac->get_fdroit())
    {
        afficher_2d(rac->get_fdroit(), niveau + 1);
    }

    for (int i = 0; i < niveau * ESPACEMENT; i++)
    {
        cout << " ";
    }

    cout << rac->get_val() << endl;

    if (rac->get_fgauche())
    {
        afficher_2d(rac->get_fgauche(), niveau + 1);
    }
}

/*@but: Affichage de l'arbre en infixe*/
template <class general>
void Arbre<general>::afficher()
{
    if (!this->racine)
    {
        cout << "Arbre Vide" << endl;
    }
    else
    {
        this->afficher_2d(this->racine, 0);
    }
    cout << endl;
}

/*@Objectif: Rechercher une valeur dans l'arbre 
@parms:valeur à rechercher dans arbra
@Algortithme: On utilise algorithme de rechercher en largeur (BFS)
*/

template <class general>
bool Arbre<general>::Rechercher_BFS(general value) {
  if (!racine)
    return false;

  queue<noeud<general> *> q;
  q.push(racine);

  noeud<general> *current;
  while (!q.empty()) {
    current = q.front();
    q.pop();

    if (current->get_val() == value) {
      cout<<"Valeur existe"<<endl;
      return true;
    }

    if (current->get_fgauche())
      q.push(current->get_fgauche());
    if (current->get_fdroit())
      q.push(current->get_fdroit());
  }

  // Valeur non trouve
        cout<<"Valeur n'existe pas"<<endl;

  return false;
}
#endif