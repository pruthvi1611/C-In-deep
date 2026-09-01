#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    double cgpa;

    // CONSTRUCTOR: a special function that runs AUTOMATICALLY when an object
    // is created. Same name as the class, NO return type (not even void).
    // This one takes no arguments -- called a "default constructor".
    Student() {
        name = "Unknown";
        rollNumber = 0;
        cgpa = 0.0;
        cout << "Default constructor called" << endl;
    }

    // PARAMETERIZED constructor -- lets you set values right at creation.
    // This is constructor OVERLOADING -- same rules as function overloading (Topic 4).
    Student(string n, int r, double c) {
        name = n;
        rollNumber = r;
        cgpa = c;
        cout << "Parameterized constructor called for " << name << endl;
    }

    void display() {
        cout << "Name: " << name << ", Roll: " << rollNumber << ", CGPA: " << cgpa << endl;
    }
};

int main() {
    cout << "--- Creating s1 with no arguments ---\n";
    Student s1;  // calls the default constructor automatically
    s1.display();

    cout << "\n--- Creating s2 with arguments ---\n";
    Student s2("Pruthvi", 21, 8.5);  // calls the parameterized constructor
    s2.display();

    return 0;
}