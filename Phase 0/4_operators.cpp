#include <iostream>
using namespace std;

int main() {
    int a = 17, b = 5;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;   // INTEGER division -> 3, not 3.4
    cout << "a % b = " << a % b << endl;   // modulus (remainder) -> 2

    double result = (double)a / b;  // cast one operand to double to get real division
    cout << "a / b as double = " << result << endl;

    // Comparison operators return bool (0 or 1)
    cout << "a > b: " << (a > b) << endl;
    cout << "a == b: " << (a == b) << endl;

    // Logical operators
    bool x = true, y = false;
    cout << "x && y: " << (x && y) << endl;  // AND
    cout << "x || y: " << (x || y) << endl;  // OR
    cout << "!x: " << (!x) << endl;          // NOT

    // Increment/decrement — common in loops
    int counter = 5;
    cout << "counter++ (post): " << counter++ << endl; // prints 5, THEN increments
    cout << "now counter is: " << counter << endl;      // 6
    cout << "++counter (pre): " << ++counter << endl;   // increments FIRST, then prints -> 7

    return 0;
}