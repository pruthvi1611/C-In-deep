#include <iostream>
using namespace std;

int main() {
    int day = 3;

    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 6:
        case 7:
            cout << "Weekend" << endl;   // case 6 and 7 both print this ("fallthrough" on purpose)
            break;
        default:
            cout << "Invalid day" << endl;
    }

    // What happens if you FORGET break? Let's see:
    cout << "\n--- Demonstrating missing break (a common bug) ---\n";
    int x = 1;
    switch (x) {
        case 1:
            cout << "one" << endl;
            // no break here!
        case 2:
            cout << "two" << endl;
            break;
        case 3:
            cout << "three" << endl;
            break;
    }
    // Notice it prints BOTH "one" and "two" — execution falls through
    // to the next case until it hits a break. This is a classic bug source.

    return 0;
}