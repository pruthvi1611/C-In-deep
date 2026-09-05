#include <iostream>
#include <vector>
using namespace std;

// O(1) SPACE -- uses a fixed, small amount of extra memory, no matter how big arr is
int sumArrayConstantSpace(vector<int>& arr) {
    int total = 0;   // just one extra variable, regardless of arr's size
    for (int x : arr) total += x;
    return total;
}

// O(n) SPACE -- creates a NEW structure whose size grows with the input
vector<int> doubleEachElement(vector<int>& arr) {
    vector<int> result;              // this grows to size n
    for (int x : arr) {
        result.push_back(x * 2);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Sum (O(1) space): " << sumArrayConstantSpace(arr) << endl;

    vector<int> doubled = doubleEachElement(arr);
    cout << "Doubled (O(n) space): ";
    for (int x : doubled) cout << x << " ";
    cout << endl;

    cout << "\nNote: the INPUT array itself is never counted toward space" << endl;
    cout << "complexity -- we only count EXTRA memory the algorithm uses." << endl;

    return 0;
}