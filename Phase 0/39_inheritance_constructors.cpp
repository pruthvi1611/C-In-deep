#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;

    Person(string n) {
        name = n;
        cout << "Person constructor called for " << name << endl;
    }
};

class Student : public Person {
public:
    double cgpa;

    // The derived class's constructor must explicitly call the base class's
    // constructor if it takes arguments -- using this ": Person(n)" syntax.
    Student(string n, double c) : Person(n) {
        cgpa = c;
        cout << "Student constructor called, cgpa = " << cgpa << endl;
    }
};

int main() {
    Student s("Pruthvi", 8.5);
    // Notice the ORDER: Person's constructor runs FIRST, then Student's.
    // This always happens -- base class is fully constructed before the
    // derived class adds its own part.

    cout << "\nName: " << s.name << ", CGPA: " << s.cgpa << endl;

    return 0;
}