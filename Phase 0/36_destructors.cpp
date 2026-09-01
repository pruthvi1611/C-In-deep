#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;

    Student(string n) {
        name = n;
        cout << "Constructor: " << name << " created" << endl;
    }

    // DESTRUCTOR: runs automatically when the object is DESTROYED.
    // Same name as class but with a ~ prefix, no arguments, no return type.
    // Useful for cleanup -- e.g. freeing heap memory the object allocated (Topic 7!)
    ~Student() {
        cout << "Destructor: " << name << " destroyed" << endl;
    }
};

void createStudentInFunction() {
    Student temp("Temporary");
    cout << "Inside function, using temp..." << endl;
    // when this function ends, temp goes out of scope (remember Topic 7: stack lifetime!)
    // -> its destructor fires automatically right here
}

int main() {
    cout << "--- main starts ---\n";
    Student s1("Pruthvi");

    cout << "\n--- calling a function that creates its own student ---\n";
    createStudentInFunction();

    cout << "\n--- back in main, about to end ---\n";
    // s1's destructor will fire automatically when main() ends
    return 0;
}