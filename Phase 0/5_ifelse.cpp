#include <iostream>
using namespace std;

int main() {
    int marks = 78;

    if (marks >= 90) {
        cout << "Grade: A+" << endl;
    } else if (marks >= 75) {
        cout << "Grade: A" << endl;
    } else if (marks >= 60) {
        cout << "Grade: B" << endl;
    } else {
        cout << "Grade: C" << endl;
    }

    // Conditions are checked top to bottom, and the FIRST true one wins.
    // Even though 78 >= 60 is also true, it never gets checked because
    // 78 >= 75 was already true and the chain stopped there.

    return 0;
}