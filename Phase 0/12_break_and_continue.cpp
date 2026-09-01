#include <iostream>
using namespace std;

int main() {
    cout << "Using break (exits the loop entirely):\n";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break;  // stops the loop completely the moment i is 5
        }
        cout << i << " ";
    }
    cout << endl;

    cout << "\nUsing continue (skips just this iteration):\n";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // skip the rest of THIS iteration, go to next i
        }
        cout << i << " ";  // only odd numbers get printed
    }
    cout << endl;

    return 0;
}