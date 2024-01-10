#ifndef LECTURE_ROMAN_H
#define LECTURE_ROMAN_H

/*@Prototypes: Classe Utilisé*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>


using namespace std;

class Lecture_Roman {
private:
    string fichier;

public:
    Lecture_Roman(string);
    string getnom();
    void Lire_Roman();
    void rechercher_Mot(string);
    void Menu();
};

#endif
