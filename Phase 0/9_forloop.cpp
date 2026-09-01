#include <iostream>
using namespace std;

int main() {
    // for (initialization; condition; update)
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Practical example: multiplication table of 7
    int n = 7;
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }

    // Loop can go backwards too
    cout << "Countdown: ";
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;

    // Skipping by more than 1
    cout << "Even numbers up to 10: ";
    for (int i = 0; i <= 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}