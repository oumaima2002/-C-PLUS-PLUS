#include <iostream>
#include "Arbre_Methods.cpp"
using namespace std;
#include <chrono>

int main()
{
    int i;
    Arbre<int> A;
    for(int i=0;i<1000;i++)
        A.inserer(i);

      //@Remarque: Affichage est tres grand   "pour tester vous pouvez faire valeur max de i petite pour voir le schema en 2D de l'arbre"
      //A.afficher();
     auto start_time = std::chrono::high_resolution_clock::now();
     A.Rechercher_BFS(800);
     auto end_time = std::chrono::high_resolution_clock::now();
     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
     std::cout << "Temps d'execution : " << duration.count() << " microsecondes" << std::endl;

}