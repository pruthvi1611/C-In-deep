#include <iostream>
using namespace std;

void leakyFunction() {
    int* p = new int(5);
    cout << "Inside function: p (the address) = " << p << endl;
    cout << "Inside function: *p (the value)   = " << *p << endl;
    // function ends here, no delete
    // p (the stack variable, the address-holder) is destroyed now
    // but the '5' on the heap at that address is still sitting there, unreachable
}

int main() {
    leakyFunction();
    cout << "\nBack in main: p doesn't even exist here -- it was local to the function." << endl;
    cout << "The heap memory holding '5' still exists somewhere, but we have" << endl;
    cout << "no address left to reach it. It's permanently leaked." << endl;
    return 0;
}