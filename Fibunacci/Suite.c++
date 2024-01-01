#include <iostream>
#include <chrono>
#define max 30
using namespace std;
using namespace chrono;

// Approche récursive
int fibonacci_recursif(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursif(n - 1) + fibonacci_recursif(n - 2);
}

// Approche itérative
int fibonacci_iteratif(int n) {
    
    if(n==0) return 0;
    if(n==1) return 1;

    int a = 0, b = 1, c; //a et b representent les deux premiers termes  de la suite 
    int res[max]; //resultat se somme 
    res[0] = 0; //pour n=0
    res[1] = 1;//pour n=1

    for (int i = 2; i <= n; i++) { //Debutant de 2 
        c = a + b; // Somme des resulats des indices  n-1 et n-2
        a = b; 
        b = c;
        res[i] = c;//resultat des deux indices precedants n-1 et n-2
    }

    return res[n];
}

int main() {
    int val;
    cout << "Veuillez saisir l'argument de la suite : ";
    cin >> val;

    auto start = high_resolution_clock::now(); // Démarrer le chronomètre

    cout << "Le resultat recursif est : " << fibonacci_recursif(val) << endl;
     auto stop = high_resolution_clock::now(); // Arrêter le chronomètre
     auto duration = duration_cast<microseconds>(stop - start);
     cout << "Temps d'execution : " << duration.count() << " microsecondes" << endl;

 start = high_resolution_clock::now(); // Démarrer le chronomètre
    cout << "Le resultat iteratif est : " << fibonacci_iteratif(val) << endl;
    stop = high_resolution_clock::now(); // Arrêter le chronomètre
  duration = duration_cast<microseconds>(stop - start);
    cout << "Temps d'execution : " << duration.count() << " microsecondes" << endl;

    return 0;
}