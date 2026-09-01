#include <iostream>
using namespace std;

void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Before swap: x=" << x << " y=" << y << endl;

    swapValues(x, y);

    cout << "After swap: x=" << x << " y=" << y << endl;

    return 0;
}