#include <iostream>
using namespace std;

int main() {
    int num = 15;

    // Long way
    string result;
    if (num % 2 == 0) {
        result = "Even";
    } else {
        result = "Odd";
    }
    cout << result << endl;

    // Ternary way: condition ? valueIfTrue : valueIfFalse
    string result2 = (num % 2 == 0) ? "Even" : "Odd";
    cout << result2 << endl;

    // Great for quick inline decisions, e.g. finding the max of two numbers
    int a = 12, b = 27;
    int maxVal = (a > b) ? a : b;
    cout << "Max: " << maxVal << endl;

    return 0;
}