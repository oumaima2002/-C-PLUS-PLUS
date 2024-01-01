#include "ClasseArbre.hpp"

#ifndef Operation_H_INCLUDED
#define Operation_H_INCLUDED

#include<iostream>
#include<stdio.h>
using namespace std;

#define COMPTEUR 10

template <class Type>
cel<Type>* ClasseArbre<Type>::creernoeud(const Type& val)
{
    cel<Type>* nouveau = new cel<Type>();
    nouveau->val = val;
    nouveau->fgauche = nullptr;
    nouveau->fdroit = nullptr;
    return nouveau;
}

template <class Type>
bool ClasseArbre<Type>::Est_Vide()
{
    return (nbelem == 0);
}

template <class Type>
void ClasseArbre<Type>::InsererNoeud(cel<Type>*& current, const Type& val)
{
    if (current == nullptr) {
        current = creernoeud(val);
        nbelem++;
    } else {
        if (val <= current->val) {
            InsererNoeud(current->fgauche, val);
        } else {
            InsererNoeud(current->fdroit, val);
        }
    }
}


template <class Type>
void ClasseArbre<Type>::InsererNoeud(const Type& val)
{
    InsererNoeud(noeud, val);
}


template <class Type>
void ClasseArbre<Type>::ChercherNoeud(cel<Type>* noeud, const Type& val)
{
    if (noeud == nullptr)
        cout << "Valeur non trouvée" << endl;
    else {
        if (noeud->val == val)
            cout << "Valeur Trouvee avec Succes" << endl;
        else if (val <= noeud->val)
            ChercherNoeud(noeud->fgauche, val);
        else
            ChercherNoeud(noeud->fdroit, val);
    }
}

template <class Type>
void ClasseArbre<Type>::Affichage_2d(cel<Type>* A, int space)
{
    if (A == nullptr)
        return;

    space += COMPTEUR;

    Affichage_2d(A->fdroit, space);

    int i;
    for (i = COMPTEUR; i < space; i++)
        cout << " ";
    
    cout << A->val << endl;

    Affichage_2d(A->fgauche, space);
}

template<class Type>
void ClasseArbre<Type>::Affichage()
{
    Affichage_2d(noeud, 0);
}

template<class Type>
ClasseArbre<Type>::~ClasseArbre(){};

template <class Type>
void ClasseArbre<Type>::SupprimerNoeud(const Type& val) {
    noeud = SupprimerNoeudRecursif(noeud, val);
}

template <class Type>
cel<Type>* ClasseArbre<Type>::SupprimerNoeudRecursif(cel<Type>*& root, const Type& val) {
    if (root == nullptr) {
        return root; // Rien à supprimer, retourne le nœud actuel
    }

    if (val < root->val) {
        root->fgauche = SupprimerNoeudRecursif(root->fgauche, val);
    } else if (val > root->val) {
        root->fdroit = SupprimerNoeudRecursif(root->fdroit, val);
    } else {
        // Le nœud avec la valeur à supprimer est trouvé

        // Cas 1 : Pas d'enfant gauche ou droit
        if (root->fgauche == nullptr) {
            cel<Type>* temp = root->fdroit;
            delete root;
            return temp;
        } else if (root->fdroit == nullptr) {
            cel<Type>* temp = root->fgauche;
            delete root;
            return temp;
        }

        // Cas 2 : Deux enfants
        cel<Type>* successeur = root->fdroit;
        while (successeur->fgauche != nullptr) {
            successeur = successeur->fgauche;
        }

        root->val = successeur->val;

        root->fdroit = SupprimerNoeudRecursif(root->fdroit, successeur->val);
    }

    return root;
}

#endif
