#include <iostream>
#include <vector>
using namespace std;

int main() {
    // pair bundles TWO values together -- very common in DSA
    // (e.g. coordinates, a value with its index, a key with its count)

    pair<string, int> student = {"Pruthvi", 85};

    cout << "Name: " << student.first << ", Marks: " << student.second << endl;

    // Very common pattern: a vector of pairs
    vector<pair<string, int>> allStudents;
    allStudents.push_back({"Pruthvi", 85});
    allStudents.push_back({"Aditi", 92});
    allStudents.push_back({"Rahul", 78});

    cout << "\nAll students:\n";
    for (pair<string, int> s : allStudents) {
        cout << s.first << " -> " << s.second << endl;
    }

    // Pairs representing 2D coordinates -- common in grid/graph problems
    pair<int, int> point = {3, 5};
    cout << "\nPoint: (" << point.first << ", " << point.second << ")" << endl;

    return 0;
}