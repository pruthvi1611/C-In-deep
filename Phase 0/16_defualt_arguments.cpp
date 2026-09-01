#include <iostream>
using namespace std;

// If caller doesn't provide 'tax', it defaults to 18 (percent)
double calculatePrice(double basePrice, double taxPercent = 18.0) {
    return basePrice + (basePrice * taxPercent / 100);
}

int main() {
    cout << "With default tax: " << calculatePrice(1000) << endl;
    cout << "With custom tax: " << calculatePrice(1000, 5) << endl;

    return 0;
}