#ifndef noeud_H
#define noeud_H

/*Classe: Structure de Noeud générique
@Info:Classe represantant struture et methode du 
noeud utilisé par la suite à une arbre
*/
template<class general>
class noeud{

private:
general val;
noeud<general> *fgauche;
noeud<general> *fdroit;

public :
noeud<general>(general);
~noeud<general>();
general get_val();
void set_val(general val);
noeud<general>* get_fgauche();
noeud<general>* get_fdroit();
void set_fgauche(noeud<general>*);
void set_fdroit(noeud<general>*);
};
#endif