#include <iostream>
using namespace std;

void leakyFunction() {
    int* p = new int(10);  // allocate on heap
    // ... function does some work ...
    // BUG: we never call delete p; before the function ends!
    // p (the pointer variable) is on the stack and gets destroyed when the
    // function returns, but the memory it POINTED TO is still sitting there
    // on the heap, now with NOTHING pointing at it. It can never be freed
    // again. This is a MEMORY LEAK.
}

void correctFunction() {
    int* p = new int(10);
    // ... function does some work ...
    delete p;  // properly freed before the function ends
}

int main() {
    for (int i = 0; i < 1000; i++) {
        leakyFunction();  // each call leaks a small chunk of memory permanently
    }
    cout << "Called leakyFunction 1000 times -- 1000 ints worth of memory is now " << endl;
    cout << "leaked and unusable until the program exits. In a long-running " << endl;
    cout << "program (like a server), this eventually exhausts available memory." << endl;

    for (int i = 0; i < 1000; i++) {
        correctFunction();  // no leak -- each allocation is properly freed
    }
    cout << "\ncorrectFunction had no leaks -- every new was matched with a delete." << endl;

    return 0;
}