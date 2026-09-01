#include <iostream>
using namespace std;

int main() {
    // while is best when you DON'T know the exact number of iterations in advance
    int num = 12345;
    int digitCount = 0;

    while (num != 0) {
        num = num / 10;   // strip off the last digit each time
        digitCount++;
    }
    cout << "Digit count: " << digitCount << endl;

    // Another classic: sum of digits
    int number = 4567;
    int sum = 0;
    while (number != 0) {
        int lastDigit = number % 10;
        sum += lastDigit;
        number /= 10;
    }
    cout << "Sum of digits: " << sum << endl;

    return 0;
}