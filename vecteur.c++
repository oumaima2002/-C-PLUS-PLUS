#include "vecteur.h"


int main() {
    SommeVecteur v1(1, 2, 3);
    SommeVecteur v2(4, 5, 6);

    SommeVecteur somme = v1 + v2;
    SommeVecteur soustraction = v1 - v2;
    SommeVecteur multiplication = v1 * v2;

    cout << "------ Somme ------" << endl;
    Afficher(somme);

    cout << "------ Soustraction ------" << endl;
    Afficher(soustraction);

    cout << "------ Multiplication ------" << endl;
    Afficher(multiplication);

    return 0;
}
