#include <iostream>
#include <string>
using namespace std;

// A class is a BLUEPRINT. It doesn't exist in memory until you create an OBJECT from it.
class Student {
public:  // 'public' means accessible from outside the class -- more on this soon
    string name;
    int rollNumber;
    double cgpa;

    // A member FUNCTION (also called a "method") -- it can use the class's own data
    void display() {
        cout << "Name: " << name << ", Roll: " << rollNumber << ", CGPA: " << cgpa << endl;
    }

    bool isEligibleForPlacement() {
        return cgpa >= 6.0;
    }
};

int main() {
    // Creating OBJECTS (instances) of the class -- each is a separate, independent copy
    Student s1;
    s1.name = "Pruthvi";
    s1.rollNumber = 21;
    s1.cgpa = 8.5;

    Student s2;
    s2.name = "Aditi";
    s2.rollNumber = 22;
    s2.cgpa = 5.5;

    s1.display();
    s2.display();

    cout << s1.name << " eligible? " << s1.isEligibleForPlacement() << endl;
    cout << s2.name << " eligible? " << s2.isEligibleForPlacement() << endl;

    return 0;
}