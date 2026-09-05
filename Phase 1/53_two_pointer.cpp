#include <iostream>
#include <vector>
using namespace std;

// Problem: given a SORTED array, find two numbers that add up to a target.
// (This is "Two Sum II" -- a variant of your earlier Two Sum, but sorted.)

// NAIVE way -- you already know this pattern from Topic "Two Sum": O(n^2)
pair<int,int> twoSumBruteForce(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == target) return {i, j};
        }
    }
    return {-1, -1};
}

// TWO-POINTER way -- O(n), and only works because the array is SORTED.
// One pointer starts at the beginning, one at the end. They move toward
// each other based on whether the current sum is too small or too big.
pair<int,int> twoSumTwoPointer(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == target) {
            return {left, right};
        } else if (currentSum < target) {
            // sum too small -- we need a BIGGER number.
            // Since the array is sorted, moving 'left' forward gets a bigger value.
            left++;
        } else {
            // sum too big -- we need a SMALLER number.
            // Moving 'right' backward gets a smaller value.
            right--;
        }
    }
    return {-1, -1};
}

int main() {
    vector<int> sortedArr = {2, 7, 11, 15, 18, 24};
    int target = 22;  // 7 + 15 = 22

    pair<int,int> result = twoSumTwoPointer(sortedArr, target);
    cout << "Two-pointer result: indices (" << result.first << ", " << result.second << ")" << endl;
    cout << "Values: " << sortedArr[result.first] << " + " << sortedArr[result.second]
         << " = " << target << endl;

    // Let's trace it step by step to make the movement visible
    cout << "\n--- Step by step trace ---\n";
    int left = 0, right = sortedArr.size() - 1;
    while (left < right) {
        int sum = sortedArr[left] + sortedArr[right];
        cout << "left=" << left << "(" << sortedArr[left] << ") right=" << right
             << "(" << sortedArr[right] << ") sum=" << sum;
        if (sum == target) { cout << " -- MATCH!" << endl; break; }
        else if (sum < target) { cout << " -- too small, left++" << endl; left++; }
        else { cout << " -- too big, right--" << endl; right--; }
    }

    return 0;
}