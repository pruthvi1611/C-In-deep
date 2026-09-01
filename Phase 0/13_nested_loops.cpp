#include <iostream>
using namespace std;

int main() {
    int rows = 5;

    // Right-angled triangle of stars
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;  // move to next line after finishing one row
    }

    cout << endl;

    // Number pyramid (slightly trickier — combines two inner loops)
    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            cout << "  ";  // leading spaces for the pyramid shape
        }
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}