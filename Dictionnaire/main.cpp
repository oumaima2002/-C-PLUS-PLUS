#include "Lecture_Roman.cpp"

//Main
int main() {
    int choix;
    string res;
    Lecture_Roman f("The_romans.txt");

    
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    duration<double> elapsed;

    do {
        f.Menu();
        cout << "Veuillez Saisir votre Choix" << endl;
        cin >> choix;

        switch (choix) {
            case 1:
                // @info : Mesurer le temps pour Lire_Roman
                start = high_resolution_clock::now();
                cout << "Voici le roman :" << endl;
                f.Lire_Roman();
                end = high_resolution_clock::now();
                elapsed = end - start;
                cout << "Temps ecoule : " << elapsed.count() << " secondes" << endl;
                break;
            case 2:
                // @info: Mesurer le temps pour rechercher_Mot
                cout << "Veuillez Saisir Le mot a rechercher " << endl;
                cin >> res;
                start = high_resolution_clock::now();
                f.rechercher_Mot(res);
                end = high_resolution_clock::now();
                elapsed = end - start;
                cout << "Temps ecoule : " << elapsed.count() << " secondes" << endl;
                break;
            case 3:
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
        }
    } while (choix != 3);

    return 0;
}
