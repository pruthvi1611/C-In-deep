#include <iostream>
using namespace std;

// FORWARD DECLARATION (a.k.a prototype) — tells the compiler "this function
// exists and looks like this," so you can call it in main() before its
// actual code appears further down the file.
int square(int n);

int main() {
    cout << "5 squared is " << square(5) << endl;
    return 0;
}

// The ACTUAL DEFINITION can come after main()
int square(int n) {
    return n * n;
}