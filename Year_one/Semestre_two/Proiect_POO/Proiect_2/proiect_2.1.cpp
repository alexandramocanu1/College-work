#include <iostream>
#include <string>

using namespace std;

///Sa se exemplifice conceptulde virtualizare
//Proiectul sa contina minim o clasa abstracta/interfata
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
    Person() {
        name = "";
        age = 0;
    }

    Person(const string&, int);
    Person(const Person& p);

    virtual ~Person() {}

    Person& operator =(const Person&);
    friend istream& operator >>(istream&, Person&);
    friend ostream& operator <<(ostream&, const Person&);

    int getAge() const {return this->age;}

    virtual istream& read(istream&) {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        return cin;
    }

    virtual ostream& print(ostream& out) const {
        out << "Name: " << name << ", Age: " << age << std::endl;
        return out;
    }
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


class Karateka : virtual public Person {
protected:
    int belt_level;
    int experience_years;
    string belt_color;

public:
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
        experience_years = years;
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
        out << "Nume dojou: " << teaching << endl;
        return out;
    }

};

/*
int main() {
    Person* person1 = new Person;
    Person person;
    Karateka karateka;
    Coach coach;
    Sensei sensei;

    cout<<person1<<endl;

    int choice = -1;
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
            case 1:
                karateka.read(cin);
                break;
            case 2:
                karateka.print(cout);
                break;
            case 3:
                sensei.read(cin);
                break;
            case 4:
                sensei.print(cout);
                break;
            case 5:
            {
                Karateka k;
                cin >> k;
                cout << "Belt color: " << k.getBeltColor() << endl;
                break;
            }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
*/


int main() {
    Person* person1 = nullptr;

    int choice = -1;
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
            case 1:
                delete person1;  // Ștergem obiectul anterior (dacă există)
                person1 = new Karateka;  // Creăm un obiect de tip Karateka
                person1->read(cin);  // Apelăm metoda read() specifică obiectului de tip Karateka
                break;
            case 2:
                if (person1 != nullptr) {
                    person1->print(cout);  // Apelăm metoda print() specifică obiectului referit de person1
                } else {
                    cout << "No karateka information available." << endl;
                }
                break;
            case 3:
                // Citire informații Sensei
                break;
            case 4:
                // Afișare informații Sensei
                break;
            case 5:
                {
                    Karateka k;
                    cin >> k;
                    cout << "Belt color: " << k.getBeltColor() << endl;
                    break;
                }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }

    delete person1;  // Eliberăm memoria ocupată de obiectul person1 înainte de încheierea programului

    return 0;
}
