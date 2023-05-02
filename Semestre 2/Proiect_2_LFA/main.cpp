#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int vStari[100];

int dfa(string a[100][100], int stareInitiala, int n, char litera)
{
    //vStari[100]={};
    int stareCurenta = stareInitiala;

    for (int j = 0; j < n; j++) {
        if (a[stareCurenta][j].find(litera) != -1) {
            stareCurenta = j;
        }
    }

    return stareCurenta;
}
///După ce șirul de caractere a fost parcurs complet, starea finală a DFA-ului este returnată.


int main()
{
    ifstream fin("date.in");
    int n, stareInitiala, e[100][100], nrFin, aux;
    fin>>n;                       //numărul de stări ale automatului
    fin>>stareInitiala;           //starea inițială a automatului
    fin>>nrFin;                   // numărul de stări finale ale automatului
    string a[100][100], alfabet;  //alfabetul folosit de automat
    vector <int> stariFinale;     //vectorul care conține stările finale ale automatului

    for(int i=0; i<nrFin; i++){
        fin>>aux;
        stariFinale.push_back(aux);
    }

    fin.ignore();
    getline(fin, alfabet);

    for(int i=0; i<100 ; i++)
        for(int j=0; j<100 ; j++)
            a[i][j] = "-";

     for (int i = 0; i < n; i++) {
        int x, y;
        char litera;
        fin >> x >> litera >> y;
        if (a[x][y] != "-") {
            a[x][y] += litera;
        } else {
            a[x][y].pop_back();
            a[x][y] += litera;
        }
    }

    for(int i=stareInitiala; i<stareInitiala+n; i++)
    for(int j=stareInitiala; j<stareInitiala+n; j++){
        e[i][j] = 1;
        if(i != j){
            if((find(stariFinale.begin(), stariFinale.end(), i) != stariFinale.end() &&
                find(stariFinale.begin(), stariFinale.end(), j) == stariFinale.end()) ||
               (find(stariFinale.begin(), stariFinale.end(), j) != stariFinale.end() &&
                find(stariFinale.begin(), stariFinale.end(), i) == stariFinale.end()))
                    e[i][j] = 0;}
        else e[i][j] = -1;
    }


    int ok = 1;
    while(ok){
        ok = 0;

        for(int i=stareInitiala+1; i<stareInitiala + n; i++)
            for(int j=stareInitiala; j < i; j++)
                for(int k=0; k<alfabet.length(); k++){
                    int i2 = dfa(a, i, n, alfabet[k]);
                    int j2 = dfa(a, j, n, alfabet[k]);
                    if(i2 < j2)
                        swap(i2, j2);
                    if(e[i2][j2] == 0 && e[i][j] != 0 && i2 != j2){
                        e[i][j] = 0;
                        ok = 1;
                        break;
                    }

                }
        }

    vector <string> stariNoi;
    int m=0;
    for(int j=stareInitiala; j<stareInitiala+n; j++){
        if(!vStari[j]){
            stariNoi.push_back(to_string(j));        //vectorul care va conține noile stări ale automatului minimizat
            m++;                                    //numărul de stări al automatului minimizat
            vStari[j]++;

        for(int i=j+1; i<stareInitiala + n; i++)
            if(e[i][j] == 1){
                stariNoi.back() += (to_string(i));
                vStari[i]++;
            }
        }
    }

    cout<<"Nr. stari: "<<m<<endl<<"Stare initiala: "<<stareInitiala<<endl;
    cout<<"Nr. stari finale: "<<stariFinale.size()<<endl;
    cout<<"Stari finale: ";
for(int i=0; i<stariNoi.size(); i++)
    if (any_of(stariFinale.begin(), stariFinale.end(), [&](int c) { return binary_search(stariNoi.at(i).begin(), stariNoi.at(i).end(), c+'0'); }))
    {
        cout << stariNoi.at(i) << " ";
    }
    cout<<endl;
    cout<<"Alfabet: "<<alfabet<<endl;

    cout << "Tabel de tranzitii:\n";
for(int i = stareInitiala; i < stareInitiala + m; i++) {
    for(int j = stareInitiala; j < stareInitiala + m; j++) {
        cout << e[i][j] << " ";
    }
    cout << "\n";
}


    return 0;
}
