#include <iostream>
using namespace std;

// Same function name "add", but different parameter lists.
// The compiler picks the right one based on what you pass in.
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {  // different NUMBER of parameters also counts as overloading
    return a + b + c;
}

int main() {
    cout << add(2, 3) << endl;         // calls int version -> 5
    cout << add(2.5, 3.5) << endl;     // calls double version -> 6
    cout << add(1, 2, 3) << endl;      // calls 3-argument version -> 6

    return 0;
}