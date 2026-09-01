#include <iostream>
using namespace std;

int main() {
    int original = 10;

    // REFERENCE: an alias, another NAME for the same variable.
    // Once bound, it can NEVER point elsewhere. No special syntax needed to use it.
    int &ref = original;
    ref = 20;  // this changes 'original' directly, no dereferencing needed
    cout << "original after ref=20: " << original << endl;

    // POINTER: stores an address, and CAN be reassigned to point elsewhere.
    int a = 1, b = 2;
    int* p = &a;
    cout << "\np points to a, *p = " << *p << endl;

    p = &b;  // pointers CAN be reassigned to point at something else
    cout << "p now points to b, *p = " << *p << endl;

    // A reference could NEVER do this -- once bound to 'original', ref
    // is 'original' forever, for its whole lifetime.

    return 0;
}