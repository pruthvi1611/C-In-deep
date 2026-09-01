#include <iostream>
using namespace std;

int main() {
    int age = 20;
    bool hasID = true;

    // Combining conditions with && (AND)
    if (age >= 18 && hasID) {
        cout << "Entry allowed." << endl;
    } else {
        cout << "Entry denied." << endl;
    }

    // Nested if — a condition inside another condition
    int cgpa_x10 = 82; // representing 8.2 CGPA as int to avoid float comparison issues
    bool hasBacklog = false;

    if (cgpa_x10 >= 70) {
        if (!hasBacklog) {
            cout << "Eligible for placement drive." << endl;
        } else {
            cout << "CGPA fine, but backlog blocks eligibility." << endl;
        }
    } else {
        cout << "CGPA too low for this drive." << endl;
    }

    return 0;
}