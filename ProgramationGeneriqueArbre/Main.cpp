#include "Operation.hpp"
#include "ClasseArbre.hpp"

int main(void)
{
    cout<<"-----------------------------\n"<<"Arbre de Type Int"<<endl;
    ClasseArbre<int> Arbre;
    Arbre.InsererNoeud(5);
    Arbre.InsererNoeud(1);
    Arbre.InsererNoeud(10);
    Arbre.InsererNoeud(20);
    Arbre.Affichage();
    cout<<"-----------------------------\n"<<"Apres Suppression de 10"<<endl;
    Arbre.SupprimerNoeud(10);
    Arbre.Affichage();
    Arbre.ChercherNoeud(Arbre.noeud,6);
    cout<<"-----------------------------\n"<<"Arbre de Type Float"<<endl;
     ClasseArbre<float> A;
    A.InsererNoeud(2.6);
    A.InsererNoeud(7.9);
    A.InsererNoeud(20.9);
    A.InsererNoeud(100.9);
    A.Affichage();
    Arbre.SupprimerNoeud(2.6);
    cout<<"-----------------------------\n"<<"Apres Suppression de 2.6"<<endl;
    Arbre.Affichage();
    A.ChercherNoeud(A.noeud,100.9);
    return 1;
}
