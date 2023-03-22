#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <windows.h>

using namespace std;

class Student {

    private:
        static int contorId;
        const int student_id;
        string name;
        int age;
        float weight;
        double beltLevel;

    public:

        double promote(int n) const {
            return beltLevel + n;
        }

        double demote() const {
            return beltLevel - 0.5;
        }

        /// Constructors
        Student(); //fara parametrii

        Student(const Student& obj);   // Copy constructor

       /* Student(string n, int a, float* w) {  // Constructor parametrizat
            name = n;
            age = a;
            weight = w;
        }*/

        Student(string name, int age, float weight);


        /// Getters and Setters
      /*  void setStudentID(int id) {
            student_id = id;
        }
        */

        int getStudentID() const {
            return student_id;
        }

        void setName(string n) {
            name = n;
        }

        string getName() const {
            return name;
        }

        void setAge(int a) {
            age = a;
        }

        int getAge() const {
            return age;
        }

        void setWeight(float w) {
            weight = w;
        }

        const float getWeight() const{
            return this->weight;
        }

        double getBeltLevel() const {
            return beltLevel;
            }


         int setBeltLevel() const {
            return beltLevel;
        }


        /// Destructor
        ~Student() {};


        /// Operatori
        float operator[](int);
        Student& operator++();
        Student operator++(int);
        Student operator+(const Student& obj);
        Student operator+(int);
        friend Student operator+(int, Student obj);
        Student& operator = (const Student&);
        friend ostream& operator <<(ostream& out, const Student& obj);
        friend istream& operator >>(istream& in, Student& obj);
        operator int();
        operator int() const {return this->age;}
        bool operator==(const Student&);

        ///Metode
        void afisare();
        void citire();
};


int Student::contorId = 1000;

Student::Student(): student_id(contorId++) {
name = "Anonim";
age = 0;
weight = 0;
beltLevel = 0.0;
}

Student::Student(string name, int age, float weight): student_id(contorId++) {
this->name = name;
this->age = age;
this->weight = weight;
}

Student::Student(const Student& obj): student_id(contorId++){
this->name = obj.name;
this->age = obj.age;
this->weight = obj.weight;
}

Student& Student::operator++() {
    this->age++;
    return *this;
}

Student Student::operator++(int){
    Student aux(*this);
    this->age++;
    return aux;
}

Student Student::operator+ (const Student& obj){
    Student aux(*this);
    aux.age += obj.age;
    return aux;
}

Student Student::operator+(int x){
    Student aux(*this);
    aux.age += x;
    return aux;
}

Student operator+(int x, Student obj){
    return obj+x;
}

bool Student::operator==(const Student& obj){
    return this->name == obj.name;
}

float Student::operator[](int i){
    if(this->weight == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > this->age) {
        throw runtime_error("Index invalid");
    }
    else
        return this->weight;
}

Student::operator int(){
    return this->age;
}

Student& Student::operator = (const Student& obj){

        this->name = obj.name;
        this->weight = obj.weight;

    return *this;
}

ostream& operator<<(ostream& out, const Student& obj) {
            out << "Name: " << obj.name << endl;
            out << "Age: " << obj.age << endl;
            out << "Weight: " << obj.weight << endl;

            return out;
}

istream& operator>>(istream& in, Student& obj) {
            cout << "Introduce the student's name: " << endl;
            in >> obj.name;

            cout << "Introduce the student's age: " << endl;
            in >> obj.age;

            cout << "Introduce the student's weight: " << endl;
            in >> obj.weight;

            return in;
}


class Instructor {

    private:
        string name;
        int age;
        char* style;
        float experienceYears;

    public:

        /// Constructors
        Instructor() : name(""), age(0), style(NULL), experienceYears(0.0) {}
        Instructor(const string& name, int age, const char* style, float experienceYears) : name(name), age(age), experienceYears(experienceYears) {

            if (style != nullptr)
            {
                this->style = new char[strlen(style) + 1];
                strcpy(this->style, style);
            }
            else
            {
                this->style = nullptr;
            }
        }

        Instructor(const Instructor& i) : name(i.name), age(i.age), experienceYears(i.experienceYears) {

            if (i.style != nullptr)
            {
                style = new char[strlen(i.style) + 1];
                strcpy(style, i.style);
            }
            else {
                style = nullptr;
            }
        }

        /// Destructor
        ~Instructor() {};


        /// Getters and Setters
        string getName() const {
            return name;
        }

        int getAge() const {
            return age;
        }

        const char* getStyle() const {
            return style;
        }

        float getExperienceYears() const {
            return experienceYears;
        }

        void setName(const string& name) {
            this->name = name;
        }

        void setAge(int age) {
            this->age = age;
        }

        void setStyle(const char* style) {
            delete[] this->style;

            if (style != nullptr)
            {
                this->style = new char[strlen(style) + 1];
                strcpy(this->style, style);
            }
            else
            {
                this->style = nullptr;
            }
        }

        void setExperienceYears(float experienceYears) {
            this->experienceYears = experienceYears;
        }


        /// Functionality
        void printInstructor() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Style: " << style << endl;
            cout << "Experience years: " << experienceYears << endl;
        }

        ///Operatori
        Instructor& operator = (const Instructor&);
        Instructor& operator++();
        Instructor operator++ (int);
        Instructor& operator+(const Instructor& obj);
        Instructor operator+();
        Instructor operator+(int);
        friend Instructor operator+(int, Instructor obj);
        bool operator==(const Instructor&);
        int operator[](int);
        operator int();
        operator int() const {return this->age;}
};

Instructor& Instructor::operator = (const Instructor& obj){

    if(this != &obj){
        if(this->style != NULL){
        delete[] this->style;
        this->style = NULL;
        }

        this->style = new char[strlen(obj.style) + 1];
        strcpy(this->style, obj.style);
        this->name = obj.name;
        this->age = obj.age;
        this->experienceYears = obj.experienceYears;
        this->age = obj.age;
    }
    return *this;

}

Instructor& Instructor::operator+(const Instructor& obj){
    Instructor aux(*this);
    aux.age += obj.age;
    return aux;
}

Instructor Instructor::operator+(int x){
    Instructor aux(*this);
    aux.age += x;
    return aux;
}

Instructor& Instructor::operator++() {
    this->experienceYears++;
    return *this;
}

Instructor Instructor::operator++(int){
    Instructor aux(*this);
    this->age++;
    return aux;
}


Instructor operator+(int x, Instructor obj){
    return obj+x;
}

bool Instructor::operator==(const Instructor& obj){
    return this->name == obj.name;
}

/*
int operator[](int i)
    {
        if (i < 0 || i >= this->age)
            throw runtime_error("index_invalid");
        return this->experienceYears[i];
    }
*/

Instructor::operator int(){
    return this->age;
}


class KarateClass {

    private:
        static int contorId;
        Student* students;
        int num_students;
        string instructor;
        char class_id;

    public:

        /// Constructors
        KarateClass() {
            students = nullptr;
            num_students = 0;
            instructor = "";
        }

        KarateClass(Student* s, int num, string i) {
            students = s;
            num_students = num;
            instructor = i;
        }

        /// Getters and Setters
        static int getContorId() {return KarateClass::contorId;}

        void setStudents(Student* s) {
            students = s;
        }

        Student* getStudents() {
            return students;
        }

        void setNumStudents(int num) {
            num_students = num;
        }

        int getNumStudents() {
            return num_students;
        }

        void setInstructor(string i) {
            instructor = i;
        }

        string getInstructor() {
            return instructor;
        }


        /// Add a new student to the class
        void addStudent(Student s) {
            Student* new_students = new Student[num_students + 1];

            for (int i = 0; i < num_students; i++)
            {
                new_students[i] = students[i];
            }

            new_students[num_students] = s;

            num_students++;

            delete[] students;
            students = new_students;
        }


        /// Remove a student from the class
        void removeStudent(int student_id) {
            int index = -1;
            for (int i = 0; i < num_students; i++)
            {
                if (students[i].getStudentID() == student_id)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Error: student with ID " << student_id << " not found." << endl;
                return;
            }

            for (int i = index; i < num_students - 1; i++)
            {
                students[i] = students[i + 1];
            }

            num_students--;


            num_students--;
            cout << "Student with ID " << student_id << " has been removed." << endl;
        };


        ///Operatori
        KarateClass& operator = (const KarateClass&);
        friend ostream& operator <<(ostream& out, const KarateClass& obj);
        friend istream& operator >>(istream& in, KarateClass& obj);
        KarateClass& operator++();
        KarateClass operator++ (int);
        KarateClass& operator--();
        KarateClass operator--(int);
        KarateClass operator+(const KarateClass& obj);
        KarateClass operator+(int);
        friend KarateClass operator+(int, KarateClass obj);
        bool operator==(const KarateClass&);
        float operator[](int) const;
        operator int();
        operator int() const {return this->num_students;}

};

KarateClass::operator int() {
    return num_students;
}


float KarateClass::operator[](int index) const {
    if (index < 0 || index >= num_students) {
        cout << "Error: invalid index" << endl;
        return -1.0f;
    }
    return students[index].getBeltLevel();
}


KarateClass KarateClass::operator+(const KarateClass& obj) {
    Student* new_students = new Student[num_students + obj.num_students];

    for (int i = 0; i < num_students; i++) {
        new_students[i] = students[i];
    }

    for (int i = 0; i < obj.num_students; i++) {
        new_students[num_students + i] = obj.students[i];
    }

    KarateClass result(new_students, num_students + obj.num_students, instructor);

    delete[] new_students;

    return result;
}

KarateClass KarateClass::operator+(int n) {
    KarateClass copy(*this);

    for (int i = 0; i < num_students; i++) {
        copy.students[i].promote(n);
    }

    return copy;
}


KarateClass operator+(int n, KarateClass obj) {
    return obj + n;
}


KarateClass& KarateClass::operator++() {
    int n;
    for (int i = 0; i < num_students; i++) {

        students[i].promote(n);
    n++;
    }
    return *this;
}


KarateClass KarateClass::operator++(int) {
    KarateClass copy(*this);
    ++(*this);
    return copy;
}


KarateClass& KarateClass::operator--() {
    for (int i = 0; i < num_students; i++) {
        students[i].demote();
    }
    return *this;
}


KarateClass KarateClass::operator--(int) {
    KarateClass copy(*this);
    --(*this);
    return copy;
}

/*
bool operator<(const KarateClass& obj) {
    return this->num_students < obj.num_students;
}
*/

/*
/// Add a new student to the class
void KarateClass::addStudent(Student s) {

    Student* new_students = new Student[num_students + 1];

    for (int i = 0; i < num_students; i++)
    {
        new_students[i] = students[i];
    }

    new_students[num_students] = s;

    num_students++;

    delete[] students;
    students = new_students;
}


/// Remove a student from the class
void removeStudent(int student_id) {
    int index = -1;
    for (int i = 0; i < num_students; i++)
        {
            if (students[i].getStudentID() == student_id)
            {
                index = i;
                break;
            }
        }

            if (index == -1)
            {
                cout << "Error: student with ID " << student_id << " not found." << endl;
                return;
            }

            for (int i = index; i < num_students - 1; i++)
            {
                students[i] = students[i + 1];
            }

            num_students--;


            num_students--;
            cout << "Student with ID " << student_id << " has been removed." << endl;
    };
*/

class Dojo {

    private:
        KarateClass* classes;
        int num_classes;
        string name;
        bool tatami;

    public:

    /// Constructors
    Dojo() {
        classes = nullptr;
        num_classes = 0;
        name = "";
        tatami = false;
    }

    Dojo(KarateClass* c, int num, string n, bool q) {
        classes = c;
        num_classes = num;
        name = n;
        tatami = q;
    }

    /// Getters and Setters
    void setClasses(KarateClass* c) {
        classes = c;
    }

    KarateClass* getClasses() {
        return classes;
    }

    void setNumClasses(int num) {
        num_classes = num;
    }

    int getNumClasses() {
        return num_classes;
    }

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setTatami(bool q) {
        tatami = q;
    }

    int getTatami() {
        return tatami;
    }


    /// Add a new class to the dojo
    void addClass(KarateClass c) {
        KarateClass* new_classes = new KarateClass[num_classes + 1];

        for (int i = 0; i < num_classes; i++)
        {
            new_classes[i] = classes[i];
        }

        new_classes[num_classes] = c;

        num_classes++;

        delete[] classes;
        classes = new_classes;
    }

    /// Remove a class from the dojo
    void removeClass(string instructor) {
        int index = -1;
        for (int i = 0; i < num_classes; i++)
        {
            if (classes[i].getInstructor() == instructor)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Error: class with instructor " << instructor << " was not found." << endl;
            return;
        }

        KarateClass* new_classes = new KarateClass[num_classes - 1];

        for (int i = 0, j = 0; i < num_classes; i++)
        {
            if (i != index)
            {
                new_classes[j] = classes[i];
                j++;
            }
        }

        num_classes--;

        delete[] classes;
        classes = new_classes;
    }

    ///Operatori

    Dojo& operator = (const Dojo&);
    friend ostream& operator <<(ostream& out, const Dojo& obj);
    friend istream& operator >>(istream& in, Dojo& obj);
    Dojo operator-(const Dojo& d);
    Dojo& operator++();
    Dojo operator++ (int);
    Dojo& operator--();
    Dojo& operator+(const Dojo& d);
    Dojo operator+(int);
    friend Dojo& operator+(int, Dojo obj);
    friend bool operator==(const Dojo& d1, const Dojo& d2);
    float operator[](int);
    operator int();
    operator int() const {return this->num_classes;}

    explicit operator bool() const {
    return num_classes > 0;
    }
};


/// Display information about the dojo, including all classes and their students

ostream& operator<<(ostream& os, const Dojo& d) {

        os << "Dojo Name: " << d.name << endl;
        os << "Number of classes: " << d.num_classes << endl;

        for (int i = 0; i < d.num_classes; i++)
        {
            os << "Class " << i + 1 << ":" << endl;
            os << "Instructor: " << d.classes[i].getInstructor() << endl;
            os << "Number of students: " << d.classes[i].getNumStudents() << endl;

            Student* students = d.classes[i].getStudents();

            for (int j = 0; j < d.classes[i].getNumStudents(); j++)
            {
                os << "Student " << j + 1 << ":" << endl;
                os << students[j] << endl;
            }
        }

        os << "Tatami: " << d.tatami << endl;

        return os;
    }


Dojo& Dojo::operator++() {
    this->num_classes++;
    return *this;
}

Dojo& Dojo::operator--() {
    this->num_classes--;
    return *this;
}

/*
Dojo& Dojo::operator+(const Dojo& d) const {
    KarateClass* new_classes = new KarateClass[num_classes + d.num_classes];
    int i;
    for (i = 0; i < num_classes; i++) {
        new_classes[i] = classes[i];
    }
    for (int j = 0; j < d.num_classes; j++) {
        new_classes[i] = d.classes[j];
        i++;
    }
    return Dojo(new_classes, num_classes + d.num_classes, name + d.name, tatami || d.tatami);
}


Dojo operator-(const Dojo& d) const {
    KarateClass* new_classes = new KarateClass[num_classes];
    int new_num_classes = 0;
    for (int i = 0; i < num_classes; i++) {
        bool found = false;
        for (int j = 0; j < d.num_classes; j++) {
            if (classes[i] == d.classes[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            new_classes[new_num_classes] = classes[i];
            new_num_classes++;
        }
    }
    return Dojo(new_classes, new_num_classes, name, tatami);
}
*/

bool operator==(const Dojo& d1, const Dojo& d2) {
    if (d1.name != d2.name) return false;
    if (d1.num_classes != d2.num_classes) return false;

    for (int i = 0; i < d1.num_classes; i++) {
        if (d1.classes[i] != d2.classes[i]) {
            return false;
        }
    }

    if (d1.tatami != d2.tatami) return false;

    return true;
}


class Competition {

    private:
        string name;
        int year;
        vector<string> winners;
        int* numWinners;

    public:

        /// Constructors
        Competition() {
            name = "";
            year = 0;
            winners = vector<string>();
            numWinners = 0;
        }

        Competition(string n, int y, vector<string> w, int* z) {
            name = n;
            year = y;
        winners = w;
        numWinners = z;
        }


    /// Getters and Setters
    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setYear(int y) {
        year = y;
    }

    int getYear() const {
        return year;
    }

    void setWinners(vector<string> w) {
        winners = w;
    }

    vector<string> getWinners() const {
        return winners;
    }

    void setNumWinners(int* z) {
        numWinners = z;
    }

    int getNumWinners() const {
        return* numWinners;
    }



    /// Functionality
    void addWinner(string winner) {
        winners.push_back(winner);
    }


    ///Operatori
    Competition& operator++();
    Competition operator++ (int);
    friend ostream& operator<<(ostream& os, const Competition& c);
    friend istream& operator >>(istream& in, Competition& obj);
    Competition& operator = (const Competition&);
    friend Competition& operator+(const Competition& other);
    Competition& operator+(int num);
    friend Competition& operator+(int, Competition other);
    bool operator==(const Competition&);
    float operator[](int);
    operator int();
    operator int() const {return *this->numWinners;}
    Competition& operator+(const Competition& other);
};

Competition& Competition::operator++() {
    this->numWinners++;
    return *this;
}

ostream& operator<<(ostream& os, const Competition& c) {

        os << "Competition: " << c.name << endl;
        os << "Year: " << c.year << endl;
        os << "Winners: ";
        for (int i = 0; i < c.winners.size(); i++)
        {
            os << c.winners[i];
            if (i != c.winners.size() - 1)
            {
                os << ", ";
            }
        }

        os << endl;

        os << "Number of winners: " << c.numWinners << endl;

        os << endl;
        return os;
}

istream& operator>>(istream& in, Competition& obj) {
            cout << "Enter competition name: ";
            in >> obj.name;
            cout << "Enter competition year: ";
            in >> obj.year;
            cout << "Enter number of winners: ";
            in >> *(obj.numWinners);
            for (int i = 0; i < *(obj.numWinners); i++) {
                string winner;
                cout << "Enter winner #" << i + 1 << ": ";
                in >> winner;
                obj.winners.push_back(winner);
            }
            return in;
}

Competition& Competition::operator=(const Competition& other) {
            if (this != &other) {
                name = other.name;
                year = other.year;
                winners = other.winners;
                *numWinners = *other.numWinners;
            }
            return *this;
}


Competition& Competition::operator+(const Competition& other) {
    Competition result = *this;
    result.winners.insert(result.winners.end(), other.winners.begin(), other.winners.end());
    *(result.numWinners) += *other.numWinners;
    return result;
}


Competition& Competition::operator+(int num) {
            Competition result = *this;
            *(result.numWinners) += num;
            return result;
        }


/*
// Main function
int main() {

    // Create student objects
    Student student1(1, "Alice", 20, 50.0);
    Student student2(2, "Bob", 19, 70.0);
    Student student3(3, "Charlie", 21, 80.0);
    Student student4(4, "Dave", 22, 75.0);

     // Create instructor object
    Instructor instructor("Sensei John", 45, "Shotokan", 20.5);

    // Create karate class object
    KarateClass karateClass;
    karateClass.setInstructor(instructor.getName());

    // Add students to the class
    karateClass.addStudent(student1);
    karateClass.addStudent(student2);
    karateClass.addStudent(student3);
    karateClass.addStudent(student4);



    // Print the karate class information
    cout << "Karate Class Information" << endl;
    cout << "Instructor: " << karateClass.getInstructor() << endl;
    cout << "Number of Students: " << karateClass.getNumStudents() << endl;
    Student* students = karateClass.getStudents();

    for (int i = 0; i < karateClass.getNumStudents(); i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << students[i] << endl;
    }

    // Remove a student from the class
    karateClass.removeStudent(2);

    // Print the karate class information again
    cout << endl << "Karate Class Information" << endl;
    cout << "Instructor: " << karateClass.getInstructor() << endl;
    cout << "Number of Students: " << karateClass.getNumStudents() << endl;
    students = karateClass.getStudents();
    for (int i = 0; i < karateClass.getNumStudents(); i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << students[i] << endl;
    }
*/


int main() {
    vector<Student> students;
    string instructor;

    int choice;
    do {
        cout << "---------------------" << endl;
        cout << "Karate Class Manager" << endl;
        cout << "---------------------" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Remove a student" << endl;
        cout << "3. Print all students" << endl;
        cout << "4. Set instructor" << endl;
        cout << "5. Quit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl;
    system("CLS");
        switch (choice) {
            case 1: {
                int id, age;
                string name;
                float weight;


                cout << "Enter student ID: ";
                cin >> id;

                cout << "Enter student name: ";
                cin >> name;

                cout << "Enter student age: ";
                cin >> age;

                cout << "Enter student weight: ";
                cin >> weight;

                students.push_back(Student(name, age, weight));

                cout << "Student added successfully." << endl;
                break;
            }

            case 2: {
                int id;
                cout << "Enter student ID: ";
                cin >> id;

                bool found = false;
                for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
                    if (it->getStudentID() == id) {
                        students.erase(it);
                        found = true;
                        cout << "Student removed successfully." << endl;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found." << endl;
                }
                break;
            }

            case 3: {
                if (students.size() == 0) {
                    cout << "No students in the class." << endl;
                } else {
                    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
                        cout << *it << endl;
                    }
                }
                break;
            }

            case 4: {
                cout << "Enter instructor name: ";
                cin >> instructor;
                cout << "Instructor set to " << instructor << endl;
                break;
            }

            case 5: {
                cout << "Goodbye!" << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Try again." << endl;
                break;
            }
        }
        cout << endl;

    } while (choice != 5);

    return 0;
}
