#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {4, 2, 7, 1, 9, 5};

    // Forward traversal -- Topic 5/10 review
    cout << "Forward: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Backward traversal
    cout << "Backward: ";
    for (int i = arr.size() - 1; i >= 0; i--) cout << arr[i] << " ";
    cout << endl;

    // Finding max/min in ONE pass -- O(n) time, O(1) space
    int maxVal = arr[0], minVal = arr[0];
    for (int x : arr) {
        if (x > maxVal) maxVal = x;
        if (x < minVal) minVal = x;
    }
    cout << "Max: " << maxVal << ", Min: " << minVal << endl;

    return 0;
}