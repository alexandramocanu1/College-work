#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <windows.h>


using namespace std;

class Karateka; // forward declaration
class Person;

vector<Karateka> karatekas; // vector de karateka
set<string> names; // set de nume
list<Person*> persons; // lista de persoane
map<string, Karateka> karatekaMap; // map de karateka cu cheie de tip string



///Sa se exemplifice conceptul de virtualizare
///Proiectul sa contina minim o clasa abstracta/interfata
class IOinterface{
public:
    ///metode virtuale pure
    virtual istream& read(istream&) = 0;
    virtual ostream& print(ostream&) const = 0;

    virtual ~IOinterface() {}
};

///Sa se exemplifice conceptul de mostenire pentru  minim 3 clase alese
class Person : virtual public IOinterface {

protected:
    string name;
    int age;

public:

    ///constructor fara parametrii
    Person() {
        name = "";
        age = 0;
    }

    ///constructor cu parametrii
    Person(const string&, int);
    Person(const Person& p);

    ///destructor
    virtual ~Person() {}

    Person& operator =(const Person&);
    friend istream& operator >>(istream&, Person&);
    friend ostream& operator <<(ostream&, const Person&);

    void setName(string n){name = n;}

    int getAge() const {return this->age;}
    string getName() const { return this->name;}

    virtual istream& read(istream&);
    virtual ostream& print(ostream&) const;

};

Person::Person(const string& name, int age) {
        this->name = name;
        this->age = age;
    }

    ///copy constructor
Person::Person(const Person& obj) {
        this->name = obj.name;
        this->age = obj.age;
    }


    ///operator =
Person& Person::operator=(const Person& obj) {
        this->name = obj.name;
        this->age = obj.age;
        return *this;
    }

istream& operator >>(istream& in, Person& obj){
    cout << "Introduceti numele\n";
    in >> obj.name;
    cout << "Introduceti varsta\n";
    in >> obj.age;
    return in;
}

ostream& operator <<(ostream& os, const Person& obj){
    os << "Nume: " << obj.name << endl;
    os << "Varsta: " << obj.age << endl;
    return os;
}
/// try/catch 1 si 2 diferite
istream& Person::read(istream& in) {
    try {
        cout << "Enter name: ";
        in >> name;
        if (name.empty()) {
            throw invalid_argument("Name cannot be empty!");
        }
        cout << "Enter age: ";
        in >> age;
        if (age < 0 || age > 120) {
            throw out_of_range("Age must be between 0 and 120!");
        }
    } catch (const exception& e) {
        cout << "Eroare: " << e.what() << endl;
        // Acțiuni specifice pentru tratarea excepțiilor
    } catch (...) {
        cout << "Eroare necunoscută!" << endl;
    }
    return in;
}


ostream& Person::print(ostream& out) const {
    out << "Name: " << name << ", Age: " << age << std::endl;
    return out;
}


class Karateka : virtual public Person {
protected:
    int belt_level;
    int experience_years;
    string belt_color;

public:

    string getName() const {
    return this->name;
}

virtual void setName(string n) { Person::setName(n); }


    void writeToFile(ofstream& ofs) const {
        ofs.write(reinterpret_cast<const char*>(this), sizeof(Karateka));
    }

    void readFromFile(ifstream& ifs) {
        ifs.read(reinterpret_cast<char*>(this), sizeof(Karateka));
    }


    Karateka() : Person() {
        belt_level = 0;
        experience_years = 0;
        belt_color = "unknown";
    }

    Karateka(const string& name, int age, int belt_level, int experience_years) : Person(name, age) {
        this->belt_level = belt_level;
        this->experience_years = experience_years;
        this->belt_color = getBeltColor();
    }

    Karateka(const Karateka& obj) : Person(obj) {
        this->belt_level = obj.belt_level;
        this->experience_years = obj.experience_years;
        this->belt_color = obj.belt_color;
    }

    Karateka& operator=(const Karateka& obj) {
        Person::operator=(obj);
        this->belt_level = obj.belt_level;
        this->experience_years = obj.experience_years;
        this->belt_color = obj.belt_color;
        return *this;
    }

    virtual ~Karateka() {}

 /*   virtual void read() {
        Person::read();
        cout << "Enter belt level: ";
        cin >> belt_level;
        cout << "Enter years of experience: ";
        cin >> experience_years;
        this->belt_color = getBeltColor();
    }

    virtual void print() const {
        Person::print();
        cout << "Belt level: " << belt_level << ", Belt color: " << belt_color << ", Years of experience: " << experience_years << std::endl;
    }*/

    void setExperienceYears(int years) {
    try {
        if (years < 0) {
            throw invalid_argument("Anii de experienta nu pot fi negativi!");
        }
        experience_years = years;
    } catch(const exception& e) {
        cerr << "Eroare: " << e.what() << endl;
        exit(1);
    }
}
/// try/catch 3
    void setBeltLevel(int beltLevel) {
    try {
        if (beltLevel < 0) {
            throw out_of_range("Nivelul curelei nu poate fi negativ!");
        }
        this->belt_level = beltLevel;
        this->belt_color = getBeltColor();
    } catch(const exception& e) {
        cerr << "Eroare: " << e.what() << endl;
        exit(1);
    }
}


    int getExperienceYears() const {
        return experience_years;
    }

    int getBeltLevel() const {
    int belt_level = (this->getExperienceYears() - 9)/2;
    return belt_level;
}

string getBeltColor() {
    int belt_level = getBeltLevel();
    string color;
    if(experience_years < 10)
    switch(belt_level) {
        case 9: color = "white"; break;
        case 8: color = "yellow"; break;
        case 7: color = "orange"; break;
        case 6: color = "green"; break;
        case 5: color = "blue"; break;
        case 4: color = "blue"; break;
        case 3: color = "brown"; break;
        case 2: color = "brown"; break;
        case 1: color = "brown"; break;
        default: color = "unknown"; break;
    }

    else color = "black";
    return color;
}

    istream& read(istream& in) override {
        Person::read(in);
        cout << "Enter belt level: ";
        cin >> belt_level;
        cout << "Enter years of experience: ";
        cin >> experience_years;
        this->belt_color = getBeltColor();
        return in;
    }

    ostream& print(ostream& out) const override {
        Person::print(out);
        out << "Belt level: " << belt_level << ", Belt color: " << belt_color << ", Years of experience: " << experience_years << std::endl;
        return out;
    }

};


void addKarateka() {
    Karateka karateka;
    cin >> static_cast<Person&>(karateka);

    int beltLevel, experienceYears;
    cout << "Enter belt level: ";
    cin >> beltLevel;
    karateka.setBeltLevel(beltLevel);

    cout << "Enter years of experience: ";
    cin >> experienceYears;
    karateka.setExperienceYears(experienceYears);

    if (names.count(karateka.getName()) == 0) {
        karatekas.push_back(karateka);
        names.insert(karateka.getName());
        persons.push_back(&karatekas.back());
        karatekaMap.insert({ karateka.getName(), karateka });
        cout << "Karateka added successfully!" << endl;
    } else {
        cout << "Karateka with the same name already exists!" << endl;
    }
}


void removeKarateka() {
    string name;
    cout << "Enter the name of the karateka to remove: ";
    cin >> name;
    if (names.count(name) != 0) {
        names.erase(name);
        for (auto it = karatekas.begin(); it != karatekas.end(); ++it) {
            if (it->getName() == name) {
                karatekas.erase(it);
                break;
            }
        }
        for (auto it = persons.begin(); it != persons.end(); ++it) {
            if ((*it)->getName() == name) {
                persons.erase(it);
                break;
            }
        }
        karatekaMap.erase(name);
        cout << "Karateka removed successfully!" << endl;
    } else {
        cout << "Karateka with the given name does not exist!" << endl;
    }
}

void displayKaratekas() {
    cout << "Karatekas:" << endl;
    for (auto& karateka : karatekas) {
        karateka.print(cout);
        cout << "Belt color: " << karateka.getBeltColor() << endl;
        cout << endl;
    }
}

/*
void writeToFile(const vector<Karateka>& karatekas, const string& filename) {
    ofstream ofs(filename, ios::binary | ios::trunc);
    for (const auto& karateka : karatekas) {
        karateka.writeToFile(ofs);
    }
    ofs.close();
}

void readFromFile(vector<Karateka>& karatekas, const string& filename) {
    ifstream ifs(filename, ios::binary);
    Karateka karateka;
    while (ifs.read(reinterpret_cast<char*>(&karateka), sizeof(Karateka))) {
        karatekas.push_back(karateka);
    }
    ifs.close();
}
*/

void writeToFile(const vector<Karateka>& karatekas, const string& filename) {
    ofstream ofs(filename, ios::binary | ios::trunc);
    if (!ofs) {
        cerr << "Eroare la deschiderea fisierului pentru scriere!" << endl;
        return;
    }
    for (const auto& karateka : karatekas) {
        karateka.writeToFile(ofs);
    }
    ofs.close();
}

void readFromFile(vector<Karateka>& karatekas, const string& filename) {
    ifstream ifs(filename, ios::binary);
    if (!ifs) {
        cerr << "Eroare la deschiderea fisierului pentru citire!" << endl;
        return;
    }
    Karateka karateka;
    while (ifs.read(reinterpret_cast<char*>(&karateka), sizeof(Karateka))) {
        karatekas.push_back(karateka);
    }
    ifs.close();
}



class Coach : virtual public Person {
protected:
    int yearsCoaching;
    string diploma;

public:
    Coach() : Person(), yearsCoaching(0), diploma("unknown") {}

    Coach(const string& name, int age, int yearsCoaching, const string& diploma) : Person(name, age), yearsCoaching(yearsCoaching), diploma(diploma) {}

    Coach(const Coach& c) : Person(c), yearsCoaching(c.yearsCoaching), diploma(c.diploma) {}

    Coach& operator=(const Coach& c) {
        Person::operator=(c);
        this->yearsCoaching = c.yearsCoaching;
        this->diploma = c.diploma;
        return *this;
    }

    virtual ~Coach() {}

    int getYearsCoaching() const {
        return yearsCoaching;
    }

    void setYearsCoaching(int years) {
        yearsCoaching = years;
    }

    string getDiploma() const {
        return diploma;
    }

    void setDiploma(const string& diploma) {
        this->diploma = diploma;
    }

    friend istream& operator >>(istream&, Coach&);
    friend ostream& operator <<(ostream&, const Coach&);\

    istream& read(istream& in) override {
        Person::read(in);
        cout << "Enter years of coaching: ";
        cin >> yearsCoaching;
        cout << "Enter diploma: ";
        cin >> diploma;
        return in;
    }

    ostream& print(ostream& out) const override {
        Person::print(out);
        out << "Years of coaching: " << yearsCoaching << ", Diploma: " << diploma << std::endl;
        return out;
    }
};

istream& operator >>(istream& in, Coach& obj){
    cout << "Introduceti numarul anilor de experienta\n";
    in >> obj.yearsCoaching;
    cout << "Introduceti denumirea diplomei\n";
    in >> obj.diploma;
    return in;
}

ostream& operator <<(ostream& os, const Coach& obj){
    os << "Ani de experienta ca antrenor: " << obj.yearsCoaching << endl;
    os << "Diploma: " << obj.diploma << endl;
    return os;
}


class Sensei : public Coach, public Karateka {
protected:
    string teaching;

public:
    Sensei() : Person(), Coach(), Karateka(), teaching("unknown") {}

    Sensei(const string& name, int age, int belt_level, int experience_years, int yearsCoaching, const string& diploma) : Person(name, age), Coach(name, age, yearsCoaching, diploma), Karateka(name, age, belt_level, experience_years) {
        int total_experience = getExperienceYears() + yearsCoaching;
        if (total_experience < 5) {
            teaching = "beginners";
        } else if (total_experience >= 5 && total_experience < 10) {
            teaching = "intermediate";
        } else {
            teaching = "advanced";
        }
    }

    Sensei(const Sensei& s) : Person(s), Coach(s), Karateka(s), teaching(s.teaching) {}

    Sensei& operator=(const Sensei& s) {
        Person::operator=(s);
        Coach::operator=(s);
        Karateka::operator=(s);
        this->teaching = s.teaching;
        return *this;
    }

    virtual ~Sensei() {}

    /*
    virtual void read() {
        Person::read();
        Coach::read();
        Karateka::read();
        int total_experience = getExperienceYears() + yearsCoaching;
        if (total_experience < 5) {
            teaching = "beginners";
        } else if (total_experience >= 5 && total_experience < 10) {
            teaching = "intermediate";
        } else {
            teaching = "advanced";
        }
    }

    virtual void print() const{
        Person::print();
        cout << "Belt level: " << getBeltLevel() << ", Belt color: " << getBeltColor() << ", Years of experience: " << getExperienceYears() << std::endl;
        cout << "Years of coaching experience: " << yearsCoaching << ", Diploma: " << diploma << std::endl;
        cout << "Teaching: " << teaching << std::endl;
    }*/

    virtual istream& read(istream& in) {
        Person::read(in);
        Karateka::read(in);
        Coach::read(in);
        cout << "Introduceti numele dojoului:\n";
        in >> teaching;
        return in;
    }

    virtual ostream& print(ostream& out) const {
        Person::print(out);
        Karateka::print(out);
        Coach::print(out);
        out << "Nume dojo: " << teaching << endl;
        return out;
    }

};


///Clasa template
template <typename T>
class KaratekaMapSorter {
public:
    KaratekaMapSorter(std::map<std::string, T>& map, int& sort)
        : karatekaMap(map), sorter(sort) {}
    KaratekaMapSorter(const map<string, T>& karatekaMap) : karatekaMap(karatekaMap) {}

    template<typename Compare>
    void sortBy(Compare comp) {
        vector<pair<string, T>> sortedKaratekas(karatekaMap.begin(), karatekaMap.end());
        sort(sortedKaratekas.begin(), sortedKaratekas.end(), comp);

        for (const auto& karateka : sortedKaratekas) {
            cout << "Name: " << karateka.first << ", Belt level: " << karateka.second << endl;
        }
    }

private:
    std::map<std::string, T>& karatekaMap;
    int& sorter;
    //map<string, T> karatekaMap;
};


class Menu {
private:
    static Menu* instance;

    Menu() {}

public:
    static Menu* getInstance() {
        if (instance == nullptr) {
            instance = new Menu();
        }
        return instance;
    }

    void display() {
        cout << "Menu options:" << endl;
        cout << "1. Add karateka" << endl;
        cout << "2. Remove karateka" << endl;
        cout << "3. Display karatekas" << endl;
        cout << "4. Import data" << endl;
        cout << "5. Export data" << endl;
        //cout << "6. Perform application functionality" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
    }
};

/// Inițializarea instanței statice a clasei Menu
Menu* Menu::instance = nullptr;


int main() {

/*
     Person* person = new Karateka("John", 25, 5, 3);
    Karateka* karateka = dynamic_cast<Karateka*>(person);

    if (karateka) {
        cout << "Person successfully casted to Karateka." << endl;
        // Acum putem accesa metodele și membrii specifici clasei Karateka
        karateka->setExperienceYears(6);
        karateka->setBeltLevel();
        cout << *karateka << endl;
    } else {
        cout << "Failed to cast Person to Karateka." << endl;
    }

    Karateka* karateka2 = new Karateka("Alice", 30, 7, 4);
    Person* person2 = dynamic_cast<Person*>(karateka2);

    if (person2) {
        cout << "Karateka successfully casted to Person." << endl;
        // Acum putem accesa metodele și membrii specifici clasei Person
        person2->setName("Alice Smith");
        cout << *person2 << endl;
    } else {
        cout << "Failed to cast Karateka to Person." << endl;
    }

    delete person;
    delete karateka2;
*/

    Menu* menu = Menu::getInstance();
    int option;

    do {
        menu->display();
        cin >> option;

        switch (option) {
            case 1:
                addKarateka();
                break;
            case 2:
                removeKarateka();
                break;
            case 3:
                displayKaratekas();
                break;
            case 4:
                writeToFile(karatekas, "karatekas.bin");
                cout << "Date importate!\n";
                break;
            case 5:
                readFromFile(karatekas, "karatekas.bin");
                cout << "Date exportate!\n";
                break;
            case 0:
                cout << "Programul se închide..." << endl;
                break;
            default:
                cout << "Opțiune invalidă! Vă rugăm să încercați din nou." << endl;
                break;
        }
    } while (option != 0);

    return 0;
}


/*
int main() {
/// try/catch 4
try {
        ifstream input_file("karateka.bin");
        if (!input_file) {
            throw runtime_error("Nu s-a putut deschide fisierul de intrare!");
        }


        ifstream ifs("karateka.bin", ios::binary);
    Karateka karateka;
    while (ifs) {
        karateka.readFromFile(ifs);
        if (ifs) {
            karatekas.push_back(karateka);
        }
    }
    ifs.close();


    int choice = -1;
    map<string, Karateka> karatekaMap;
    int option = 0;

    //KaratekaMapSorter sorter(karatekaMap, option);

    while (choice != 0) {
        cout << "Menu:" << endl;
        cout << "1. Read a karateka's information" << endl;
        cout << "2. Print all karateka information" << endl;
        cout << "3. Read Sensei information" << endl;
        cout << "4. Print Sensei information" << endl;
        cout << "5. Find belt color based on experience years" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Karateka karateka;
                karateka.read(cin);
                karatekas.push_back(karateka);
                names.insert(karateka.getName());
                persons.push_back(&karateka);
                karatekaMap.insert({karateka.getName(), karateka});
                break;
            }
            case 2: {
            cout << "Select the order (0 - by name, 1 - by belt level): ";
            int order;
            cin >> order;

            KaratekaMapSorter<Karateka> sortBy(karatekaMap, order);
            //sortBy.sortBy(karatekaMap);

            for (const auto& pair : karatekaMap) {
                cout << pair.first << ": " << pair.second.getName() << endl;
            }
            break;
        }
            case 3: {
                Sensei sensei;
                sensei.read(cin);
                karatekas.push_back(sensei);
                names.insert(sensei.getName());
                persons.push_back(&sensei);
                karatekaMap.insert({sensei.getName(), sensei});
                break;
            }
            case 4: {
                cout << "Sensei information:" << endl;
                for (const auto& person : persons) {
                    Sensei* sensei = dynamic_cast<Sensei*>(person);
                    if (sensei) {
                        sensei->print(cout);
                    }
                }
                break;
            }
            case 5: {
                string name;
                cout << "Enter the name of the karateka: ";
                cin >> name;
                auto it = karatekaMap.find(name);
                if (it != karatekaMap.end()) {
                    Karateka karateka = it->second;
                    cout << "Belt color for " << name << " is " << karateka.getBeltColor() << endl;
                } else {
                    cout << "Karateka not found!" << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }
} catch(const exception& e) {
        cerr << "Eroare: " << e.what() << endl;
        exit(1);
    }
    return 0;
}
*/

