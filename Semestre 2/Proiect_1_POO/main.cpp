#include <iostream>
#include <string.h>
using namespace std;

class Karateka {
private:
    static int contorId;
    const int idSala;
    char* numeSala;
    string tipAntrenament;
    char culoareCentura;
    int nrAni;
    float* gradCentura;
    bool sensei;

public:
    //Constructori
    Karateka();  // Constructor fara parametrii
    Karateka(char* numeSala, string tipAntrenament, char culoareCentura, int nrAni,
        float* gradCentura, bool sensei, int ); // Constructor parametrizat
    Karateka(const Karateka& obj);   // Copy constructor

    //Operator
    Karateka& operator = (const Karateka&);
    friend ostream& operator <<(ostream& out, const Karateka& obj);
    friend istream& operator >>(istream& in, Karateka& obj);
    Karateka& operator++();
    Karateka operator++ (int);
    Karateka operator+(const Karateka& obj);
    Karateka operator+(int);
    friend Karateka operator+(int, Karateka obj);
    bool operator==(const Karateka&);
    float operator[](int);
    operator int();
    //operator int() const {return this->;}


    //Metode
    void afisare();
    void citire();

    //Get+Set
    static int getContorId() {return Karateka::contorId;}
    string getTipAntrenament() {return tipAntrenament;}
    int getnrAni() {return nrAni;}
    const float* getCantitateMiere() const {return this->gradCentura;}


    friend void afisare2(const Karateka& obj);


    //Destructor
    ~Karateka();

};

int Karateka::contorId = 1000;

Karateka::~Karateka(){

    if(this->numeSala!=NULL)
    {
        delete[] this->numeSala;
        this->numeSala=NULL;
    }
    if(this->gradCentura!=NULL)
    {
        delete[] this->gradCentura;
        this->gradCentura=NULL;
    }
}

Karateka::Karateka():idSala(contorId++) {
    numeSala = new char[strlen("Anonim") + 1]; /// Alocat memorie fara sa initializam
    strcpy(numeSala, "Anonim");  /// Initializam variabila
    tipAntrenament = "Anonim";
    culoareCentura = '-';
    nrAni = 0;
    gradCentura = NULL;
    sensei = false;
}

Karateka::Karateka(char* numeSala, string tipAntrenament, char culoareCentura, int nrAni,
float* gradCentura, bool sensei): idSala(contorId++){
    this->numeSala = new char[strlen(numeSala) + 1]; ///alocat memorie
    strcpy(this->numeSala, numeSala); ///initializez variabila
    this->tipAntrenament = tipAntrenament;
    this->culoareCentura = culoareCentura;
    this->nrAni = nrAni;
    this->gradCentura = new float[gradCenetura];
    for(int i=0; i<nrAni; i++)
        this->gradCentura[i] = gradCentura[i];
    //this->gradCentura=gradCentura;
    this->sensei = sensei;
}

Karateka::Karateka(const Karateka& obj): idSala(contorId++){
    this->numeSala = new char[strlen(obj.numeSala) + 1];
    strcpy(this->numeSala, obj.numeSala);
    this->tipAntrenament = obj.tipAntrenament;
    this->culoareCentura = obj.culoareCentura;
    this->nrAni = obj.nrAni;
    this->gradCentura = new float[obj.nrAni];
    for(int i = 0; i < obj.nrAni; i++)
        this->gradCentura[i] = obj.gradCentura[i];  /// Pentru a avea o zona de memorie diferita
    this->sensei = obj.sensei;
}

Karateka& Karateka::operator = (const Karateka& obj){
    if(this != &obj){
        if(this->numeSala != NULL){
        delete[] this->numeSala;
        this->numeSala = NULL;
        }

        if(this->gradCentura != NULL){
            delete[] this->gradCentura;
            gradCentura = NULL;
        }

        this->numeSala = new char[strlen(obj.numeSala) + 1];
        strcpy(this->numeSala, obj.numeSala);
        this->tipAntrenament = obj.tipAntrenament;
        this->culoareCentura = obj.culoareCentura;
        this->nrAni = obj.nrAni;
        this->gradCentura = new float[obj.nrAni];
        for(int i = 0; i < obj.nrAni; i++)
            this->gradCentura[i] = obj.gradCentura[i];  /// Pentru a avea o zona de memorie diferita
        this->sensei = obj.sensei;
    }
    return *this;
}

/*
Karateka& Karateka::operator++() {
    this->++;
    return *this;

}*/

Karateka Karateka::operator++ (int){
    Karateka aux(*this);
    ///this->++;
    ++*this;
    return aux;
}

Karateka Karateka::operator+ (const Karateka& obj){
    Karateka aux(*this);
    aux.tipAntrenament += obj.tipAntrenament;
    return aux;

}

/*
Karateka Karateka::operator+(int x){
    Karateka aux(*this);
    aux. += x;
    return aux;
}*/

Karateka operator+(int x, Karateka obj){
    return obj+x;
}

bool Karateka::operator==(const Karateka& obj){
    return this->tipAntrenament == obj.tipAntrenament;
}

float Karateka::operator[](int i){
    if(this->gradCentura == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > this->nrAni) {
        throw runtime_error("Index invalid");
    }
    else
        return this->gradCentura[i];

}
/*
Karateka::operator int(){
    return this->;
}*/

void Karateka::afisare(){
    cout << "ID: " << this->idSala << endl;
    cout << "Nume: " << this->numeSala << endl;
    cout << "Tip antrenament: " << this->tipAntrenament << endl;
    cout << "culoareCentura: " << this->culoareCentura << endl;
    cout << "Nr luni: " << this->nrAni << endl;
    cout << "Grad centura: ";
    for(int i = 0; i < this->nrAni; i++)
        cout << this->gradCentura[i] << " ";
    cout << endl;
    cout << "sensei: " << this->sensei << endl;
}

void afisare2(const Karateka& obj){
    cout << "ID: " << obj.idSala << endl;
    cout << "Nume: " << obj.numeSala << endl;
    cout << "Tip antrenament: " << obj.tipAntrenament << endl;
    cout << "Culoarea centurii: " << obj.culoareCentura << endl;
    cout << "Nr ani experienta: " << obj.nrAni << endl;
    cout << "Grad centura: ";
    for(int i = 0; i < obj.nrAni; i++)
        cout << obj.gradCentura[i] << " ";
    cout << endl;
    cout << "sensei: " << obj.sensei << endl;
}

void Karateka::citire(){
    cout << "Introduceti numele stupului: " << endl;
    char numeSala[100];
    cin >> numeSala;
    if(this->numeSala != NULL){
        delete this->numeSala;
        this->numeSala = NULL;
    }
    this->numeSala = new char[strlen(numeSala) + 1];
    strcpy(this->numeSala, numeSala);

    cout << "Introduceti tipil de antrenament: " << endl;
    cin >> this->tipAntrenament;

    cout << "Introduceti culoarea centurii: " << endl;
    cin >> this->culoareCentura;

    cout << "Introduceti numarul de ani de experienta: " << endl;
    cin >> this->nrAni;

    cout << "Introduceti grdul centurii: " << endl;
    if(this->gradCentura != NULL){
        delete[] this->gradCentura;
        this->gradCentura = NULL;
    }

    this->gradCentura = new float[this->nrAni];
    for(int i = 0; i < this->nrAni; i++)
        cin >> this->gradCentura[i];

    cout << "Introduceti sensei: " << endl;
    cin >> this->sensei;
}

ostream& operator <<(ostream& out, const Karateka& obj){
    out << "ID: " << obj.idSala << endl;
    out << "Nume: " << obj.numeSala << endl;
    out << "Tip antrenament: " << obj.tipAntrenament << endl;
    out << "Culoare centura: " << obj.culoareCentura << endl;
    out << "Nr luni: " << obj.nrAni << endl;
    out << "Cantitate: ";
    for(int i = 0; i < obj.nrAni; i++)
        out << obj.gradCentura[i] << " ";
    out << endl;
    out << "sensei: " << obj.sensei << endl;
    return out;
}

istream& operator >>(istream& in, Karateka& obj){
    cout << "Introduceti numele salii: " << endl;
    char numeSala[100];
    in >> numeSala;
    if(obj.numeSala != NULL){
        delete obj.numeSala;
        obj.numeSala = NULL;
    }
    obj.numeSala = new char[strlen(numeSala) + 1];
    strcpy(obj.numeSala, numeSala);

    cout << "Introduceti tipul de antrenament: " << endl;
    in >> obj.tipAntrenament;

    cout << "Introduceti culoarea centurii: " << endl;
    in >> obj.culoareCentura;

    cout << "Introduceti numarul de ani de expereinta: " << endl;
    in >> obj.nrAni;

    cout << "Introduceti culoarea centurii: " << endl;
    if(obj.gradCentura != NULL){
        delete[] obj.gradCentura;
        obj.gradCentura = NULL;
    }

    obj.gradCentura = new float[obj.nrAni];
    for(int i = 0; i < obj.nrAni; i++)
        in >> obj.gradCentura[i];

    cout << "Introduceti sensei: " << endl;
    in >> obj.sensei;
    return in;
}

Karateka::~Karateka(){
    if(this->numeSala != NULL){
        delete[] this->numeSala;
        this->numeSala = NULL;
    }

    if(this->gradCentura != NULL){
        delete[] this->gradCentura;
        gradCentura = NULL;
    }
}

int main()
{
    Karateka a;
    char numeSala[]={"Aiko "};
    float n=1.2, n2=1.3, n3=1.5;
    float gradCentura[]={n,n2,n3};
    Karateka a2(numeSala,"Concordia Chiajna ", 'galben', 3, gradCentura, true);
    cout<<a2.getTipAntrenament();
    cout<<a.getTipAntrenament();
    Karateka a3(a2), a4=a2;
    cout<<a3.getTipAntrenament();
    cout<<a4.getTipAntrenament();
    return 0;

    /*
    //cout << (int)a2 << endl;

    //cout<<a[2]<<endl;

    //cout << a2.getTipAntrenament() << endl;

    Karateka a3(a2);
    Karateka a4 = a2;  // Tot copy constructor

    //cout << a3.getTipAntrenament() << endl;

    //cout << Karateka::getContorId(); // 1004, avem 4 stupi

    a = a4;
    cout << a.getTipAntrenament() << endl;

    //a4.afisare();
    //a4.citire();
    //a4.afisare();
    //cin >> a4;
    //cout << a4;

    for(int i = 0; i < a4.getnrAni(); i++)
        cout << a4.getCantitateMiere()[i] << ' ';
        */

    return 0;
}
