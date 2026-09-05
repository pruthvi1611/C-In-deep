#include <iostream>
#include <vector>
#include <chrono>   // for timing
using namespace std;
using namespace std::chrono;

// Approach 1: check if array has duplicates -- brute force, checks every pair
bool hasDuplicateSlow(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}

// Approach 2: same problem, using a set to remember what we've seen
bool hasDuplicateFast(vector<int>& arr) {
    vector<int> seen;  // we'll pretend this is a hash set conceptually for now
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < seen.size(); j++) {
            if (seen[j] == arr[i]) return true;
        }
        seen.push_back(arr[i]);
    }
    return false;
    // (this isn't actually faster as written -- true O(n) needs unordered_set,
    //  which is Topic 16. This is just to set up WHY we'll want that.)
}

int main() {
    // Build a large array with no duplicates (worst case -- checks everything)
    vector<int> bigArray;
    for (int i = 0; i < 20000; i++) bigArray.push_back(i);

    auto start = high_resolution_clock::now();
    hasDuplicateSlow(bigArray);
    auto end = high_resolution_clock::now();
    cout << "Brute force (O(n^2)) on 20,000 elements: "
         << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    cout << "\nThis is the entire point of Big-O: it predicts THIS kind of" << endl;
    cout << "slowdown before you ever have to run and time the code." << endl;

    return 0;
}