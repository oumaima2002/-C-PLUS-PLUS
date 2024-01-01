#ifndef ClassPile_H_INCLUDED
#define  ClassPile_H_INCLUDED
//classe cellule de la pile
//Pour avoir un type generique de valeur attribuer dans cellule on utilise template
template <class Type> 
struct Cellule
{
    /* data */
    Type data;
    struct Cellule *suivant;
};
template <class Type> 
//Classe Represantant la pile
class ClassPile{
private:
Cellule<Type>* cel;
 int nbelem;
public :
//Definition des constructeurs et methodes
//constructeur Par Defaut
ClassPile(){
    nbelem=0;
    cel=nullptr;
};
//constructeur de recopie
ClassPile(const ClassPile&);
//Methodes definie pour la pile
Cellule<Type>* CreerCellule(const Type& );
void Empiler(const Type& );
void Depiler();
void Afficher();
//Destructeur 
~ClassPile();
};

#endif // Finish header