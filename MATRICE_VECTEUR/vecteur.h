#include <iostream>
using namespace std;

class SommeVecteur {
private:
    int x;
    int y;
    int z;

public:
    SommeVecteur(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Surcharge de l'opérateur d'addition (+)
    SommeVecteur operator+(const SommeVecteur& autre) {
        return SommeVecteur(this->x + autre.x, this->y + autre.y, this->z + autre.z);
    }

    // Surcharge de l'opérateur de soustraction (-)
    SommeVecteur operator-(const SommeVecteur& autre) {
        return SommeVecteur(this->x - autre.x, this->y - autre.y, this->z - autre.z);
    }

    // Surcharge de l'opérateur de multiplication (*)
    SommeVecteur operator*(const SommeVecteur& autre) {
        return SommeVecteur(this->x * autre.x, this->y * autre.y, this->z * autre.z);
    }

    friend void Afficher(const SommeVecteur&);
};

void Afficher(const SommeVecteur& v) {
    cout << "X: " << v.x << endl;
    cout << "Y: " << v.y << endl;
    cout << "Z: " << v.z << endl;
}
