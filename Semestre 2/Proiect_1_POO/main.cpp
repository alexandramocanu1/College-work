#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Student {
    private:
        int student_id;
        string name;
        int age;
        float weight;
    public:

        // Constructors
        Student() {
            student_id = 0;
            name = "";
            age = 0;
            weight = 0.0;
        }

        Student(int id, string n, int a, float w) {
            student_id = id;
            name = n;
            age = a;
            weight = w;
        }

        // Getters and Setters
        void setStudentID(int id) {
            student_id = id;
        }

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

        float getWeight() const {
            return weight;
        }

        // Display student information
        friend ostream& operator<<(ostream& os, const Student& s) {
            os << "Student ID: " << s.student_id << endl;
            os << "Name: " << s.name << endl;
            os << "Age: " << s.age << endl;
            os << "Weight: " << s.weight << " kg" << endl;
            return os;
        }
};

class Instructor {
    private:
        string name;
        int age;
        char* style;
        float experienceYears;

    public:
        // Constructors
        Instructor() : name(""), age(0), style(nullptr), experienceYears(0.0) {}
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

        // Destructor
        ~Instructor() {
            delete[] style;
        }


        // Getters and Setters
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


        // Functionality
        void printInstructor() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Style: " << style << endl;
            cout << "Experience years: " << experienceYears << endl;
        }
};

class KarateClass {
    private:
        Student* students;
        int num_students;
        string instructor;

    public:

        // Constructors
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

        // Getters and Setters
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


        // Add a new student to the class
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


        // Remove a student from the class
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
};

/*
// Add a new student to the class
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
*/

class Dojo {
    private:
        KarateClass* classes;
        int num_classes;
        string name;
    public:

    // Constructors
    Dojo() {
        classes = nullptr;
        num_classes = 0;
        name = "";
    }

    Dojo(KarateClass* c, int num, string n) {
        classes = c;
        num_classes = num;
        name = n;
    }

    // Getters and Setters
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

    // Add a new class to the dojo
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

    // Remove a class from the dojo
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


    // Display information about the dojo, including all classes and their students

    friend ostream& operator<<(ostream& os, const Dojo& d) {

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

        return os;
    }
};


class Competition {
    private:
        string name;
        int year;
        vector<string> winners;
    public:
        // Constructors
        Competition() {
            name = "";
            year = 0;
            winners = vector<string>();
        }

        Competition(string n, int y, vector<string> w) {
            name = n;
            year = y;
        winners = w;
        }


    // Getters and Setters
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


    // Functionality
    void addWinner(string winner) {
        winners.push_back(winner);
    }

    friend ostream& operator<<(ostream& os, const Competition& c) {

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
        return os;
    }
};


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

                students.push_back(Student(id, name, age, weight));

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
