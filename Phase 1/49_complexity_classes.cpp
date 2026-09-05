#include <iostream>
#include <vector>
using namespace std;

// O(1) -- CONSTANT time. Doesn't matter how big arr is, this always takes
// the same amount of work: one lookup, no loops.
int getFirst(vector<int>& arr) {
    return arr[0];
}

// O(log n) -- LOGARITHMIC. Each step cuts the remaining work roughly in half.
// (This is binary search -- full topic coming up next, just previewing the shape.)
bool binarySearchPreview(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// O(n) -- LINEAR. Work grows in direct proportion to input size.
// One pass through the array, no nesting.
int sumArray(vector<int>& arr) {
    int total = 0;
    for (int i = 0; i < arr.size(); i++) {
        total += arr[i];
    }
    return total;
}

// O(n log n) -- what most good sorting algorithms achieve (Topic 14).
// Not shown here directly -- just noting where it sits relative to the others.

// O(n^2) -- QUADRATIC. A loop inside a loop, both roughly the size of n.
// This is exactly your Two Sum brute force from before.
bool hasDuplicate(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}

// O(2^n) -- EXPONENTIAL. Each step doubles the work. Gets unusable FAST.
// Classic example: naive recursive Fibonacci (you'll write this in Topic 15).
int fibNaive(int n) {
    if (n <= 1) return n;
    return fibNaive(n - 1) + fibNaive(n - 2);  // two recursive calls per call
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "O(1)      getFirst: " << getFirst(arr) << endl;
    cout << "O(log n)  binarySearch(7): " << binarySearchPreview(arr, 7) << endl;
    cout << "O(n)      sumArray: " << sumArray(arr) << endl;
    cout << "O(n^2)    hasDuplicate: " << hasDuplicate(arr) << endl;
    cout << "O(2^n)    fibNaive(10): " << fibNaive(10) << endl;

    return 0;
}