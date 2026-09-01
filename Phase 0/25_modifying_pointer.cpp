#include <iostream>
using namespace std;

int main() {
    int score = 50;
    int* ptr = &score;

    cout << "Before: score = " << score << endl;

    *ptr = 100;  // "go to the address ptr holds, and set the value there to 100"

    cout << "After *ptr = 100: score = " << score << endl;
    // score itself changed! Because ptr points directly AT score's memory location.

    // You can also read through the pointer and do math
    *ptr = *ptr + 25;
    cout << "After *ptr += 25: score = " << score << endl;

    return 0;
}