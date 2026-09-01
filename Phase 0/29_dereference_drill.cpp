#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int* p = &x;      // p holds x's address
    int* q = p;        // q holds a COPY of that same address (q also points at x)

    cout << "x        = " << x << endl;
    cout << "&x       = " << &x << "   (x's address)" << endl;
    cout << "p        = " << p << "   (same as &x -- p HOLDS this address)" << endl;
    cout << "*p       = " << *p << "   (dereferencing ALWAYS gives a VALUE, never an address)" << endl;
    cout << "q        = " << q << "   (same address as p, since q = p copied it)" << endl;
    cout << "*q       = " << *q << "   (also 5, because q points at the same x)" << endl;

    cout << "\n--- Now let's change x through q ---\n";
    *q = 99;
    cout << "x is now: " << x << endl;   // changed! because *q modifies whatever q points at, which is x
    cout << "*p is now: " << *p << endl; // ALSO changed to 99, because p points at the same x

    return 0;
}