#include <iostream>
using namespace std;

int main() {
    int age = 21;

    // The & operator, when used like this, means "give me the ADDRESS of this variable"
    cout << "Value of age: " << age << endl;
    cout << "Address of age: " << &age << endl;

    // A pointer is declared with *, and it stores an address.
    // "int* p" means "p is a pointer that points to an int"
    int* p = &age;

    cout << "\nValue stored in p (this is an address): " << p << endl;
    cout << "Is p the same as &age? " << (p == &age) << endl;

    // The * operator, when used on a pointer, means "DEREFERENCE" --
    // i.e. "go to the address stored in this pointer, and get the value there"
    cout << "\nDereferencing p (*p): " << *p << endl;  // this gives us 21, age's value

    return 0;
}