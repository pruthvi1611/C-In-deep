#include <iostream>
#include <vector>
using namespace std;

// Problem: find the maximum sum of any CONTIGUOUS subarray of size k.
// e.g. arr = {2,1,5,1,3,2}, k=3 -> subarrays of size 3: {2,1,5}=8, {1,5,1}=7,
// {5,1,3}=9, {1,3,2}=6 -> answer is 9

// BRUTE FORCE -- recompute the sum from scratch for every window. O(n*k)
int maxSumBruteForce(vector<int>& arr, int k) {
    int maxSum = 0;
    for (int i = 0; i <= (int)arr.size() - k; i++) {
        int windowSum = 0;
        for (int j = i; j < i + k; j++) {   // re-sums all k elements every time
            windowSum += arr[j];
        }
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

// SLIDING WINDOW -- O(n). Compute the FIRST window's sum directly, then
// SLIDE by removing the element leaving the window and adding the new one.
// No need to re-sum everything from scratch each time.
int maxSumSlidingWindow(vector<int>& arr, int k) {
    int windowSum = 0;

    // Build the first window (first k elements)
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Slide the window forward one element at a time
    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i];        // add the new element entering the window
        windowSum -= arr[i - k];    // remove the old element leaving the window
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << "Brute force: " << maxSumBruteForce(arr, k) << endl;
    cout << "Sliding window: " << maxSumSlidingWindow(arr, k) << endl;

    cout << "\n--- Trace of the sliding window ---\n";
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];
    cout << "Initial window [0.." << k-1 << "] sum = " << windowSum << endl;

    int maxSum = windowSum;
    for (int i = k; i < arr.size(); i++) {
        cout << "Slide: add arr[" << i << "]=" << arr[i]
             << ", remove arr[" << i-k << "]=" << arr[i-k];
        windowSum += arr[i];
        windowSum -= arr[i - k];
        cout << " -> new sum = " << windowSum << endl;
        maxSum = max(maxSum, windowSum);
    }
    cout << "Max sum found: " << maxSum << endl;

    return 0;
}