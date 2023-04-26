#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;


class Person
{
protected:
    string name;
    int age;
public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    virtual ~Person() {}
 /*   virtual string getName() const { return name; }
    virtual int getAge() const { return age; }
    */

    virtual string getName() const = 0; // metoda pur virtuala
    virtual int getAge() const = 0; // metoda pur virtuala
};


class Student : public Person {
protected:
    static int contorId;
    const int student_id;
    string name;
    int age;
    float weight;
    double beltLevel;
    float score;

public:

    // Conversion operator to int
    double promote(int n) const
    {
        return beltLevel + n;
    }

    double demote() const
    {
        return beltLevel - 0.5;
    }

    /// Constructors
    Student(); // fara parametrii

    Student(const Student &obj); // Copy constructor

    /* Student(string n, int a, float* w) {  // Constructor parametrizat
         name = n;
         age = a;
         weight = w;
     }*/

    Student(string n, int s) : student_id(++contorId), name(n), score(s) {}

    Student(string name, int age, float weight);

    /// Getters and Setters
    /*  void setStudentID(int id) {
          student_id = id;
      }
      */

      // implementarea metodelor virtuale pure din clasa "Person"
      string getName() const override { return name; }
    int getAge() const override { return age; }
    float getWeight() const { return weight; }
    double getBeltLevel() const { return beltLevel; }
    float getScore() const { return score; }


    int getStudentID() const
    {
        return student_id;
    }

    void setName(string n)
    {
        name = n;
    }

    void setAge(int a)
    {
        age = a;
    }

    void setWeight(float w)
    {
        weight = w;
    }

    int setBeltLevel() const
    {
        return beltLevel;
    }

    int setScore(int s)
    {
        score = s;
        return this->score;
    }

    operator int() const
    {
        return score;
    }

    /// Destructor
    virtual ~Student(){};

    /// Operatori
    float operator[](int);
    Student &operator++();
    Student operator++(int);
    Student operator+(int);
    friend Student operator+(int, Student obj);
    Student &operator=(const Student &);
    friend ostream &operator<<(ostream &out, const Student &obj);
    friend istream &operator>>(istream &in, Student &obj);
    operator int();
    //  operator int() const {return this->age;}
    bool operator==(const Student &);
    bool operator<(const Student &);

    /// Metode
    void print();
    void afisare();
    void citire();
};

/*
// Overloaded + operator outside Student class
Competition operator+(const Student& s, const Competition& c) {
  int newScore = s.operator int() + c.getScore();
  return Competition(c.getName(), newScore);
}
*/

void Student::print()
{
    cout << "Nume: " << this->name << endl;
    cout << "Varsta: " << this->age << endl;
    cout << "Greutate: " << this->weight << endl;
    cout << "Nivel centura: " << this->beltLevel << endl;
    cout << "Scor: " << this->score << endl;
}

int Student::contorId = 1000;

Student::operator int()
{
    return this->beltLevel;
}

Student::Student() : student_id(contorId++)
{

    name = "Anonim";
    age = 0;
    weight = 0;
    beltLevel = 0.0;
}

Student::Student(string name, int age, float weight) : student_id(contorId++)
{
    this->name = name;
    this->age = age;
    this->weight = weight;
}

Student::Student(const Student &obj) : student_id(contorId++)
{
    this->name = obj.name;
    this->age = obj.age;
    this->weight = obj.weight;
}

Student &Student::operator++()
{
    this->age++;
    return *this;
}

Student Student::operator++(int)
{
    Student aux(*this);
    this->age++;
    return aux;
}

/*
Student Student::operator+ (const Student& obj){
    Student aux(*this);
    aux.age += obj.age;
    return aux;
}
*/

Student Student::operator+(int x)
{
    Student aux(*this);
    aux.age += x;
    return aux;
}

Student operator+(int x, Student obj)
{
    return obj + x;
}

bool Student::operator==(const Student &obj)
{
    return this->name == obj.name;
}

bool Student::operator<(const Student &obj)
{
    return this->name < obj.name;
}

float Student::operator[](int i)
{

    if (this->weight == NULL)
        throw runtime_error("Nu exista elemente in vector");

    if (i < 0 || i > this->age)
    {
        throw runtime_error("Index invalid");
    }
    else
        return this->weight;
}

/*
Student::operator int(){
    return this->age;
}
*/

Student &Student::operator=(const Student &obj)
{

    this->name = obj.name;
    this->weight = obj.weight;

    return *this;
}

ostream &operator<<(ostream &out, const Student &obj)
{

    out << "Name: " << obj.name << endl;
    out << "Age: " << obj.age << endl;
    out << "Weight: " << obj.weight << endl;

    return out;
}

istream &operator>>(istream &in, Student &obj)
{

    cout << "Introduce the student's name: " << endl;
    in >> obj.name;

    cout << "Introduce the student's age: " << endl;
    in >> obj.age;

    cout << "Introduce the student's weight: " << endl;
    in >> obj.weight;

    return in;
}

class Instructor : public Person {
protected:
    string name;
    int age;
    char *style;
    float experienceYears;
    int id;

public:
    /// Constructors
    Instructor() : name(""), age(0), style(NULL), experienceYears(0.0) {}
    Instructor(const string &name, int age, const char *style, float experienceYears) : name(name), age(age), experienceYears(experienceYears)
    {

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

    Instructor(const Instructor &i) : name(i.name), age(i.age), experienceYears(i.experienceYears)
    {

        if (i.style != nullptr)
        {
            style = new char[strlen(i.style) + 1];
            strcpy(style, i.style);
        }
        else
        {
            style = nullptr;
        }
    }

    /// Destructor
    virtual ~Instructor(){};

    /// Getters and Setters

    // implementarea metodelor virtuale pure din clasa "Person"
    int getAge() const override { return age; }
    string getName() const override { return name; }
    float getWeight() const { return 0.0; } // instructorii nu au greutate specifica


    const char *getStyle() const
    {
        return style;
    }

    float getExperienceYears() const
    {
        return experienceYears;
    }

    void setName(const string &name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setStyle(const char *style)
    {
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

    void setExperienceYears(float experienceYears)
    {
        this->experienceYears = experienceYears;
    }

    int getID() const
    {
        return id;
    }

    /// Functionality
    void printInstructor() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Style: " << style << endl;
        cout << "Experience years: " << experienceYears << endl;
    }

    /// Operatori
    Instructor &operator=(const Instructor &);
    Instructor &operator++();
    Instructor operator++(int);
    Instructor &operator+(const Instructor &obj);
    Instructor operator+();
    Instructor operator+(int);
    friend Instructor operator+(int, Instructor obj);
    bool operator==(const Instructor &);
    bool operator<(const Instructor &);
    int operator[](int);
    operator int();
    operator int() const { return this->age; }
};

Instructor &Instructor::operator=(const Instructor &obj)
{

    if (this != &obj)
    {
        if (this->style != NULL)
        {
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

Instructor &Instructor::operator+(const Instructor &obj)
{

    Instructor aux(*this);
    aux.age += obj.age;
    return aux;
}

Instructor Instructor::operator+(int x)
{

    Instructor aux(*this);
    aux.age += x;
    return aux;
}

Instructor &Instructor::operator++()
{

    this->experienceYears++;
    return *this;
}

Instructor Instructor::operator++(int)
{

    Instructor aux(*this);
    this->age++;
    return aux;
}

Instructor operator+(int x, Instructor obj)
{
    return obj + x;
}

bool Instructor::operator==(const Instructor &obj)
{
    return this->name == obj.name;
}

bool Instructor::operator<(const Instructor &obj)
{
    return this->name < obj.name;
}

/*
int operator[](int i)
    {
        if (i < 0 || i >= this->age)
            throw runtime_error("index_invalid");
        return this->experienceYears[i];
    }
*/

Instructor::operator int()
{
    return this->age;
}

class KarateClass : public Student, public Instructor {
protected:
    static int contorId;
    Student *students;
    int num_students;
    string instructor;
    vector<Instructor> instructors;
    int class_id;

public:
    /// Constructors
    KarateClass()
    {
        students = nullptr;
        num_students = 0;
        instructor = "";
    }

    KarateClass(Student *s, int num, string i)
    {
        students = s;
        num_students = num;
        instructor = i;
    }

    KarateClass(int id)
    {
        class_id = id;
    }

    /// Destructor
    virtual ~KarateClass(){};

    /// Getters and Setters
    static int getContorId() { return KarateClass::contorId; }

    void setStudents(Student *s)
    {
        students = s;
    }

    Student *getStudents()
    {
        return students;
    }

    void setNumStudents(int num)
    {
        num_students = num;
    }

    int getNumStudents()
    {
        return num_students;
    }

    void setInstructor(string i)
    {
        instructor = i;
    }

    string getInstructor()
    {
        return instructor;
    }

    int getClassID()
    {
        return class_id;
    }

    /// Add a new student to the class
    virtual void addStudent(Student s) {
        if (num_students == 0) {
            students = new Student[1];
            students[0] = s;
            num_students++;
        }
        else {
            Student *temp = new Student[num_students + 1];
            for (int i = 0; i < num_students; i++) {
                temp[i] = students[i];
            }
            temp[num_students] = s;
            num_students++;
            delete[] students;
            students = temp;
        }
    }

    /// Remove a student from the class
    virtual void removeStudent(int student_id)
    {
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

    /*  ///Remove an instructor from the class
      bool removeInstructor(int instructorID) {
  auto it = find_if(instructor.begin(), instructor.end(),
      [instructorID](const Instructor& i) { return i.getID() == instructorID; });

  if (it == instructor.end()) {
      // Instructor not found
      return false;
  } else {
      // Remove instructor from vector
      instructor.erase(it);
      return true;
  }
}
*/

    /// Operatori
    friend ostream &operator<<(ostream &out, const KarateClass &obj);
    friend istream &operator>>(istream &in, KarateClass &obj);
    KarateClass &operator++();
    KarateClass operator++(int);
    KarateClass &operator--();
    KarateClass operator--(int);
    KarateClass operator+(const KarateClass &obj);
    KarateClass operator+(int);
    friend KarateClass operator+(int, KarateClass obj);
    bool operator==(const KarateClass &);
    bool operator<(const KarateClass &);
    float operator[](int) const;
    operator int();
    operator int() const { return this->num_students; }

    KarateClass &operator=(const KarateClass &);
};

ostream &operator<<(ostream &out, const KarateClass &obj)
{
    //  out << "Class ID: " << obj.class_id() << endl;
    // out << instructors[i].getName() << endl;
    //  out << "Number of students: " << getNumStudents() << endl;
    //   out << "ID of the class: " << getClassID() << endl;
    //   out << "Instructor of the class: " << getInstructor() << endl;

    out << "Students: " << endl;
    //    for (int i = 0; i < obj.getNumStudents(); i++) {
    //      out << obj.getStudents()[i] << endl;
    //   }
    return out;
}

KarateClass &KarateClass::operator=(const KarateClass &other)
{
    if (this != &other)
    {
        // Copy the data from the other object
        num_students = other.num_students;
        instructor = other.instructor;
        class_id = other.class_id;

        // Copy the students array
        delete[] students;
        students = new Student[num_students];
        for (int i = 0; i < num_students; i++)
        {
            students[i] = other.students[i];
        }

        // Copy the instructors vector
        instructors = other.instructors;
    }
    return *this;
}

KarateClass::operator int()
{
    return num_students;
}

float KarateClass::operator[](int index) const
{

    if (index < 0 || index >= num_students)
    {
        cout << "Error: invalid index" << endl;
        return -1.0f;
    }

    return students[index].getBeltLevel();
}

KarateClass KarateClass::operator+(const KarateClass &obj)
{

    Student *new_students = new Student[num_students + obj.num_students];

    for (int i = 0; i < num_students; i++)
    {
        new_students[i] = students[i];
    }

    for (int i = 0; i < obj.num_students; i++)
    {
        new_students[num_students + i] = obj.students[i];
    }

    KarateClass result(new_students, num_students + obj.num_students, instructor);

    delete[] new_students;

    return result;
}

KarateClass KarateClass::operator+(int n)
{

    KarateClass copy(*this);

    for (int i = 0; i < num_students; i++)
    {
        copy.students[i].promote(n);
    }

    return copy;
}

KarateClass operator+(int n, KarateClass obj)
{
    return obj + n;
}

KarateClass &KarateClass::operator++()
{
    int n;
    for (int i = 0; i < num_students; i++)
    {

        students[i].promote(n);
        n++;
    }
    return *this;
}

KarateClass KarateClass::operator++(int)
{

    KarateClass copy(*this);
    ++(*this);
    return copy;
}

KarateClass &KarateClass::operator--()
{

    for (int i = 0; i < num_students; i++)
    {
        students[i].demote();
    }
    return *this;
}

KarateClass KarateClass::operator--(int)
{
    KarateClass copy(*this);
    --(*this);
    return copy;
}

bool KarateClass::operator<(const KarateClass &obj)
{
    return this->num_students < obj.num_students;
}

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

class Dojo
{

private:
    KarateClass *classes;
    int num_classes;
    string name;
    bool tatami;
    char dojo_id;

public:
    /// Constructors
    Dojo()
    {
        classes = nullptr;
        num_classes = 0;
        name = "";
        tatami = false;
    }

    Dojo(KarateClass *c, int num, string n, bool q)
    {
        classes = c;
        num_classes = num;
        name = n;
        tatami = q;
    }

    /// Destructor
    ~Dojo(){};

    /// Getters and Setters
    void setClasses(KarateClass *c)
    {
        classes = c;
    }

    KarateClass *getClasses()
    {
        return classes;
    }

    void setNumClasses(int num)
    {
        num_classes = num;
    }

    int getNumClasses()
    {
        return num_classes;
    }

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setTatami(bool q)
    {
        tatami = q;
    }

    int getTatami()
    {
        return tatami;
    }

    char getDojoID()
    {
        return dojo_id;
    }

    /// View all instructors
    void viewInstructors() const
    {
        cout << "Instructors at " << name << ":" << endl;
        for (int i = 0; i < num_classes; i++)
        {
            cout << classes[i].getInstructor() << endl;
        }
    }

    /// View all classes
    void viewClasses() const
    {
        for (int i = 0; i < num_classes; i++)
        {
            cout << "Class " << i + 1 << ": " << classes[i] << endl;
        }
    }

    /// Add a new class to the dojo
    void addClass(KarateClass c)
    {
        KarateClass *new_classes = new KarateClass[num_classes + 1];

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
    void removeClass(string instructor)
    {
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

        KarateClass *new_classes = new KarateClass[num_classes - 1];

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

    /// Operatori

    Dojo &operator=(const Dojo &);
    friend ostream &operator<<(ostream &out, const Dojo &obj);
    friend istream &operator>>(istream &in, Dojo &obj);
    Dojo operator-(const Dojo &d);
    Dojo &operator++();
    Dojo operator++(int);
    Dojo &operator--();
    Dojo &operator+(const Dojo &d);
    Dojo operator+(int);
    friend Dojo &operator+(int, Dojo obj);
    friend bool operator==(const Dojo &d1, const Dojo &d2);
    float operator[](int);
    operator int();
    operator int() const { return this->num_classes; }

    explicit operator bool() const
    {
        return num_classes > 0;
    }

    void print();
};

void Dojo::print()
{
    cout << "Numarul de clase: " << this->num_classes << endl;
    cout << "Numele clasei: " << this->name << endl;
}

/// Display information about the dojo, including all classes and their students

ostream &operator<<(ostream &os, const Dojo &d)
{

    os << "Dojo Name: " << d.name << endl;
    os << "Number of classes: " << d.num_classes << endl;

    for (int i = 0; i < d.num_classes; i++)
    {
        os << "Class " << i + 1 << ":" << endl;
        os << "Instructor: " << d.classes[i].getInstructor() << endl;
        os << "Number of students: " << d.classes[i].getNumStudents() << endl;

        Student *students = d.classes[i].getStudents();

        for (int j = 0; j < d.classes[i].getNumStudents(); j++)
        {
            os << "Student " << j + 1 << ":" << endl;
            os << students[j] << endl;
        }
    }

    os << "Tatami: " << d.tatami << endl;

    return os;
}

Dojo &Dojo::operator++()
{
    this->num_classes++;
    return *this;
}

Dojo &Dojo::operator--()
{
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

bool operator==(const Dojo &d1, const Dojo &d2)
{
    if (d1.name != d2.name)
        return false;
    if (d1.num_classes != d2.num_classes)
        return false;

    for (int i = 0; i < d1.num_classes; i++)
    {
        if (d1.classes[i] != d2.classes[i])
        {
            return false;
        }
    }

    if (d1.tatami != d2.tatami)
        return false;

    return true;
}

class Competition : public KarateClass {
protected:
    string name;
    int year;
    vector<string> winners;
    int *numWinners;
    float score;
    char competition_id;

public:
    /// Constructors
    Competition()
    {
        name = "";
        year = 0;
        winners = vector<string>();
        numWinners = new int(0);
    }

    Competition(string n, int y, vector<string> w, int *z)
    {
        name = n;
        year = y;
        winners = w;
        numWinners = z;
    }

    Competition(string s, int NewScore)
    {
        score = NewScore;
        name = s;
    }

    /// Destructor
    ~Competition(){};

    /// Getters and Setters
    void setName(string n)
    {
        name = n;
    }

    string getName() const
    {
        return name;
    }

    void setYear(int y)
    {
        year = y;
    }

    int getYear() const
    {
        return year;
    }

    void setWinners(vector<string> w)
    {
        winners = w;
    }

    vector<string> getWinners() const
    {
        return winners;
    }

    void setNumWinners(int *z)
    {
        numWinners = z;
    }

    int getNumWinners() const
    {
        return *numWinners;
    }

    void setScore(float q)
    {
        score = q;
    }

    int getScore() const
    {
        return score;
    }

    int getCompetitionId() const
    {
        return competition_id;
    }

    /// Functionality
    void addWinner(string winner)
    {
        winners.push_back(winner);
    }

    void addStudent(vector<Student> &students, int student_id)
    {
        // Check if student exists
        bool student_found = false;
        for (vector<Student>::iterator it = students.begin(); it != students.end(); it++)
        {
            if (it->getStudentID() == student_id)
            {
                student_found = true;
                // Add student to competition
                if (it->getBeltLevel() >= 3)
                {
                    // Add to championship
                    winners.push_back(it->getName());
                    (*numWinners)++;
                    it->setScore(it->getScore() + 10.0); // increase score of the student
                }
                else
                {
                    // Add to cup
                    it->setScore(it->getScore() + 5.0); // increase score of the student
                }
                break;
            }
        }
        if (!student_found)
        {
            cout << endl
                 << "Student not found." << endl;
        }
    }

    void removeStudent(int studentId)
    {
        for (auto it = winners.begin(); it != winners.end(); ++it)
        {
            if (stoi(*it) == studentId)
            { // convert string to int and compare with studentId
                winners.erase(it);
                (*numWinners)--;
                break;
            }
        }
    }

    int getStudentId(int student_id) const
    {
        for (int i = 0; i < winners.size(); i++)
        {
            if (winners[i] == name)
            {
                return i + 1;
            }
        }
        return -1; // Returnează -1 dacă numele studentului nu este găsit
    }

    /// Operatori
    Competition &operator++();
    Competition operator++(int);
    friend ostream &operator<<(ostream &os, const Competition &c);
    friend istream &operator>>(istream &in, Competition &obj);
    Competition &operator=(const Competition &);
    // friend Competition& operator+(const Competition& other);
    Competition &operator+(int num);
    friend Competition &operator+(int, Competition other);
    bool operator==(const Competition &);
    float operator[](int);
    operator int();
    operator int() const { return *this->numWinners; }
    Competition &operator+(const Student &c);
    Competition operator+(const Student &c) const;
    Competition &operator+(const Competition &other);
};

Competition Competition::operator+(const Student &c) const
{
    int newScore = score + c.getScore();
    return Competition(name, newScore);
}

Competition &Competition::operator++()
{
    this->numWinners++;
    return *this;
}

ostream &operator<<(ostream &os, const Competition &c)
{

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

    os << "Number of winners: " << *c.numWinners << endl;

    os << endl;
    return os;
}

istream &operator>>(istream &in, Competition &obj)
{
    cout << "Enter competition name: ";
    in >> obj.name;
    cout << "Enter competition year: ";
    in >> obj.year;
    cout << "Enter number of winners: ";
    in >> *(obj.numWinners);
    for (int i = 0; i < *(obj.numWinners); i++)
    {
        string winner;
        cout << "Enter winner #" << i + 1 << ": ";
        in >> winner;
        obj.winners.push_back(winner);
    }
    return in;
}

Competition &Competition::operator=(const Competition &other)
{
    if (this != &other)
    {
        name = other.name;
        year = other.year;
        winners = other.winners;
        numWinners = new int(*other.numWinners);
    }
    return *this;
}

Competition &Competition::operator+(const Competition &other)
{
    winners.insert(winners.end(), other.winners.begin(), other.winners.end());
    *numWinners += *other.numWinners;
    return *this;
}

Competition &Competition::operator+(int num)
{
    // Competition result = *this;
    *numWinners += num;
    return *this;
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


int main()
{
    vector<Student> students;
    vector<Instructor> instructors;
    vector<KarateClass> karateClasses;
    vector<Dojo> dojos;
    vector<Competition> competitions;

    int choice;

    do
    {
        cout << "---------------------" << endl;
        cout << "Karate Class Manager" << endl;
        cout << "---------------------" << endl;
        cout << "1. Add a student to a karate class" << endl;
        cout << "2. Remove a student from a karate class" << endl;
        //       cout << "3. Update student information" << endl;
        cout << "3. View all students" << endl;
        cout << "4. Add an instructor to a karate class" << endl;
        //        cout << "6. Remove an instructor from a karate class" << endl;
        cout << "5. View all instructors in a dojo" << endl;
        cout << "6. Add a karate class to a dojo" << endl;
        cout << "7. View all karate classes in a dojo" << endl;
        cout << "8. View all dojos" << endl;
        cout << "9. Add a competition" << endl;
        cout << "10. Update competition information" << endl;
        cout << "11. View all competitions" << endl;
        cout << "12. Add a student to a competition" << endl;
        cout << "13. Remove a student from a competition" << endl;
        cout << "14. View all student in a competition" << endl;
        cout << "15. Add a dojo" << endl;
        cout << "16. Quit" << endl;
        cout << endl
             << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        system("CLS");

        switch (choice)
        {

        case 1:
        {
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

            cout << endl
                 << "Student added successfully." << endl;
            break;
        }

        case 2:
        {
            int id;
            cout << "Enter student ID: ";
            cin >> id;

            bool found = false;
            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++)
            {
                if (it->getStudentID() == id)
                {
                    students.erase(it);
                    found = true;
                    cout << endl
                         << "Student removed successfully." << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << endl
                     << "Student not found." << endl;
            }
            break;
        }

        case 3:
        {
            if (students.size() == 0)
            {
                cout << "No students in the class." << endl;
            }
            else
            {
                for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
                {
                    cout << *it << endl;
                }
            }
            break;
        }

            /*  case 4: {
                  if (students.empty()) {
                      cout << endl << "No students found." << endl;
                  } else {
                      cout << "Students:" << endl;
                      for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
                          it->print();
                      }
                  }
                  break;
              }
              */

        case 4:
        {
            int class_id, instructor_id;
            cout << "Enter karate class ID: ";
            cin >> class_id;

            // Check if karate class exists
            bool class_found = false;
            for (vector<KarateClass>::iterator it = karateClasses.begin(); it != karateClasses.end(); it++)
            {
                if (it->getClassID() == class_id)
                {
                    class_found = true;
                    break;
                }
            }
            if (!class_found)
            {
                cout << endl
                     << "Karate class not found." << endl;
                break;
            }

            cout << "Enter instructor ID: ";
            cin >> instructor_id;
        }
            /*   case 4: {
       cout << "All students:" << endl;
       for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
           it->print();
           cout << endl;
       }
       break;
   }*/

            /* case 5: {
                 int class_id, instructor_id;
                 cout << "Enter karate class ID: ";
                 cin >> class_id;

                 // Check if karate class exists
                 bool class_found = false;
                 for (vector<KarateClass>::iterator it = karateClasses.begin(); it != karateClasses.end(); it++) {
                     if (it->getClassID() == class_id) {
                         class_found = true;
                         break;
                     }
                 }
                 if (!class_found) {
                     cout << endl << "Karate class not found." << endl;
                     break;
                 }

                 cout << "Enter instructor ID: ";
                 cin >> instructor_id;

                 // Check if instructor exists
                 bool instructor_found = false;
                 for (vector<Instructor>::iterator it = instructors.begin(); it != instructors.end(); it++) {
                     if (it->getInstructorID() == instructor_id) {
                         instructor_found = true;
                         break;
                     }
                 }
                 if (!instructor_found) {
                     cout << endl << "Instructor not found." << endl;
                     break;
                 }

                 // Add instructor to karate class
                 for (vector<KarateClass>::iterator it = karateClasses.begin(); it != karateClasses.end(); it++) {
                     if (it->getClassID() == class_id) {
                         it->addInstructor(instructor_id);
                         break;
                     }
                 }
                 cout << endl << "Instructor added successfully to karate class." << endl;
                 break;
             }*/

            /*  case 6: {
                  int class_id, instructor_id;
                  cout << "Enter karate class ID: ";
                  cin >> class_id;

                  // Check if karate class exists
                  bool class_found = false;
                  for (vector<KarateClass>::iterator it = karateClasses.begin(); it != karateClasses.end(); it++) {
                      if (it->getClassID() == class_id) {
                          class_found = true;
                          break;
                      }
                  }
                  if (!class_found) {
                      cout << endl << "Karate class not found." << endl;
                      break;
                  }

                  cout << "Enter instructor ID: ";
                  cin >> instructor_id;

                  // Check if instructor is teaching in karate class
                  bool instructor_found = false;
                  for (vector<KarateClass>::iterator it = karateClasses.begin(); it != karateClasses.end(); it++) {
                      if (it->getClassID() == class_id) {
                          if (it->removeInstructor(instructor_id)) {
                              instructor_found = true;
                              cout << endl << "Instructor removed successfully from karate class." << endl;
                              break;
                          }
                      }
                  }
                  if (!instructor_found) {
                      cout << endl << "Instructor not found in karate class." << endl;
                  }
                  break;

              }
      */
        case 5:
        {
            int dojo_id;
            cout << "Enter dojo ID: ";
            cin >> dojo_id;

            // Check if dojo exists
            bool dojo_found = false;
            for (vector<Dojo>::iterator it = dojos.begin(); it != dojos.end(); it++)
            {
                if (it->getDojoID() == dojo_id)
                {
                    dojo_found = true;
                    // View all instructors in dojo
                    it->viewInstructors();
                    break;
                }
            }
            if (!dojo_found)
            {
                cout << endl
                     << "Dojo not found." << endl;
            }
            break;
        }

        case 6:
        {
            int dojo_id, class_id;
            cout << "Enter dojo ID: ";
            cin >> dojo_id;

            // Check if dojo exists
            bool dojo_found = false;
            for (vector<Dojo>::iterator it = dojos.begin(); it != dojos.end(); it++)
            {
                if (it->getDojoID() == dojo_id)
                {
                    dojo_found = true;
                    cout << "Enter karate class ID: ";
                    cin >> class_id;

                    // Check if karate class exists
                    bool class_found = false;
                    for (vector<KarateClass>::iterator it2 = karateClasses.begin(); it2 != karateClasses.end(); it2++)
                    {
                        if (it2->getClassID() == class_id)
                        {
                            class_found = true;
                            // Add karate class to dojo
                            KarateClass new_class(class_id);
                            it->addClass(new_class);
                            cout << endl
                                 << "Karate class added successfully to dojo." << endl;
                            break;
                        }
                    }
                    if (!class_found)
                    {
                        cout << endl
                             << "Karate class not found." << endl;
                    }
                    break;
                }
            }
            if (!dojo_found)
            {
                cout << endl
                     << "Dojo not found." << endl;
            }
            break;
        }

        case 7:
        {
            int dojo_id;
            cout << "Enter dojo ID: ";
            cin >> dojo_id;

            // Check if dojo exists
            bool dojo_found = false;
            for (vector<Dojo>::iterator it = dojos.begin(); it != dojos.end(); it++)
            {
                if (it->getDojoID() == dojo_id)
                {
                    dojo_found = true;
                    // View all karate classes in dojo
                    it->viewClasses();
                    break;
                }
            }
            if (!dojo_found)
            {
                cout << endl
                     << "Dojo not found." << endl;
            }
            break;
        }

        case 8:
        {
            if (dojos.empty())
            {
                cout << "No dojos found." << endl;
            }
            else
            {
                cout << "ID\tName\tAddress\tPhone" << endl;
                for (vector<Dojo>::iterator it = dojos.begin(); it != dojos.end(); it++)
                {
                    it->print();
                }
            }
            break;
        }

        case 9:
        {
            string competition_name;
            cout << "Enter competition name: ";
            getline(cin, competition_name); // consume newline character left by previous input
            getline(cin, competition_name);

            Competition competition(competition_name, 0, vector<string>(), new int(0));
            competitions.push_back(competition);

            cout << endl
                 << "Competition added successfully." << endl;
            break;
        }

        case 10:
        {
            int competition_id;
            cout << "Enter competition ID: ";
            cin >> competition_id;

            // Find the competition with the specified ID
            auto it = find_if(competitions.begin(), competitions.end(),
                              [competition_id](const Competition &c)
                              { return c.getCompetitionId() == competition_id; });

            if (it == competitions.end())
            {
                // Competition not found
                cout << "Competition not found." << endl;
            }
            else
            {
                // Update competition information
                string name;
                int year;
                float score;

                cout << "Enter new name (or press enter to skip): ";
                getline(cin, name); // consume newline character left by previous input
                getline(cin, name);
                if (!name.empty())
                {
                    it->setName(name);
                }

                cout << "Enter new year (or press enter to skip): ";
                cin >> year;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    it->setYear(year);
                }

                cout << "Enter new score (or press enter to skip): ";
                cin >> score;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    it->setScore(score);
                }

                cout << endl
                     << "Competition information updated successfully." << endl;
            }
            break;
        }

        case 11:
        {
            cout << "Competitions:" << endl;
            for (vector<Competition>::iterator it = competitions.begin(); it != competitions.end(); it++)
            {
                cout << endl
                     << "Competition ID: " << it->getCompetitionId() << endl;
                cout << "Name: " << it->getName() << endl;
                // cout << "Start Date: " << it->getStartDate() << endl;
                // cout << "End Date: " << it->getEndDate() << endl;
            }
            break;
        }

        case 12:
        {
            int competition_id, student_id;
            cout << "Enter competition ID: ";
            cin >> competition_id;

            // Check if competition exists
            bool competition_found = false;
            for (vector<Competition>::iterator it = competitions.begin(); it != competitions.end(); it++)
            {
                if (it->getCompetitionId() == competition_id)
                {
                    competition_found = true;
                    break;
                }
            }
            if (!competition_found)
            {
                cout << endl
                     << "Competition not found." << endl;
                break;
            }

            cout << "Enter student ID: ";
            cin >> student_id;

            // Check if student exists
            bool student_found = false;
            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++)
            {
                if (it->getStudentID() == student_id)
                {
                    student_found = true;
                    break;
                }
            }
            if (!student_found)
            {
                cout << endl
                     << "Student not found." << endl;
                break;
            }

            // Add student
            for (vector<Competition>::iterator it = competitions.begin(); it != competitions.end(); it++)
            {
                if (it->getCompetitionId() == competition_id)
                {
                    it->addStudent(students, student_id);
                    cout << endl
                         << "Student added to competition successfully." << endl;
                    break;
                }
            }
            break;
        }
        case 13:
        {
            int competition_id, student_id;
            cout << "Enter competition ID: ";
            cin >> competition_id;

            // Check if competition exists
            bool competition_found = false;
            for (vector<Competition>::iterator it = competitions.begin(); it != competitions.end(); it++)
            {
                if (it->getCompetitionId() == competition_id)
                {
                    competition_found = true;
                    break;
                }
            }
            if (!competition_found)
            {
                cout << endl
                     << "Competition not found." << endl;
                break;
            }

            cout << "Enter student ID: ";
            cin >> student_id;

            // Check if student exists
            bool student_found = false;
            for (vector<Student>::iterator it = students.begin(); it != students.end(); it++)
            {
                if (it->getStudentID() == student_id)
                {
                    student_found = true;
                    break;
                }
            }
            if (!student_found)
            {
                cout << endl
                     << "Student not found." << endl;
                break;
            }

            // Remove student
            for (auto &competition : competitions)
            {
                if (competition.getCompetitionId() == competition_id)
                {
                    // Find student in the competition
                    int studentIndex = competition.getStudentId(student_id);
                    if (studentIndex != -1)
                    {
                        // Remove student
                        competition.removeStudent(studentIndex);
                        cout << endl
                             << "Student removed from competition successfully." << endl;
                    }
                    else
                    {
                        cout << endl
                             << "Student is not in the competition." << endl;
                    }
                    break;
                }
            }
            break;
        }

        case 14:
        {
            int competition_id;
            cout << "Enter competition ID: ";
            cin >> competition_id;

            // Check if competition exists
            bool competition_found = false;
            for (vector<Competition>::iterator it = competitions.begin(); it != competitions.end(); it++)
            {
                if (it->getCompetitionId() == competition_id)
                {
                    competition_found = true;

                    // Print list of students
                    cout << endl
                         << "Students in competition:" << endl;
                    vector<string> student_names = it->getWinners();
                    for (vector<string>::iterator it2 = student_names.begin(); it2 != student_names.end(); it2++)
                    {
                        for (vector<Student>::iterator it3 = students.begin(); it3 != students.end(); it3++)
                        {
                            if (it3->getName() == *it2)
                            {
                                cout << "ID: " << it3->getStudentID() << ", Name: " << it3->getName() << endl;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (!competition_found)
            {
                cout << endl
                     << "Competition not found." << endl;
            }
            break;
        }

        case 15:
        {
            string dojo_name;
            bool has_tatami;
            char dojo_id;

            cout << "Enter dojo name: ";
            cin >> dojo_name;

            cout << "Does the dojo have a tatami? (y/n): ";
            char choice;
            cin >> choice;
            has_tatami = (choice == 'y' || choice == 'n');

            cout << "Enter dojo ID: ";
            cin >> dojo_id;

            // Check if Dojo already exists
            bool dojo_found = false;
            for (vector<Dojo>::iterator it = dojos.begin(); it != dojos.end(); it++)
            {
                if (it->getDojoID() == dojo_id)
                {
                    dojo_found = true;
                    break;
                }
            }
            if (dojo_found)
            {
                cout << endl
                     << "Dojo with ID " << dojo_id << " already exists." << endl;
                break;
            }

            // Add new Dojo
            dojos.push_back(Dojo(nullptr, 0, dojo_name, has_tatami));
            cout << endl
                 << "Dojo added successfully." << endl;
            break;
        }

        case 16:
        {
            cout << "Exiting program..." << endl;
            return 0;
        }

        default:
        {
            cout << "Invalid option. Please try again." << endl;
            break;
        }
        }

    } while (choice != 16);

    return 0;
}
