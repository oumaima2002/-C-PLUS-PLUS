#include <iostream>
#include "noeud.hpp"
using namespace std;
template <class general>
noeud<general>::noeud(general val)
{
    this->val=val;
    this->fgauche=nullptr;
    this->fdroit=nullptr;
}

template <class general>

noeud<general>::~noeud()
{
delete this->fdroit;
delete this->fgauche;
}

template <class general>

general noeud<general>::get_val()
{
    return this->val;
}

template <class general>

noeud<general>* noeud<general>::get_fgauche()
{
    return this->fgauche;
}
template <class general>

noeud<general>* noeud<general>::get_fdroit()
{
    return this->fdroit;
}
template <class general>

void noeud<general>::set_val(general val)
{
    this->val=val;
}
template <class general>

void noeud<general>::set_fdroit(noeud<general>*val)
{
this->fdroit=val;
}
template <class general>

void noeud<general>::set_fgauche(noeud<general>* val)
{
   this->fgauche=val;
}