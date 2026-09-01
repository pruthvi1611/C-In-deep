#include <iostream>
using namespace std;

int main() {
    // do-while runs the body FIRST, THEN checks the condition
    // So it always executes at least once, even if the condition is false from the start

    int x = 10;
    do {
        cout << "This runs at least once, x = " << x << endl;
        x++;
    } while (x < 5);  // condition is false immediately, but body already ran

    cout << "\n--- Compare with a regular while ---\n";
    int y = 10;
    while (y < 5) {
        cout << "This will NEVER print, y = " << y << endl;
        y++;
    }
    cout << "See? Nothing printed above because while checks BEFORE running." << endl;

    return 0;
}