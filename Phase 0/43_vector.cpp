#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Remember Topic 5's arrays -- fixed size, decided at compile time (mostly).
    // Remember Topic 7 -- new int[size] needs manual delete[], leak risk.
    // vector solves BOTH problems: it resizes automatically AND manages its
    // own memory -- no new/delete needed, ever.

    vector<int> nums;  // starts EMPTY, unlike int arr[5]

    nums.push_back(10);  // add to the end
    nums.push_back(20);
    nums.push_back(30);

    cout << "Size: " << nums.size() << endl;
    cout << "Elements: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";  // [] works just like a regular array
    }
    cout << endl;

    // Better traversal style: range-based for loop (cleaner, less error-prone)
    cout << "Using range-based for: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    nums.pop_back();  // remove last element
    cout << "After pop_back, size: " << nums.size() << endl;

    // Vector with an initial size and default value
    vector<int> zeros(5, 0);  // 5 elements, all initialized to 0
    cout << "zeros: ";
    for (int x : zeros) cout << x << " ";
    cout << endl;

    // Vector initialized directly with values, like an array literal
    vector<int> primes = {2, 3, 5, 7, 11};
    cout << "primes: ";
    for (int x : primes) cout << x << " ";
    cout << endl;

    // Checking if empty, accessing front/back
    cout << "\nfront: " << primes.front() << ", back: " << primes.back() << endl;
    cout << "is nums empty? " << nums.empty() << endl;

    // Clearing everything
    zeros.clear();
    cout << "After clear, zeros size: " << zeros.size() << endl;

    return 0;
}