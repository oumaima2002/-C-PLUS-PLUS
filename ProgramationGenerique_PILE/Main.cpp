#include "ClassPile.hpp"
#include "OperationPile.hpp"

//Programme Principal

int main(void)
{
    //Implementation de la pile 
    //Type int
    ClassPile <int> Pile;
    cout<<" =>Type Entier : " <<endl;
    Pile.Empiler(1);    
    Pile.Empiler(2);
    Pile.Empiler(3);
    Pile.Empiler(4);
    Pile.Afficher();
    cout<< "Apres depilement :"<<endl;
    Pile.Depiler();
    Pile.Afficher();
    cout<<"-----------------------------------"<< endl;
    cout<<" =>Type Reel : "<< endl;
    ClassPile <float> P;
    P.Empiler(1.99);    
    P.Empiler(2.00);
    P.Empiler(34.9);
    P.Empiler(-4.555);
    P.Afficher();
    cout<< "Apres depilement :"<<endl;
    P.Depiler();
    P.Afficher();
    return 1;
}