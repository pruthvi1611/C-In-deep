#include <iostream>
#include <vector>
using namespace std;

// Problem: answer MANY range-sum queries efficiently -- "what's the sum of
// elements from index i to j?" -- without re-summing the range every time.

// Build a prefix sum array: prefix[i] = sum of all elements from 0 to i
vector<int> buildPrefixSum(vector<int>& arr) {
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];   // running total, built incrementally
    }
    return prefix;
}

// Once built, ANY range sum [left, right] can be answered in O(1):
// sum(left, right) = prefix[right] - prefix[left - 1]
// (special case: if left == 0, the answer is just prefix[right])
int rangeSum(vector<int>& prefix, int left, int right) {
    if (left == 0) return prefix[right];
    return prefix[right] - prefix[left - 1];
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};

    vector<int> prefix = buildPrefixSum(arr);

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << "\nPrefix:   ";
    for (int x : prefix) cout << x << " ";
    cout << endl;

    cout << "\nSum of arr[2..5] (should be 4+1+5+9=19): " << rangeSum(prefix, 2, 5) << endl;
    cout << "Sum of arr[0..2] (should be 3+1+4=8): " << rangeSum(prefix, 0, 2) << endl;
    cout << "Sum of arr[4..7] (should be 5+9+2+6=22): " << rangeSum(prefix, 4, 7) << endl;

    return 0;
}