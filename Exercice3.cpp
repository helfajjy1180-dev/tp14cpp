#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

void lireFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
    }

    string ligne;
    while (getline(fichier, ligne)) {
        cout << ligne << '\n';
    }

    if (fichier.bad()) {
        throw runtime_error("Une erreur est survenue pendant la lecture.");
    }
}

int main() {
    cout << "EXERCICE 3 - LECTURE D'UN FICHIER\n";

    // Creation d'un fichier de demonstration.
    {
        ofstream exemple("exemple.txt");
        exemple << "Premiere ligne du fichier.\n";
        exemple << "Deuxieme ligne du fichier.\n";
        exemple << "Fin de la demonstration.\n";
    }

    try {
        lireFichier("exemple.txt");
    } catch (const exception& erreur) {
        cout << "Erreur : " << erreur.what() << '\n';
    }

    // Test d'un fichier inexistant.
    try {
        lireFichier("fichier_inconnu.txt");
    } catch (const exception& erreur) {
        cout << "Erreur : " << erreur.what() << '\n';
    }

    return 0;
}
