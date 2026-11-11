#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class MontantInvalideException : public invalid_argument {
public:
    explicit MontantInvalideException(const string& message)
        : invalid_argument(message) {}
};

class SoldeInsuffisantException : public runtime_error {
public:
    explicit SoldeInsuffisantException(const string& message)
        : runtime_error(message) {}
};

class Compte {
private:
    int solde;

public:
    explicit Compte(int soldeInitial) : solde(soldeInitial) {
        if (soldeInitial < 0) {
            throw MontantInvalideException("Le solde initial est invalide.");
        }
    }

    void deposer(int montant) {
        if (montant <= 0) {
            throw MontantInvalideException("Le depot doit etre positif.");
        }

        solde += montant;
        cout << "Depot effectue. Solde : " << solde << '\n';
    }

    void retirer(int montant) {
        if (montant <= 0) {
            throw MontantInvalideException("Le retrait doit etre positif.");
        }

        if (montant > solde) {
            throw SoldeInsuffisantException(
                "Solde insuffisant. Solde disponible : " + to_string(solde)
            );
        }

        solde -= montant;
        cout << "Retrait effectue. Solde : " << solde << '\n';
    }

    int consulterSolde() const {
        return solde;
    }
};

int main() {
    cout << "EXERCICE 4 - SIMULATION BANCAIRE\n";

    Compte compte(650);

    try {
        compte.deposer(120);
        compte.retirer(200);

        try {
            compte.retirer(900);
        } catch (const SoldeInsuffisantException& erreur) {
            cout << "Retrait refuse : " << erreur.what() << '\n';
        }

        compte.deposer(-40);
    } catch (const MontantInvalideException& erreur) {
        cout << "Montant invalide : " << erreur.what() << '\n';
    }

    cout << "Solde final : " << compte.consulterSolde() << '\n';
    return 0;
}
