#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nume_fisier"); // Deschidem fisierul de intrare

const int MAX = 100;

int n, m, q, f, t[MAX][MAX], F[1000], afis[MAX];
char s[MAX];

int main() {


    fin >> n >> m; // Citim numarul de stari si numarul de simboluri din alfabet
    for (int i = 0; i < m; i++)
        fin >> s[i]; // Citim simbolurile din alfabet

    fin >> q; // Citim numarul de tranzitii
    for (int i = 0; i < q; i++) {
        int x, y;
        char c;
        fin >> x >> c >> y; // Citim o tranzitie sub forma "i a j"
        t[x][c - 'a'] = y; // Salvam tranzitia in matricea t
    }

    fin >> q; // Citim starea initiala a automatului
    for (int i = 0; i < q; i++) {
        int x;
        fin >> x;
    }

    fin >> f; // Citim numarul de stari finale si starile finale ale automatului
    for (int i = 0; i < f; i++) {
        int x;
        fin >> x;
        F[i]=x; // Adaugam starea in vectorul cu stari finale
    }

    fin.close(); // Inchidem fisierul de intrare

    string cuvant;
    cin >> cuvant; // Citim cuvantul de la tastatura

    int stare_curenta = 0; // Pornim de la starea initiala
    int j = 0;

    for (int i = 0; i < cuvant.length(); i++) {
        afis[j] = stare_curenta;
        j++;
        stare_curenta = t[stare_curenta][cuvant[i] - 'a']; // Aplicam tranzitia corespunzatoare simbolului
    }
    afis[j] = stare_curenta;
    j++;

    bool cuvant_acceptat = false;
    for (int i = 0; i < f; i++) {
        if (stare_curenta == F[i]) {
            cuvant_acceptat = true;
            break;
        }
    }

    if (cuvant_acceptat) {
        cout << "Cuvantul este acceptat!" << endl;

        for (int i = 0; i < j - 1; i++) {
            cout << "q" << afis[i] << " -> ";
        }
        cout << "q" << afis[j-1];
    } else {
        cout << "Cuvantul nu este acceptat!" << endl;
    }

    return 0;
}
