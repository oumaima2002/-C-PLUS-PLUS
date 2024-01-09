#include <iostream>
#include <chrono>
#include <vector>  //Pour avoir tableau dynamique
using namespace std;
using namespace chrono;

/*Approche Récursive
@parametre : l'argument a calculer son suite de fibunnaci
@resultat :le dernier valeur calculer par la suite
@But: Calculer suite de fibbuncci reccurssivement pour une donne n
*/ 
unsigned long int  fibonacci_recursif(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursif(n - 1) + fibonacci_recursif(n - 2);
}

/*Approche Iterative
@parametre : l'argument a calculer son suite de fibunnaci
@resultat :le dernier valeur calculer par la suite
@But: Calculer suite de fibbuncci Iterativement pour une donne n
*/ 

unsigned long int  fibonacci_iteratif(int n) {
    
    if(n==0) return 0;
    if(n==1) return 1;

    unsigned long int  a = 0, b = 1, res=0; //a et b representent les deux premiers termes  de la suite 
    for (int i = 2; i <= n; i++) { //Debutant de 2 
        res = a + b; // Somme des resulats des indices  n-1 et n-2
        a = b; 
        b = res;
    }

    return res;
}

/*Approche  par tableau dynamique "vector"
@parametre : l'argument a calculer son suite de fibunnaci
@resultat :tableau dynamique des nombres fibbunaci calcule pour cet argument
@But: Calculer suite de fibbuncci par vector pour une donne n
*/ 
vector<unsigned long int> fibunnaci_Vect(int n)
{
    vector<unsigned long int> res;
    if(n==0) return res;
    res.push_back(1);
    if(n==1) return res;
    res.push_back(1);
    for(int i=2;i<n;i++)  
    {
         res.push_back(res[i-1]+res[i-2]);
    }
      return res;
}
/*Affichage du resultat de suite de fibunnaci 
@parametre :  le vector res contenant les calcules
@resultat :afficher la derniere case de vector contenat le resultat de calcule de suite de fibunacci
@But:  Afficher le resultat
*/ 
void Afficher_Res(vector<unsigned long int>res)
{
    
    if(!res.empty())
    cout<<res.back();
}






int main() {
    int val;
    cout << "Veuillez saisir l'argument de la suite : ";
    cin >> val;
    if(val<0) {cout<<"Argument Invalide"; exit(-1);}


    // auto start = high_resolution_clock::now(); // Démarrer le chronomètre

    // cout << "Le resultat recursif est : " << fibonacci_recursif(val) << endl;
    //  auto stop = high_resolution_clock::now(); // Arrêter le chronomètre
    //  auto duration = duration_cast<microseconds>(stop - start);
    //  cout << "Temps d'execution : " << duration.count() << " microsecondes" << endl;

    auto start = high_resolution_clock::now(); // Démarrer le chronomètre
    cout << "Le resultat iteratif est : " << fibonacci_iteratif(val) << endl;
    auto stop = high_resolution_clock::now(); // Arrêter le chronomètre
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Temps d'execution : " << duration.count() << " microsecondes" << endl;
    
    start = high_resolution_clock::now(); // Démarrer le chronomètre
    cout << "Le resultat par vector est : " ;
    vector<unsigned long int> res=fibunnaci_Vect(val);
    stop = high_resolution_clock::now(); // Arrêter le chronomètre

    Afficher_Res(res) ;
     duration = duration_cast<microseconds>(stop - start);
    cout << "Temps d'execution : " << duration.count() << " microsecondes" << endl;

    return 0;
}