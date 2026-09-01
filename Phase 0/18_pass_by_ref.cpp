#include <iostream>
using namespace std;

// PASS BY VALUE: the function gets a COPY. Changes here don't affect the original.
void tryToDoubleValue(int x) {
    x = x * 2;
    cout << "Inside tryToDoubleValue, x = " << x << endl;
}

// PASS BY REFERENCE: the '&' means this function works on the ORIGINAL variable,
// not a copy. Changes here DO affect the caller's variable.
void actuallyDouble(int &x) {
    x = x * 2;
    cout << "Inside actuallyDouble, x = " << x << endl;
}

int main() {
    int num = 10;

    tryToDoubleValue(num);
    cout << "After tryToDoubleValue, num in main = " << num << endl;  // still 10!

    actuallyDouble(num);
    cout << "After actuallyDouble, num in main = " << num << endl;    // now 20

    return 0;
}