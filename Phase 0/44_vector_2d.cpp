#include <iostream>
#include <vector>
using namespace std;

int main() {
    // A vector of vectors -- this is how you build a resizable grid/matrix
    vector<vector<int>> grid(3, vector<int>(4, 0));  // 3 rows, 4 cols, all 0

    // Filling it
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = i * 4 + j;
        }
    }

    for (int i = 0; i < grid.size(); i++) {          // grid.size() = number of rows
        for (int j = 0; j < grid[i].size(); j++) {    // grid[i].size() = cols in that row
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}