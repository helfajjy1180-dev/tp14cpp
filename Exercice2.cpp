#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class StockInsuffisantException : public runtime_error {
public:
    explicit StockInsuffisantException(const string& message)
        : runtime_error(message) {}
};

class Produit {
private:
    string nom;
    int stock;

public:
    Produit(const string& libelle, int quantite)
        : nom(libelle), stock(quantite) {
        if (quantite < 0) {
            throw invalid_argument("Le stock initial ne peut pas etre negatif.");
        }
    }

    void vendre(int quantite) {
        if (quantite <= 0) {
            throw invalid_argument("La quantite doit etre positive.");
        }

        if (quantite > stock) {
            throw StockInsuffisantException(
                "Stock insuffisant pour " + nom +
                ". Disponible : " + to_string(stock) +
                ", demande : " + to_string(quantite) + "."
            );
        }

        stock -= quantite;
        cout << quantite << " unite(s) vendue(s). Stock restant : "
             << stock << '\n';
    }
};

int main() {
    cout << "EXERCICE 2 - GESTION DU STOCK\n";

    Produit article("Souris", 10);
    int commandes[] = {4, 8, 2};

    for (int quantite : commandes) {
        try {
            article.vendre(quantite);
        } catch (const StockInsuffisantException& erreur) {
            cout << "Vente refusee : " << erreur.what() << '\n';
        } catch (const exception& erreur) {
            cout << "Erreur : " << erreur.what() << '\n';
        }
    }

    return 0;
}
