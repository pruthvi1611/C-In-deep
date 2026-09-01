#include <iostream>
using namespace std;

int main() {
    // A 2D array is basically a grid: rows x columns
    int grid[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Access with two indices: grid[row][col]
    cout << "Element at row 1, col 2: " << grid[1][2] << endl; // 7

    // Traversal needs NESTED loops -- outer for rows, inner for columns
    cout << "\nFull grid:\n";
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cout << grid[row][col] << "\t";
        }
        cout << endl;  // new line after each row
    }

    return 0;
}