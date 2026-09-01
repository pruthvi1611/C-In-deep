#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // Here's a fact that surprises most beginners: an array's name,
    // used by itself, decays into a pointer to its FIRST element.
    int* p = arr;  // no & needed! arr already behaves like &arr[0]

    cout << "arr[0] = " << arr[0] << endl;
    cout << "*p = " << *p << endl;
    cout << "Are they the same address? " << (p == &arr[0]) << endl;

    // POINTER ARITHMETIC: p + 1 doesn't mean "address + 1 byte",
    // it means "move forward by 1 INT-sized step" (so +4 bytes for int)
    cout << "\n*(p+1) = " << *(p + 1) << endl;  // this is arr[1] = 20
    cout << "*(p+2) = " << *(p + 2) << endl;     // this is arr[2] = 30

    // So arr[i] is literally just shorthand for *(arr + i) under the hood
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";  // same output as arr[i]
    }
    cout << endl;

    return 0;
}