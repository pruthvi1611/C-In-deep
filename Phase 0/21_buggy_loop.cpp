#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};

    // WRONG: this loop condition is a classic off-by-one bug
    cout << "Buggy loop (i <= 3 instead of i < 3):\n";
    for (int i = 0; i <= 3; i++) {   // BUG: should be i < 3
        cout << "arr[" << i << "] = " << arr[i] << endl;
        // arr[3] is OUT OF BOUNDS. C++ won't stop you or throw an error here
        // -- it just reads whatever garbage happens to be in memory next.
        // This is exactly why C++ requires discipline that Python doesn't.
    }

    return 0;
}