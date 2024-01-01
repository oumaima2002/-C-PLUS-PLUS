#ifndef ClassArbre_H_INCLUDED
#define ClassArbre_H_INCLUDED

template<class Type>
struct cel{
    Type val;
    struct cel *fgauche;
    struct cel *fdroit;
};

template <class Type>
class ClasseArbre{
public:
    cel <Type>* noeud;
    int nbelem;

public:
    ClasseArbre(){
        noeud = nullptr;
        nbelem = 0;
    };

    cel<Type>* creernoeud(const Type& val);
    void InsererNoeud(cel<Type>*& current, const Type& val);
    void InsererNoeud(const Type& val);
    void ChercherNoeud(cel<Type>* noeud, const Type& val);
    void Affichage_2d(cel<Type>* A, int space);
    bool Est_Vide();
    void Affichage();
    void SupprimerNoeud(const Type& val);
    cel<Type>* SupprimerNoeudRecursif(cel<Type>*& root, const Type& val);
    ~ClasseArbre();
};

#endif
