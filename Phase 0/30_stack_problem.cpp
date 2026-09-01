#include <iostream>
using namespace std;

int* makePointerToStackVar() {
    int localVar = 42;   // this lives on the STACK, inside this function
    return &localVar;     // returning its address -- but localVar is about to be destroyed!
}

int main() {
    int* p = makePointerToStackVar();

    // localVar no longer exists -- the function already returned and its
    // stack memory was reclaimed. p is now a "dangling pointer" pointing
    // at memory that's no longer valid. Using *p here is undefined behavior.
    cout << "This might print garbage, or might crash: " << *p << endl;
    cout << "This is exactly why the heap exists -- for data that needs to " << endl;
    cout << "outlive the function that created it." << endl;

    return 0;
}