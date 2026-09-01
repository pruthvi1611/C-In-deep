#include <iostream>
using namespace std;

int main() {
    // Declaration + initialization
    int marks[5] = {85, 90, 78, 92, 88};

    // Access by index — starts at 0, NOT 1
    cout << "First element (index 0): " << marks[0] << endl;
    cout << "Third element (index 2): " << marks[2] << endl;
    cout << "Last element (index 4): " << marks[4] << endl;

    // Modifying an element
    marks[1] = 95;
    cout << "Modified second element: " << marks[1] << endl;

    // Traversal with a for loop
    cout << "All marks: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    // sizeof trick to get array length (only works when you still have the
    // original array, not when it's been passed into a function)
    int size = sizeof(marks) / sizeof(marks[0]);
    cout << "Array size via sizeof: " << size << endl;

    // Declaring without initial values, then filling later
    int scores[3];
    scores[0] = 10;
    scores[1] = 20;
    scores[2] = 30;
    for (int i = 0; i < 3; i++) cout << scores[i] << " ";
    cout << endl;

    return 0;
}