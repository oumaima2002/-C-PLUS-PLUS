#include "ClassPile.hpp"
#ifndef OperationPile_H_HEADER
#define OperationPile_H_HEADER
#include <iostream>
using namespace std;

//creation du noeud
template <class Type>
Cellule<Type>* ClassPile<Type>:: CreerCellule(const Type& val) {
    Cellule<Type>* nouveau = new Cellule<Type>();
    nouveau->data = val;
    nouveau->suivant = nullptr;
    return nouveau;
};
//Empiler un element dans la pile
template <class Type>
void ClassPile<Type>:: Empiler(const Type& val)
{Cellule <Type>* nouveau =CreerCellule(val); //construction du noeud
    if (cel == nullptr) {//si pile est vide
        cel = nouveau;
    } else {
     //Pile Plein
        nouveau->suivant = cel;
        cel = nouveau;
    }
    nbelem++;//incrementer nombre
};
//Depiler un noeud de pile
template <class Type>
void ClassPile<Type>::Depiler() {
    if (cel == nullptr) {
        cout << "La pile est vide." << endl;
        return;
    }
    Cellule<Type>* tmp = cel;
    cel = cel->suivant;
    delete tmp;
    nbelem--;
};

template <class Type>
void ClassPile<Type>::Afficher() {
    cout << "Les elements sont : ";
    Cellule<Type>* current = cel;
    while (current ) {
        cout << current->data << " ";
        current = current->suivant;
    }
    cout << endl;
}


template <class Type>
ClassPile<Type>::~ClassPile() {
    
};

#endif // OperationPile_H_HEADER
