
#include "Lecture_Roman.hpp"
#include <chrono>
using namespace std::chrono;

//Constructeur Paramétré
Lecture_Roman::Lecture_Roman(string val) {
    this->fichier = val;
}

//Getter nom
string Lecture_Roman::getnom() {
    return this->fichier;
}

//Lecture du roman
void Lecture_Roman::Lire_Roman() {
    ifstream f(this->getnom().c_str());

    if (!f.is_open()) {
        cout << "Echec d'ouverture du fichier" << endl;
    } else {
        string ligne;
        while (getline(f, ligne)) {
            cout << ligne << endl;
        }
    }
}

//recherche d'un mot
void Lecture_Roman::rechercher_Mot(string v) {
    ifstream f(this->getnom().c_str());
    if (!f.is_open()) {
        cout << "Echec d'ouverture" << endl;
    } else {
        string ligne;
        int compt = 0;
        int n = 0;
        while (getline(f, ligne)) {
            n++;
            istringstream iss(ligne);
            string mot;
            while (iss >> mot) {
                if (v == mot.substr(0, mot.length() - 1)) {  // Utilisez l'opérateur == pour comparer les std::string
                    compt++;
                    cout << "Le mot se trouve en ligne : " << n << endl;
                }
            }
        }
        cout << "Le Roman contient " << compt << " fois le mot " << v << endl;
    }
}

//Menu Principal
void Lecture_Roman::Menu() {
    cout << "-----------Menu-----------" << endl;
    cout << "1 : Afficher Le Roman " << endl;
    cout << "2 : Rechercher Tous les mots du fichier avec leurs positions et informations sur le nombre d'occurrences de chaque mot : " << endl;
    cout << "3 : Quitter  " << endl;
}
