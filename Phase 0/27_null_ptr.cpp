#include <iostream>
using namespace std;

int main() {
    // A pointer that isn't pointing at anything valid yet should be set to nullptr
    int* p = nullptr;

    cout << "p is nullptr? " << (p == nullptr) << endl;

    // ALWAYS check before dereferencing a pointer that might be null
    if (p != nullptr) {
        cout << *p << endl;
    } else {
        cout << "p doesn't point to anything valid -- safely skipped dereferencing." << endl;
    }

    // Now let's point it somewhere real
    int value = 42;
    p = &value;
    if (p != nullptr) {
        cout << "Now *p = " << *p << endl;
    }

    // NOTE: dereferencing a nullptr (like *p when p is nullptr) causes a CRASH
    // (segmentation fault). This is one of the most common C++ runtime errors.
    // Always initialize pointers, and always check for nullptr before dereferencing
    // if there's any chance it wasn't set.

    return 0;
}