#include <iostream>
#include <vector>
using namespace std;

// This does THREE separate O(n) passes -- looks like it should be "O(3n)"
void threePasses(vector<int>& arr) {
    int sum = 0;
    for (int x : arr) sum += x;              // pass 1

    int maxVal = arr[0];
    for (int x : arr) if (x > maxVal) maxVal = x;   // pass 2

    int minVal = arr[0];
    for (int x : arr) if (x < minVal) minVal = x;   // pass 3

    cout << "sum=" << sum << " max=" << maxVal << " min=" << minVal << endl;
}
// We call this O(n), not O(3n). Why? Because Big-O cares about the SHAPE of
// growth as n gets huge, not the exact operation count. Whether it's 1 pass
// or 3 passes, the runtime still scales LINEARLY with n -- double the input,
// (roughly) double the time, in both cases. The "3" is a constant factor
// that doesn't change the fundamental growth pattern, so we drop it.

// Compare that to genuinely different growth:
void onePassVsNested(vector<int>& arr) {
    // O(n): 1x the work as n grows
    int sum = 0;
    for (int x : arr) sum += x;

    // O(n^2): if n doubles, this doesn't just double -- it roughly QUADRUPLES
    int pairCount = 0;
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr.size(); j++)
            pairCount++;

    cout << "pairCount for n=" << arr.size() << ": " << pairCount << endl;
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 9};
    threePasses(arr);

    cout << "\n--- Showing WHY n^2 is fundamentally different from n ---\n";
    vector<int> small(10, 0);
    vector<int> doubled(20, 0);

    onePassVsNested(small);
    onePassVsNested(doubled);
    cout << "\nNotice: n doubled from 10 to 20, but pairCount didn't just" << endl;
    cout << "double -- it went from 100 to 400. That's the n^2 signature." << endl;

    return 0;
}