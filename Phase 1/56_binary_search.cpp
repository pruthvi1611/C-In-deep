#include <iostream>
#include <vector>
using namespace std;

// Binary search: find target in a SORTED array in O(log n) instead of O(n).
// Works by repeatedly cutting the search space in HALF.
int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // safer than (low+high)/2 -- avoids overflow on huge arrays

        if (arr[mid] == target) {
            return mid;  // found it
        } else if (arr[mid] < target) {
            low = mid + 1;   // target must be in the RIGHT half
        } else {
            high = mid - 1;  // target must be in the LEFT half
        }
    }
    return -1;  // not found
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int target = 23;

    cout << "Searching for " << target << " in a sorted array of size " << arr.size() << endl;
    cout << "\n--- Step by step trace ---\n";

    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "low=" << low << " high=" << high << " mid=" << mid
             << " arr[mid]=" << arr[mid];

        if (arr[mid] == target) {
            cout << " -- FOUND at index " << mid << endl;
            break;
        } else if (arr[mid] < target) {
            cout << " -- too small, search right half" << endl;
            low = mid + 1;
        } else {
            cout << " -- too big, search left half" << endl;
            high = mid - 1;
        }
    }

    cout << "\nResult: " << binarySearch(arr, target) << endl;
    cout << "Result for missing value (99): " << binarySearch(arr, 99) << endl;

    return 0;
}