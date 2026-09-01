#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // SET -- stores unique values, automatically sorted
    set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10);  // duplicate -- ignored, set only keeps unique values

    cout << "Set contents (auto-sorted, no duplicates): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    cout << "Is 20 in the set? " << (s.count(20) > 0) << endl;  // count() returns 0 or 1 for a set

    // MAP -- key-value pairs, automatically sorted by key
    map<string, int> ageMap;
    ageMap["Pruthvi"] = 21;
    ageMap["Aditi"] = 22;
    ageMap["Rahul"] = 20;

    cout << "\nMap contents:\n";
    for (pair<string, int> entry : ageMap) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    cout << "\nPruthvi's age: " << ageMap["Pruthvi"] << endl;

    // SORT -- works on vectors (and arrays) directly
    vector<int> nums = {5, 2, 8, 1, 9, 3};
    cout << "\nBefore sort: ";
    for (int x : nums) cout << x << " ";

    sort(nums.begin(), nums.end());  // ascending by default
    cout << "\nAfter sort (ascending): ";
    for (int x : nums) cout << x << " ";

    sort(nums.begin(), nums.end(), greater<int>());  // descending
    cout << "\nAfter sort (descending): ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}