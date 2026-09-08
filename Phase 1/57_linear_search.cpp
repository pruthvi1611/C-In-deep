#include <iostream>
#include <vector>
using namespace std;

// Linear search: check every element, one by one, until found or exhausted.
// Works on ANY array -- sorted or not. O(n) time, O(1) space.
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> unsorted = {45, 12, 8, 91, 3, 67, 29};

    cout << "Searching unsorted array for 91: " << linearSearch(unsorted, 91) << endl;
    cout << "Searching unsorted array for 100: " << linearSearch(unsorted, 100) << endl;

    return 0;
}