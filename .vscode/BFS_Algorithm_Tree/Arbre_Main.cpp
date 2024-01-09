#include 'Arbre.hpp'


 void Arbre::inserer(int val)
 {
    if(val>this.noeud.val)//insertion a droite
    {
        this.fdroit=inserer(val);
    }else{
        this.fgauche=inserer(val);
    }
 }
 /*Principe est comme suit:
 avoir le premier noeud puis declare si il est visite puis passe au fils gauche .
 Ce fils gauche est declare a vrai , puis voir si ila un fils droit si oui , passera ce dernier 

 et le lettre a vrai . 
 puis rpasse a fils  gauche de son pere si a fils gauche a lors refaire le principe sinon
 passer a son frere.
 */

 void Arbre::Rechercher_BFS(noeud * f,int val)
 {
    if(this.noeud) //pour le noeud
    {
        if(this.noeud.val==val) 
        cout<<"valeur trouve"<<endl; //si valeur existe
        visite=true;
    }
    if(this.noeud->fgauche)
    {
        this.noeud->fgauche->visite=true;
        if(this.noeud->fgauche->fdroit)
        {
            Arbre->fgauche->fdroit->visite=true;
            Rechercher_BFS(Arbre->fgauche->fdroit,val);
        }

    }
    //Si ila fils droit et pas fils gauche , arbre juste avec branchea droite

    if(Arbre.noeud->fdroit)
    {
        Arbre.noeud->fdroit->visite=true;
        if(Arbre.noeud->fdroit->fgauche)
        {
            Arbre.noeud->fdroit->fgauche->visite=true;
            Rechercher_BFS(Arbre.noeud->fdroit,val);
        }

    }
    if(Arbre->fgauche==nullptr) //pas de fils gauche
    {
        Arbre->fgauche=Arbre->fgauche->fdroit;
        Rechercher_BFS(Arbre->fgauche->fdroit,val);
    }


 }