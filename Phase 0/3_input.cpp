#include <iostream>
#include <string>
using namespace std;

int main() {
    int rollNumber;
    cout << "Enter roll number: ";
    cin >> rollNumber;

    string firstName;
    cout << "Enter first name: ";
    cin >> firstName;  // cin >> stops at whitespace, so it only reads ONE word

    cin.ignore();  // clears the leftover newline character sitting in the input buffer

    string fullLine;
    cout << "Enter a full sentence: ";
    getline(cin, fullLine);  // getline reads the WHOLE line, including spaces

    cout << "\n--- Summary ---\n";
    cout << "Roll: " << rollNumber << endl;
    cout << "First name: " << firstName << endl;
    cout << "Full line: " << fullLine << endl;

    return 0;
}