#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2000000001;

ifstream fin("mergeheap.in");
ofstream fout("mergeheap.out");

struct Nod {
    int cheie, grad;
    Nod* copil, *frate, *parinte;
};

Nod* nodNou(int val) {
    Nod* temp = new Nod;
    temp->cheie = val;
    temp->grad = 0;
    temp->copil = temp->frate = temp->parinte = nullptr;
    return temp;
}

class HeapBinomial {
    Nod* cap;

    Nod* reunesteArbori(Nod* arbore1, Nod* arbore2) {
        if (arbore1->cheie < arbore2->cheie) {
            swap(arbore1, arbore2);
        }

        arbore2->frate = arbore1->copil;
        arbore2->parinte = arbore1;
        arbore1->copil = arbore2;
        arbore1->grad++;

        return arbore1;
    }

    void ajusteaza() {
        if (cap == nullptr || cap->frate == nullptr) {
            return;
        }

        vector<Nod*> arbori;
        Nod* arbore = cap;

        while (arbore != nullptr) {
            if (arbore->frate == nullptr || arbore->grad < arbore->frate->grad) {
                arbori.push_back(arbore);
                arbore = arbore->frate;
            } else {
                Nod* urmator = arbore->frate;
                while (urmator != nullptr && urmator->grad == arbore->grad) {
                    urmator = urmator->frate;
                }

                if (urmator != nullptr) {
                    if (arbore->cheie < urmator->cheie) {
                        swap(arbore, urmator);
                    }

                    Nod* temp = urmator->frate;
                    urmator->frate = arbore->copil;
                    urmator->parinte = arbore;
                    arbore->copil = urmator;
                    arbore->grad++;
                    arbore = urmator;
                    urmator = temp;
                } else {
                    arbori.push_back(arbore);
                    arbore = nullptr;
                }
            }
        }

        cap = nullptr;

        for (Nod* arbore : arbori) {
            if (cap == nullptr || arbore->grad > cap->grad) {
                arbore->frate = cap;
                cap = arbore;
            } else {
                Nod* temp = cap;
                while (temp->frate != nullptr && temp->frate->grad > arbore->grad) {
                    temp = temp->frate;
                }
                arbore->frate = temp->frate;
                temp->frate = arbore;
            }
        }
    }

public:
    int maxim() {
        if (cap == nullptr) {
            return -1;  // Întoarce -1 dacă heap-ul este vid
        }

        int maxVal = cap->cheie;
        Nod* maxNod = cap;

        Nod* temp = cap;
        while (temp != nullptr) {
            if (temp->cheie > maxVal) {
maxVal = temp->cheie;
maxNod = temp;
}
temp = temp->frate;
}
    return maxVal;
}

void inserare(int val) {
    Nod* arbore = nodNou(val);

    if (cap == nullptr) {
        cap = arbore;
    } else {
        HeapBinomial heapTemp;
        heapTemp.cap = arbore;
        uneste(heapTemp);
    }
}

void uneste(HeapBinomial& heap2) {
    Nod* arbore1 = cap;
    Nod* arbore2 = heap2.cap;

    cap = nullptr;
    Nod* ultimArbore = nullptr;

    while (arbore1 != nullptr || arbore2 != nullptr) {
        Nod* arbore;
        if (arbore1 != nullptr && (arbore2 == nullptr || arbore1->grad <= arbore2->grad)) {
            arbore = arbore1;
            arbore1 = arbore1->frate;
        } else {
            arbore = arbore2;
            arbore2 = arbore2->frate;
        }

        if (cap == nullptr) {
            cap = arbore;
            ultimArbore = arbore;
        } else {
            ultimArbore->frate = arbore;
            ultimArbore = arbore;
        }
    }

    ajusteaza();
    heap2.cap = nullptr;
}

void extrageMaxim() {
    if (cap == nullptr) {
        return;
    }

    Nod* maxNod = cap;
    Nod* prevMaxNod = nullptr;
    Nod* temp = cap->frate;
    Nod* prevTemp = cap;

    while (temp != nullptr) {
        if (temp->cheie > maxNod->cheie) {
            maxNod = temp;
            prevMaxNod = prevTemp;
        }
        prevTemp = temp;
        temp = temp->frate;
    }

    if (prevMaxNod != nullptr) {
        prevMaxNod->frate = maxNod->frate;
    } else {
        cap = maxNod->frate;
    }

    HeapBinomial heapTemp;
    heapTemp.cap = maxNod->copil;
    ajusteaza();

    heapTemp.ajusteaza();
    uneste(heapTemp);

    delete maxNod;
}
};

int main() {
int N, Q;
fin >> N >> Q;
vector<HeapBinomial> heapuri(N);
queue<int> valoriMaxime;
for (int i = 0; i < Q; i++) {
    int op, a, b;
    fin >> op;
    if (op == 1) {
        fin >> a >> b;
        heapuri[a - 1].inserare(b);
    } else if (op == 2) {
        fin >> a;
        valoriMaxime.push(heapuri[a - 1].maxim());
        heapuri[a - 1].extrageMaxim();
    } else if (op == 3) {
        fin >> a >> b;
        heapuri[a - 1].uneste(heapuri[b - 1]);
    }
}

while (!valoriMaxime.empty()) {
    fout << valoriMaxime.front() << '\n';
    valoriMaxime.pop();
}

fin.close();
fout.close();

return 0;
}
