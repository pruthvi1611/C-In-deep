#include <iostream>
using namespace std;

// returnType functionName(parameters) { ... }
int add(int a, int b) {
    return a + b;
}

// A function that returns nothing uses 'void'
void greet(string name) {
    cout << "Hello, " << name << "!" << endl;
    // no return statement needed (or just "return;" with nothing after it)
}

// A function can call other functions
bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    int result = add(5, 7);
    cout << "5 + 7 = " << result << endl;

    greet("Pruthvi");

    cout << "Is 10 even? " << isEven(10) << endl;
    cout << "Is 7 even? " << isEven(7) << endl;

    return 0;
}