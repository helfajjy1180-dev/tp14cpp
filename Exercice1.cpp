#include <iostream>
#include <stdexcept>
using namespace std;

double calculerQuotient(int numerateur, int denominateur) {
    if (denominateur == 0) {
        throw invalid_argument("Division impossible : le diviseur est nul.");
    }
    return static_cast<double>(numerateur) / denominateur;
}

int main() {
    cout << "EXERCICE 1 - DIVISION SECURISEE\n";

    int essais[][2] = {{36, 6}, {-18, 3}, {7, 0}};

    for (const auto& essai : essais) {
        try {
            cout << essai[0] << " / " << essai[1]
                 << " = " << calculerQuotient(essai[0], essai[1]) << '\n';
        } catch (const exception& erreur) {
            cout << "Erreur : " << erreur.what() << '\n';
        }
    }

    return 0;
}
