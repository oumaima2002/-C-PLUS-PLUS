#include <iostream>
using namespace std;

class Matrice {
private:
    int m;
    int n;
    int** T;

public:
    Matrice() : m(0), n(0), T(nullptr) {}//constructeur par defaut

    Matrice(int x, int y) : m(x), n(y) { //constructeur avec dimension de matrice
        T = new int*[n];
        for (int i = 0; i < n; i++) {
            T[i] = new int[m];
            for (int j = 0; j < m; j++) {
                T[i][j] = i * m + j; // Inialiser matrice avec valeur predefinies
            }
        }
    }

    Matrice(const Matrice& autre) : m(autre.m), n(autre.n) {//constructeur de recopie
        T = new int*[n];
        for (int i = 0; i < n; i++) {
            T[i] = new int[m];
            for (int j = 0; j < m; j++) {
                T[i][j] = autre.T[i][j];
            }
        }
    }

    ~Matrice() {//Destructeur 
        for (int i = 0; i < n; i++) {
            delete[] T[i];
        }
        delete[] T;
    }
    
//surcharge des opérateurs +=-*
    void operator=(const Matrice& autre);
    Matrice operator+(const Matrice& autre);
    Matrice operator-(const Matrice& autre);
    Matrice operator*(const Matrice& autre);
    
    friend void Affichage(const Matrice& M);//fonction ami
};

void Affichage(const Matrice& M) {
    for (int i = 0; i < M.n; i++) {
        for (int j = 0; j < M.m; j++) {
            cout << M.T[i][j] << " ";
        }
        cout << endl;
    }
}
