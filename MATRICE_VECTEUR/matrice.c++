#include "matrice.h"

void Matrice::operator=(const Matrice& autre) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << autre.T[i][j] << " ";
        }
        cout << endl;
    }
}

Matrice Matrice::operator+(const Matrice& autre) {
    if (m != autre.m || n != autre.n) {
        cout << "Erreur de dimensions" << endl;
        return Matrice();
    }

    Matrice resultat(m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            resultat.T[i][j] = T[i][j] + autre.T[i][j];
        }
    }

    return resultat;
}

Matrice Matrice::operator-(const Matrice& autre) {
    if (m != autre.m || n != autre.n) {
        cout << "Erreur de dimensions" << endl;
        return Matrice();
    }

    Matrice resultat(m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            resultat.T[i][j] = T[i][j] - autre.T[i][j];
        }
    }

    return resultat;
}

Matrice Matrice::operator*(const Matrice& autre) {
    if (m != autre.m || n != autre.n) {
        cout << "Erreur de dimensions" << endl;
        return Matrice();
    }

    Matrice resultat(m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            resultat.T[i][j] = T[i][j] * autre.T[i][j];
        }
    }

    return resultat;
}

int main() {
    Matrice mat1(2, 2); // creer matrice 1 avec valeurs predefinies

    Matrice mat2(2, 2); //creer matrice 2 avec valeurs predefinies

    Matrice resultatsomme = mat1 + mat2;

    Matrice resultatsoustraction = mat1 - mat2;

    Matrice resultatmultiple = mat1 * mat2;

    cout << "------Matrice1------ \n";
    Affichage(mat1);

    cout << "------Matrice2------ \n";
    Affichage(mat2);

    cout << "------Résultat Somme------ \n";
    Affichage(resultatsomme);

    cout << "------Résultat Soustraction------ \n";
    Affichage(resultatsoustraction);

    cout << "------Résultat Multiplication------ \n";
    Affichage(resultatmultiple);

    return 0;
}
